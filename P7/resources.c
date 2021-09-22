/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "corelib.h"
#include "patron.h"
#include "check.h"
#include "resources.h"

int import_resources_node(char const filename[], resource_node_type **head_node) {
    resource_node_type *current_node;
    FILE *input;
    char line[line_length_max];
    char chunks[ chunk_count_max ][ chunk_length_max];
    int count;
    
    count = 0;
    input = fopen(filename, "r");
    if (input == NULL ) {
        printf("Error: No valid filename!\n");
    } else {
        while (file_read_line(input, line) > 0) {
            if(string_split(line,',', chunks) == 6) {
                if( *head_node == NULL) {
                    *head_node = (resource_node_type *) malloc(sizeof(resource_node_type));
                    strcpy( (*head_node)->resource_id, chunks[0]);
                    strcpy( (*head_node)->resource_title, chunks[1]);
                    (*head_node)->resource_option = atoi(chunks[2]);
                    (*head_node)->resource_price = atof(chunks[3]);
                    (*head_node)->resource_date, chunks[4];
                    (*head_node)->resource_status = atoi(chunks[5]);
                    (*head_node)->next_resource = NULL;
                    current_node = *head_node;
                    printf("Note: Added head_node!\n");


                } else {
                    current_node->next_resource = (resource_node_type *) malloc(sizeof(resource_node_type));
                    current_node = current_node->next_resource;
                    strcpy( (*head_node)->resource_id, chunks[0]);
                    strcpy( (*head_node)->resource_title, chunks[1]);
                    (*head_node)->resource_option = atoi(chunks[2]);
                    (*head_node)->resource_price = atof(chunks[3]);
                    strcpy( (*head_node)->resource_date, chunks[4]);
                    (*head_node)->resource_status = atoi(chunks[5]);
                    current_node->next_resource = NULL;
                    printf("Note: Added new_node!\n");
                    
                }
                count++;
            } else {
                printf("Note: malformed line!\n");
            }
        }
        display_resources_node(*head_node);
        return(count);
    }
    
    return(0);
}
int display_resources_node(resource_node_type *head_node) {
    resource_node_type *current_node;
    
    current_node = head_node;
    
    while(current_node != NULL) {
        display_resource_node(current_node );
        current_node = current_node->next_resource;
    }
}
int examine_resource_node(resource_node_type *head_node ) {
    
}
int display_resource_node(resource_node_type *resource_node ) {
    printf("resource_id:                  %s\n", resource_node->resource_id);
    printf("resource_title:               %s\n", resource_node->resource_title);
    printf("resource_option:              %s\n", resource_node->resource_option);
    printf("resource_price:               %lf\n", resource_node->resource_price);
    printf("resource_date:                %s\n", resource_node->resource_date);
    printf("resource_status:              %s\n", resource_node->resource_status);

}
int export_resources_node(char const filename[], resource_node_type *head_node) {
    FILE *output;
    resource_node_type *current_node;
    
    current_node = head_node;
    
    output = fopen(filename, "w");
    if (output = NULL) {
        printf("Error: Can not open file.\n");
    } else {
        while( current_node != NULL ) {
            fprintf(output,"resource_id:        %s\n", current_node->resource_id);
            fprintf(output,"resource_title:     %s\n", current_node->resource_title);
            fprintf(output,"resource_option:    %s\n", current_node->resource_option);
            fprintf(output,"resource_price:     %lf\n",current_node->resource_price);
            fprintf(output,"resource_date:      %s\n", current_node->resource_date);
            fprintf(output,"resource_status:    %s\n", current_node->resource_status);
            current_node = current_node->next_resource;
        }
    }
}

int add_resource_node(resource_node_type **head_node,  resource_node_type *resource_node) {
    resource_node_type *current_node;
    char chunks[ chunk_count_max][chunk_length_max];
    
    if(head_node == NULL) {
        *head_node = (resource_node_type *) malloc(sizeof(resource_node_type));
        strcpy((*head_node)->resource_id, chunks[ 0 ]);
        strcpy((*head_node)->resource_title, chunks[ 1 ]);
        resource_node->resource_option = atoi (chunks[2]);
        (*head_node)->resource_price =  atof(chunks[3]);
        strcpy((*head_node)->resource_date, chunks[4]);
        resource_node->resource_status = atoi(chunks[5]);
        (*head_node)->next_resource = NULL;
        current_node = *head_node;
        printf("Note: Added head node!\n");
    } else {
        current_node->next_resource = (resource_node_type *) malloc(sizeof( resource_node_type));
        current_node = current_node->next_resource;
         *head_node = (resource_node_type *) malloc(sizeof(resource_node_type));
         
        strcpy((*head_node)->resource_id, chunks[ 0 ]);
        strcpy((*head_node)->resource_title, chunks[ 1 ]);
        resource_node->resource_option = atoi (chunks[2]);
        (*head_node)->resource_price = atof(chunks[3]);
        strcpy((*head_node)->resource_date, chunks[4]);
        resource_node->resource_status = atoi(chunks[5]);
        current_node->next_resource = NULL;
        printf("Note: Added new node!\n");
        
    }
}
int remove_resource_node(resource_node_type **head_node, resource_node_type *resource_node) {
    resource_node_type *current_node;
    current_node = *head_node;
    int match = 0;
    
    while (match = 0) {
        if(compare_resource_node(current_node, resource_node) == 1) {
            current_node->resource_status = resource_inactive;
            match = 1;
        } else if (current_node->next_resource == NULL) {
            printf("Error: No match found\n");
            return(match);
        } else {
            // keep looking...
        }
    }
    return(match);
}

int isa_resource_all_fields_list(resource_node_type *head_node, resource_node_type *resource_node);
int isa_resource_node(resource_node_type *head_node, char resource_id[]);

int get_resource_all_fields_list(resource_node_type *head_node, resource_node_type *resource_node);

int get_resource_node(resource_node_type *head_node, char resource_id[], resource_node_type *resource_node) {
    resource_node_type *current_node;
    current_node = head_node;
    
    int found = 0;
    while((current_node != NULL) && (found == 0)) {
        if(string_compare(current_node->resource_id, resource_id, case_insensitive) == 0) {
            copy_resource_node(resource_node, current_node);
            found = 1;
        } else {
            // keep looking...
            current_node = current_node->next_resource;
        }
    }
}

int compare_resource_node(resource_node_type *first_resource_node, resource_node_type *second_resource_node) {
    int match;
    match = 0;
    
    /*
    resource_node_type *current_node;
    
    
    
    if ((string_compare ([first_resource_node->resource_id],[second_resource_node->resource_id] ) == 0) && (string_compare ([first_resource_node->resource_title],[second_resource_node->resource_title] ) == 0)
          && (string_compare ([first_resource_node->resource_option],[second_resource_node->resource_option] ) == 0) && (string_compare ([first_resource_node->resource_price],[second_resource_node->resource_price] ) == 0)
          && (string_compare ([first_resource_node->resource_date],[second_resource_node->resource_date] ) == 0) && (string_compare ([first_resource_node->resource_status],[second_resource_node->resource_status] ) == 0)) {
                printf("Match found\n");
                match = 1;
    } else {
        printf("No match\n");
    }
*/
    
    if ((string_compare (first_resource_node->resource_id, second_resource_node->resource_id) == 0) &&
        (string_compare (first_resource_node->resource_title, second_resource_node->resource_title) == 0) &&
        (first_resource_node->resource_option == second_resource_node->resource_option) &&
        (first_resource_node->resource_price == second_resource_node->resource_price) &&
        (string_compare (first_resource_node->resource_date, second_resource_node->resource_date) == 0) ) {
        printf("Match Found\n");
        match = 1;
    } else {
        printf("No match found\n");
        match = 0;
    }
            
            
            
            
    return(match);
}
int copy_resource_node(resource_node_type *destination_node, resource_node_type *source_node) {
    strcpy( destination_node->resource_id, source_node->resource_id);
    strcpy( destination_node->resource_title, source_node->resource_title);
    destination_node->resource_option = source_node->resource_option;
    destination_node->resource_price = source_node->resource_price;
    strcpy( destination_node->resource_date, source_node->resource_date);
    destination_node->resource_status = source_node->resource_status;
    destination_node->next_resource = NULL;
}

int sort_resource_node(resource_node_type *head_node, resource_field_enum field_name, order_type order) {
/*
    typedef enum
    { resource_id, resource_option }
resource_field_enum;

typedef enum 
    { book, journal, audio_video, electronic, archive }
resource_option_enum;
*/

    resource_node_type *current_node;
    resource_node_type *temp_node;
    
    int done = 0;
    
    if (*head_node == NULL) {
        
    } else if (*head_node->next_resource == NULL) {
        
    } else {
        if (field_name == resource_field_enum->resource_id) {
            if (order == ascending) {
                current_node = *head_node;
                while(done == 0) {
                    done = 1;
                    while ( current_node->next_resource != NULL) {
                        if(string_compare(current_node->resource_id, current_node->next_resource, case_insensitive) > 0 ) {
                            copy_patron_node(temp_node, current_node);
                            copy_patron_node(current_node, current_node->next_resource);
                            copy_patron_node(current_node->next_resource, temp_node);
                            done == 0;
                        } else {
                            // keep looking...
                        }
                    }
                    current_node = current_node->next_resource; // increment the node pointer
                }
            } else if ( order == descending) {
                current_node = *head_node;
                while(done == 0) {
                    done = 1;
                    while ( current_node->next_resource != NULL) {
                        if(string_compare(current_node->resource_id, current_node->next_resource, case_insensitive) < 0 ) {
                            copy_patron_node(temp_node, current_node);
                            copy_patron_node(current_node, current_node->next_resource);
                            copy_patron_node(current_node->next_resource, temp_node);
                            done == 0;
                        } else {
                            // keep looking...
                        }
                    }
                    current_node = current_node->next_resource; // increment the node pointer
                }
            } else {
                // invalid order
            }
        } else if (field_name == resource_field_enum->resource_option) {
            if( resource_field_enum->resource_option == book) {
               if (order == ascending) {
                 current_node = *head_node;
                 while(done == 0) {
                    done = 1;
                    while ( current_node->next_resource != NULL) {
                        if(string_compare(current_node->resource_option, current_node->next_resource, case_insensitive) > 0 ) {
                            copy_patron_node(temp_node, current_node);
                            copy_patron_node(current_node, current_node->next_resource);
                            copy_patron_node(current_node->next_resource, temp_node);
                            done == 0;
                        } else {
                            // keep looking...
                        }
                    }
                    current_node = current_node->next_resource; // increment the node pointer
                }
            } else if ( order == descending) {
                 current_node = *head_node;
                 while(done == 0) {
                    done = 1;
                    while ( current_node->next_resource != NULL) {
                        if(string_compare(current_node->resource_option, current_node->next_resource, case_insensitive) < 0 ) {
                            copy_patron_node(temp_node, current_node);
                            copy_patron_node(current_node, current_node->next_resource);
                            copy_patron_node(current_node->next_resource, temp_node);
                            done == 0;
                        } else {
                            // keep looking...
                        }
                    }
                    current_node = current_node->next_resource; // increment the node pointer
                }
            } else {
                // invalid order
            } 
            } else if ( resource_field_enum->resource_option == journal) {
                if (order == ascending) {
                 current_node = *head_node;
                 while(done == 0) {
                    done = 1;
                    while ( current_node->next_resource != NULL) {
                        if(string_compare(current_node->resource_option, current_node->next_resource, case_insensitive) > 0 ) {
                            copy_patron_node(temp_node, current_node);
                            copy_patron_node(current_node, current_node->next_resource);
                            copy_patron_node(current_node->next_resource, temp_node);
                            done == 0;
                        } else {
                            // keep looking...
                        }
                    }
                    current_node = current_node->next_resource; // increment the node pointer
                }
            } else if ( order == descending) {
                 current_node = *head_node;
                 while(done == 0) {
                    done = 1;
                    while ( current_node->next_resource != NULL) {
                        if(string_compare(current_node->resource_option, current_node->next_resource, case_insensitive) < 0 ) {
                            copy_patron_node(temp_node, current_node);
                            copy_patron_node(current_node, current_node->next_resource);
                            copy_patron_node(current_node->next_resource, temp_node);
                            done == 0;
                        } else {
                            // keep looking...
                        }
                    }
                    current_node = current_node->next_resource; // increment the node pointer
                }
            } else {
                // invalid order
            }
            } else if ( resource_field_enum->resource_option == audio_video) {
                if (order == ascending) {
                  current_node = *head_node;
                 while(done == 0) {
                    done = 1;
                    while ( current_node->next_resource != NULL) {
                        if(string_compare(current_node->resource_option, current_node->next_resource, case_insensitive) > 0 ) {
                            copy_patron_node(temp_node, current_node);
                            copy_patron_node(current_node, current_node->next_resource);
                            copy_patron_node(current_node->next_resource, temp_node);
                            done == 0;
                        } else {
                            // keep looking...
                        }
                    }
                    current_node = current_node->next_resource; // increment the node pointer
                }
            } else if ( order == descending) {
                 current_node = *head_node;
                 while(done == 0) {
                    done = 1;
                    while ( current_node->next_resource != NULL) {
                        if(string_compare(current_node->resource_option, current_node->next_resource, case_insensitive) > 0 ) {
                            copy_patron_node(temp_node, current_node);
                            copy_patron_node(current_node, current_node->next_resource);
                            copy_patron_node(current_node->next_resource, temp_node);
                            done == 0;
                        } else {
                            // keep looking...
                        }
                    }
                    current_node = current_node->next_resource; // increment the node pointer
                }
            } else {
                // invalid order
            }
            } else if ( resource_field_enum->resource_option == electronic) {
                if (order == ascending) {
                 current_node = *head_node;
                 while(done == 0) {
                    done = 1;
                    while ( current_node->next_resource != NULL) {
                        if(string_compare(current_node->resource_option, current_node->next_resource, case_insensitive) > 0 ) {
                            copy_patron_node(temp_node, current_node);
                            copy_patron_node(current_node, current_node->next_resource);
                            copy_patron_node(current_node->next_resource, temp_node);
                            done == 0;
                        } else {
                            // keep looking...
                        }
                    }
                    current_node = current_node->next_resource; // increment the node pointer
                }
            } else if ( order == descending) {
                 current_node = *head_node;
                 while(done == 0) {
                    done = 1;
                    while ( current_node->next_resource != NULL) {
                        if(string_compare(current_node->resource_option, current_node->next_resource, case_insensitive) < 0 ) {
                            copy_patron_node(temp_node, current_node);
                            copy_patron_node(current_node, current_node->next_resource);
                            copy_patron_node(current_node->next_resource, temp_node);
                            done == 0;
                        } else {
                            // keep looking...
                        }
                    }
                    current_node = current_node->next_resource; // increment the node pointer
                }
            } else {
                // invalid order
            }
            } else if ( resource_field_enum->resource_option == archive) {
                if (order == ascending) {
                 current_node = *head_node;
                 while(done == 0) {
                    done = 1;
                    while ( current_node->next_resource != NULL) {
                        if(string_compare(current_node->resource_option, current_node->next_resource, case_insensitive) > 0 ) {
                            copy_patron_node(temp_node, current_node);
                            copy_patron_node(current_node, current_node->next_resource);
                            copy_patron_node(current_node->next_resource, temp_node);
                            done == 0;
                        } else {
                            // keep looking...
                        }
                    }
                    current_node = current_node->next_resource; // increment the node pointer
                }
            } else if ( order == descending) {
                 current_node = *head_node;
                 while(done == 0) {
                    done = 1;
                    while ( current_node->next_resource != NULL) {
                        if(string_compare(current_node->resource_option, current_node->next_resource, case_insensitive) < 0 ) {
                            copy_patron_node(temp_node, current_node);
                            copy_patron_node(current_node, current_node->next_resource);
                            copy_patron_node(current_node->next_resource, temp_node);
                            done == 0;
                        } else {
                            // keep looking...
                        }
                    }
                    current_node = current_node->next_resource; // increment the node pointer
                }
            } else {
                // invalid order
            }
            } else {
                // no valid resource option.
            }
        } else {
            // no valid resource_field_enum;
        }
    }
}