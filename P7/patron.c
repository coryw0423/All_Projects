/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "corelib.h"
#include "patron.h"
#include "check.h"

int import_patrons_node(char const filename[], patron_node_type **head_node) {
    patron_node_type *current_node;
    FILE *input;
    char line[line_length_max];
    char chunks[ chunk_count_max][ chunk_length_max];
    int count;
    
    count = 0;
    input = fopen( filename, "r");
    if (input == NULL) {
        printf("Error: No valid filename!\n");
    } else {                
/*
        if (*head_node != NULL) {
            printf("Note: need to destroy the existing linked list!\n");               
            current_node = *head_node;
        }
*/
        while (file_read_line( input, line ) > 0) {
            if (string_split( line, ',', chunks) == 8) {
                if (*head_node == NULL) {
                    *head_node = (patron_node_type *) malloc( sizeof( patron_node_type));
                    strcpy( (*head_node)->patron_id, chunks[ 0 ]);
                    strcpy( (*head_node)->patron_first_name, chunks[ 1 ]);
                    strcpy( (*head_node)->patron_last_name, chunks[ 2 ]);
                    strcpy( (*head_node)->patron_address, chunks[ 3 ]);
                    strcpy( (*head_node)->patron_city, chunks[ 4 ]);
                    strcpy( (*head_node)->patron_state, chunks[ 5 ]);
                    strcpy( (*head_node)->patron_zip, chunks[ 6 ]);
                    (*head_node)->patron_status = atoi( chunks[ 7 ]);
                    (*head_node)->next_patron = NULL;
                    current_node = *head_node;
                    printf("Note: Added head_node!\n");
                } else {
                    current_node->next_patron = (patron_node_type *) malloc( sizeof( patron_node_type));
                    current_node = current_node->next_patron;
                    
                    strcpy( (*head_node)->patron_id, chunks[ 0 ]);
                    strcpy( (*head_node)->patron_first_name, chunks[ 1 ]);
                    strcpy( (*head_node)->patron_last_name, chunks[ 2 ]);
                    strcpy( (*head_node)->patron_address, chunks[ 3 ]);
                    strcpy( (*head_node)->patron_city, chunks[ 4 ]);
                    strcpy( (*head_node)->patron_state, chunks[ 5 ]);
                    strcpy( (*head_node)->patron_zip, chunks[ 6 ]);
                    (*head_node)->patron_status =  atoi(chunks[ 7 ]);
                    current_node->next_patron = NULL;
                    printf("Note: Added new_node!\n");
                }
                count++;
            } else {
                printf("Note: malformed line!\n");
            }
        }
        display_patrons_node(*head_node);
        return( count );
    }
    
    
    
/*
    if (*head_node == NULL) {
        printf("Note: Need to create a head_node!\n");
        
    } else {
        printf("Note: head_node already exists!\n");
    }
*/
    
    return( 0 );

}
int display_patrons_node(patron_node_type *head_node) {
    patron_node_type *current_node;
    
    current_node = head_node;
    
    while( current_node != NULL ) {
        display_patron_node( current_node );
        current_node = current_node->next_patron;
        
    }
}
int examine_patron_node(patron_node_type *head_node ); // more info than the display functions


int display_patron_node(patron_node_type *patron_node ) {
    printf("patron_id:                  %s\n", patron_node->patron_id);
    printf("patron_first_name:          %s\n", patron_node->patron_first_name);
    printf("patron_last_name:           %s\n", patron_node->patron_last_name);
    printf("patron_address:             %s\n", patron_node->patron_address);
    printf("patron_city                 %s\n", patron_node->patron_city);
    printf("patron_state                %s\n", patron_node->patron_state);
    printf("patron_zip                  %s\n", patron_node->patron_zip);
    printf("patron_status               %d\n", patron_node->patron_status);
}
int export_patrons_node(char const filename[], patron_node_type *head_node) {
    FILE *output;
    patron_node_type *current_node;
    
    current_node = head_node;
    
    output = fopen(filename, "w");
    if (output == NULL) {
        printf("Error: Can not open file.\n");
    } else {
        while ( current_node != NULL ) {
        fprintf(output,"patron_id:                  %s\n", current_node->patron_id);
        fprintf(output,"patron_first_name:          %s\n", current_node->patron_first_name);
        fprintf(output,"patron_last_name:           %s\n", current_node->patron_last_name);
        fprintf(output,"patron_address:             %s\n", current_node->patron_address);
        fprintf(output,"patron_city                 %s\n", current_node->patron_city);
        fprintf(output,"patron_state                %s\n", current_node->patron_state);
        fprintf(output,"patron_zip                  %s\n", current_node->patron_zip);
        fprintf(output,"patron_status               %d\n", current_node->patron_status);
        current_node = current_node->next_patron;
        }
    }
}

int add_patron_node(patron_node_type **head_node,  patron_node_type *patron_node) {
    patron_node_type *current_node;
    char chunks[ chunk_count_max][ chunk_length_max];
    
    
    if ( head_node == NULL ) {
        *head_node = (patron_node_type *) malloc( sizeof( patron_node_type));
         strcpy( (*head_node)->patron_id, chunks[ 0 ]);
         strcpy( (*head_node)->patron_first_name, chunks[ 1 ]);
         strcpy( (*head_node)->patron_last_name, chunks[ 2 ]);
         strcpy( (*head_node)->patron_address, chunks[ 3 ]);
         strcpy( (*head_node)->patron_city, chunks[ 4 ]);
         strcpy( (*head_node)->patron_state, chunks[ 5 ]);
         strcpy( (*head_node)->patron_zip, chunks[ 6 ]);
        (*head_node)->patron_status = atoi( chunks[ 7 ]);
        (*head_node)->next_patron = NULL;
        current_node = *head_node;
        printf("Note: Added head_node!\n");
    } else {
         current_node->next_patron = (patron_node_type *) malloc( sizeof( patron_node_type));
         current_node = current_node->next_patron;
         
         strcpy( (*head_node)->patron_id, chunks[ 0 ]);
         strcpy( (*head_node)->patron_first_name, chunks[ 1 ]);
         strcpy( (*head_node)->patron_last_name, chunks[ 2 ]);
         strcpy( (*head_node)->patron_address, chunks[ 3 ]);
         strcpy( (*head_node)->patron_city, chunks[ 4 ]);
         strcpy( (*head_node)->patron_state, chunks[ 5 ]);
         strcpy( (*head_node)->patron_zip, chunks[ 6 ]);
         (*head_node)->patron_status =  atoi(chunks[ 7 ]);
         current_node->next_patron = NULL;
         printf("Note: Added new_node!\n");
    }
}
int remove_patron_node(patron_node_type **head_node, patron_node_type *patron_node) {
    patron_node_type *current_node;
    current_node = *head_node;
    // changing pointers
    
    int match = 0;
    
    while (match = 0) {
        if (compare_patron_node(current_node, patron_node) == 1) {
            current_node->patron_status = patron_inactive;
            match = 1;
        } else if (current_node->next_patron == NULL) {
            return(match);
        } else {
            // keep looking....
        }
    }
    return( match );
}

int isa_patron_all_fields_list(patron_node_type *head_node, patron_node_type *patron_node);
// create a new patron node and compares to ensure its unique
int isa_patron_node(patron_node_type *head_node, char patron_id[]);
// makes sure all unique patron id's 
// searches for a match of two patron ids
int get_patron_all_fields_list(patron_node_type *head_node, patron_node_type *patron_node) {
    patron_node_type *current_node;
    int found;
    current_node = head_node;
}
// return the count true or false 
// true 
int get_patron_node(patron_node_type *head_node, char patron_id[], patron_node_type *patron_node) {
    patron_node_type *current_node;
    current_node = head_node;
/*
    if (string_compare (patron_id, current_node->patron_id) == 0) {
        //patron node found
        // pop the fields and put the info in the given patron_node byref
        *patron_node = current_node->patron_id;
        strcpy( patron_node->patron_id, current_node->patron_id );
        strcpy( patron_node->patron_first_name, current_node->patron_first_name);
        strcpy( patron_node->patron_last_name, current_node->patron_last_name);
        strcpy( patron_node->patron_address, current_node->patron_address);
        strcpy( patron_node->patron_city, current_node->patron_city);
        strcpy( patron_node->patron_state, current_node->patron_state);
        strcpy( patron_node->patron_zip, current_node->patron_zip);
        patron_node->patron_status = current_node->patron_status;
    } else if((string_compare(patron_id, current_node->patron_id) != 0) && (string_compare(patron_id, current_node->next_patron) != NULL)) {
       
                current_node = current_node->next_patron;
        
    } else {
        printf("Error: No match found\n");
    }
*/
    int found = 0;
    while ((current_node != NULL) && (found == 0)) {
        if(string_compare(current_node->patron_id, patron_id, case_insensitive) == 0) {
            copy_patron_node( patron_node, current_node);
            found = 1;
        } else {
            // keep looking...
            current_node = current_node->next_patron;
        }
    }
    return( found );
}

int compare_patron_node(patron_node_type *first_patron_node, patron_node_type *second_patron_node) {
    patron_node_type *current_node;
    int match;
    match = 0;
    
    if ((string_compare (first_patron_node->patron_id, second_patron_node->patron_id, case_insensitive) == 0) &&
       (string_compare (first_patron_node->patron_first_name, second_patron_node->patron_first_name, case_insensitive) == 0) &&
       (string_compare (first_patron_node->patron_last_name, second_patron_node->patron_last_name, case_insensitive) == 0) &&
       (string_compare (first_patron_node->patron_address, second_patron_node->patron_address, case_insensitive) == 0) &&
       (string_compare (first_patron_node->patron_city, second_patron_node->patron_city, case_insensitive) == 0) &&
       (string_compare (first_patron_node->patron_state, second_patron_node->patron_state, case_insensitive) == 0) &&
       (string_compare (first_patron_node->patron_zip, second_patron_node->patron_zip, case_insensitive) == 0)) {
    
        printf("Match found\n");
        match = 1;
    } else {
        printf("No match\n");
    }
    return(match);
}
int copy_patron_node(patron_node_type *destination_node, patron_node_type *source_node) {
    strcpy( destination_node->patron_id, source_node->patron_id);
    strcpy( destination_node->patron_first_name, source_node->patron_first_name);
    strcpy( destination_node->patron_last_name, source_node->patron_last_name);
    strcpy( destination_node->patron_address, source_node->patron_address);
    strcpy( destination_node->patron_city, source_node->patron_city);
    strcpy( destination_node->patron_state, source_node->patron_state);
    strcpy( destination_node->patron_zip, source_node->patron_zip);
    destination_node->patron_status = source_node->patron_status;
    destination_node->next_patron = NULL;
}

int sort_patron_node(patron_node_type *head_node, patron_field_enum field_name, order_type order) {
    patron_node_type *current_node;
    patron_node_type *temp_node;
    //patron_node_type *min_patron_node;
    int done = 0;
    
    //previous_node == NULL;
    
    if(*head_node == NULL) {
        
    } else if (*head_node->next_patron == NULL) {
        
    } else {
        if (field_name == patron_field_enum->patron_id) {
            if (order == ascending) {
                current_node = *head_node;
                while(done == 0) {
                    done = 1;
                    while ( current_node->next_patron != NULL) {
                        if(string_compare(current_node->patron_id, current_node->next_patron, case_insensitive) > 0 ) {
                            copy_patron_node(temp_node, current_node);
                            copy_patron_node(current_node, current_node->next_patron);
                            copy_patron_node(current_node->next_patron, temp_node);
                            done == 0;
                        } else {
                            // keep looking...
                        }
                    }
                    current_node = current_node->next_patron; // increment the node pointer
                }
            } else if (order == descending) {
                current_node = *head_node;
                while(done == 0) {
                    done = 1;
                    while ( current_node->next_patron != NULL) {
                        if(string_compare(current_node->patron_id, current_node->next_patron, case_insensitive) < 0 ) {
                            copy_patron_node(temp_node, current_node);
                            copy_patron_node(current_node, current_node->next_patron);
                            copy_patron_node(current_node->next_patron, temp_node);
                            done == 0;
                        } else {
                            // keep looking...
                        }
                    }
                    current_node = current_node->next_patron; // increment the node pointer
                }
            } else {
                // not handled order
            } 
            } else if (field_name == patron_field_enum->patron_last_name) {
                if (order == ascending) {
                    current_node = *head_node;
                while(done == 0) {
                    done = 1;
                    while ( current_node->next_patron != NULL) {
                        if(string_compare(current_node->patron_last_name, current_node->next_patron, case_insensitive) > 0 ) {
                            copy_patron_node(temp_node, current_node);
                            copy_patron_node(current_node, current_node->next_patron);
                            copy_patron_node(current_node->next_patron, temp_node);
                            done == 0;
                        } else {
                            // keep looking...
                        }
                    }
                    current_node = current_node->next_patron; // increment the node pointer
                }
                } else if (order == descending) {
                    current_node = *head_node;
                while(done == 0) {
                    done = 1;
                    while ( current_node->next_patron != NULL) {
                        if(string_compare(current_node->patron_last_name, current_node->next_patron, case_insensitive) > 0 ) {
                            copy_patron_node(temp_node, current_node);
                            copy_patron_node(current_node, current_node->next_patron);
                            copy_patron_node(current_node->next_patron, temp_node);
                            done == 0;
                        } else {
                            // keep looking...
                        }
                    }
                    current_node = current_node->next_patron; // increment the node pointer
                }
                } else {
                    
                }
        } else {
                // unhandled field_name...
        }
    }
    
/*
    current_node = head_node;
    copy_patron_node(min_patron_node, current_node);
    current_node = current_node->next_patron;
*/
    
/*
    while(current_node->next_patron != NULL) {
        if (field_name == patron_id) {
            if (order == ascending) {
                printf("Sort by patron_id(ascending)\n");
                    current_node = head_node;
                    copy_patron_node(min_patron_node, current_node);
                    current_node = current_node->next_patron;
                    if (current_node->patron_id < min_patron_node->patron_id) {
                        // new low
                        copy_patron_node(min_patron_node, current_node);
                        current_node = current_node->next_patron;
                    }
            } else if ( order == descending) {
                printf("Sort by patron_id(descending)\n");
            } else {
                printf("Error no order_type passed.\n");
            }
        } else if ( field_name == patron_last_name) {
             if (order == ascending) {
                printf("Sort by patron_last_name(ascending)\n");
            } else if ( order == descending) {
                printf("Sort by patron_last_name(descending)\n");
            } else {
                printf("Error no order_type passed.\n");
            }
        } else {
            printf("Error no field_name passed.\n");
        }
    }
*/
    
    
/*
    if (field_name == patron_id) {
        if (order == ascending) {
            printf("Sort by patron_id(ascending)\n");
            copy_patron_node(min_patron_node, current_node);
            current_node = head_node->next_patron;
            if(current_node->patron_id < min_patron_node->patron_id) {
                // found a new min patron id
                copy_patron_node(min_patron_node, current_node);
            } else {
                // keep looking....
                current_node = current_node->next_patron;
            }
        } else if (order == descending) {
            printf("Sort by patron_id(descending)\n");
        } else {
            // do nothing
        }
    } else if (field_name == patron_last_name) {
        if (order == ascending) {
            printf("Sort by patron_last_name(ascending)\n");
        } else if (order == descending) {
            printf("Sort by patron_last_name(descending)\n");
        } else {
            // do nothing
        }
    } else {
        // do nothing
    }
*/
    
    
    return (done);
}

int patron_structure_builder( char patron_id[], char first_name[], char last_name[], char address[], char city[], char state[], char zip[]) {
    patron_node_type *current_node;
    
    strcpy(current_node->patron_id, patron_id);
     strcpy(current_node->patron_first_name, first_name);
      strcpy(current_node->patron_last_name, last_name);
       strcpy(current_node->patron_address, address);
        strcpy(current_node->patron_city, city);
         strcpy(current_node->patron_state, state);
          strcpy(current_node->patron_zip, zip);
          current_node->patron_status = patron_active;
          
          add_patron_node(NULL, current_node);
          
          
          
          return(EXIT_SUCCESS);
             
    
    
    
}