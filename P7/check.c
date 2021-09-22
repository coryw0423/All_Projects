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

int import_checks_node(char const filename[], check_node_type **head_node) {
    check_node_type *current_node;
    FILE *input;
    char line[line_length_max];
    char chunks[chunk_count_max][chunk_length_max];
    int count;
    
    count = 0;
    input = fopen(filename, "r");
    if(input == NULL) {
        printf("Error: No valid filename!\n");
    } else {
        while (file_read_line(input, line) > 0 ) {
            if (string_split(line, ',', chunks) == 5) {
                if (*head_node == NULL) {
                    *head_node = (check_node_type *) malloc(sizeof(check_node_type));
                    strcpy( (*head_node)->resource_id, chunks[0]);
                    strcpy( (*head_node)->patron_id, chunks[1]);
                    strcpy( (*head_node)->checkout_date, chunks[2]);
                    strcpy( (*head_node)->due_date, chunks[3]);
                    strcpy( (*head_node)->checkin_date, chunks[4]);
                    (*head_node)->next_check = NULL;
                    current_node = *head_node;
                    printf("Note: Added head_node\n");
                } else {
                    current_node->next_check = (check_node_type *) malloc(sizeof(check_node_type));
                    current_node = current_node->next_check;
                    strcpy( (*head_node)->resource_id, chunks[0]);
                    strcpy( (*head_node)->patron_id, chunks[1]);
                    strcpy( (*head_node)->checkout_date, chunks[2]);
                    strcpy( (*head_node)->due_date, chunks[3]);
                    strcpy( (*head_node)->checkin_date, chunks[4]);
                    current_node->next_check = NULL;
                    printf("Note: Added new node!\n");
                    
                }
                count++;
            } else {
                printf("Note: malformed line!\n");
            }
        }
        display_checks_node(*head_node);
        return(count);
    }
}
int display_checks_node(check_node_type *head_node) {
    check_node_type *current_node;
    
    while( current_node != NULL) {
        display_check_node(current_node);
        current_node = current_node->next_check;
    }
}
int examine_check_node(check_node_type *head_node );

int display_check_node(check_node_type *check_node ) {
    printf("resource_id:            %s\n", check_node->resource_id);
    printf("patron_id:            %s\n", check_node->patron_id);
    printf("checkout_date:            %s\n", check_node->checkout_date);
    printf("due_date:            %s\n", check_node->due_date);
    printf("checkin_date:            %s\n", check_node->checkin_date);
}
int export_checks_node(char const filename[], check_node_type *head_node) {
    FILE *output;
    check_node_type *current_node;
    
    current_node = head_node;
    
    output = fopen(filename, "w");
    if (output == NULL) {
        printf("Error: can not open file\n");
    } else {
        while (current_node != NULL) {
            fprintf(output,"resource_id:            %s\n", current_node->resource_id);
            fprintf(output,"patron_id:              %s\n", current_node->patron_id);
            fprintf(output,"checkout_date:          %s\n", current_node->checkout_date);
            fprintf(output,"due_date:               %s\n", current_node->due_date);
            fprintf(output,"checkin_date:           %s\n", current_node->checkin_date);
            current_node = current_node->next_check;
        }
    }
}

int add_check_node(check_node_type **head_node,  check_node_type *check_node) {
    check_node_type *current_node;
    char chunks[chunk_count_max][chunk_length_max];
    
    if (head_node == NULL) {
        *head_node = (check_node_type *) malloc( sizeof(check_node_type));
        strcpy( (*head_node)->resource_id, chunks[0]);
        strcpy( (*head_node)->patron_id, chunks[0]);
        strcpy( (*head_node)->checkout_date, chunks[0]);
        strcpy( (*head_node)->due_date, chunks[0]);
        strcpy( (*head_node)->checkin_date, chunks[0]);
        (*head_node)->next_check = NULL;
        current_node = *head_node;
        printf("Note: Added head_node!\n");
    } else {
        current_node->next_check = (check_node_type *) malloc( sizeof(check_node_type));
    }
}
int remove_check_node(check_node_type **head_node, check_node_type *check_node) {
    check_node_type *current_node;
    current_node = *head_node;
    
    int match = 0;
    if(compare_check_node(current_node, check_node) == 1) {
        //current_node->checkin_date = time();
    } else if(current_node->next_check == NULL) {
        return(match);
    } else {
        //keep looking...
    }
    return(match);
}

int isa_check_all_fields_list(check_node_type *head_node, check_node_type *check_node);
int isa_check_node(check_node_type *head_node, char resource_id[], char patron_id[]);

int get_check_all_fields_list(check_node_type *head_node, check_node_type *check_node);

int get_check_node(check_node_type *head_node, char check_id[], check_node_type *check_node) {
    check_node_type *current_node;
    current_node = head_node;
    
/*
    int found = 0;
    while((current_node != NULL) && (found == 0)) {
        if(string_compare(current_node->))
    }
}
*/
    // no check id in structure def.
}

int compare_check_node(check_node_type *first_check_node, check_node_type *second_check_node) {
    check_node_type *current_node;
    int match;
    match = 0;
    
    if((string_compare(first_check_node->checkin_date, second_check_node->checkin_date, case_insensitive) == 0) &&
            (string_compare (first_check_node->checkout_date, second_check_node->checkout_date, case_insensitive) == 0) &&
            (string_compare(first_check_node->due_date, second_check_node->due_date, case_insensitive) == 0) &&
            (string_compare(first_check_node->patron_id, second_check_node->patron_id, case_insensitive) == 0) &&
            (string_compare(first_check_node->resource_id, second_check_node->resource_id, case_insensitive) == 0) ) {
        printf("Note: Match found\n");
        match = 1;
    }  else {
        printf("Note: No match found\n");
    }
    return(match);
    
}
 
int copy_check_node(check_node_type *destination_node, check_node_type *source_node) {
    strcpy( destination_node->patron_id, source_node->patron_id);
    strcpy( destination_node->resource_id, source_node->resource_id);
    strcpy( destination_node->checkin_date, source_node->checkin_date);
    strcpy( destination_node->checkout_date, source_node->checkout_date);
    strcpy( destination_node->due_date, source_node->due_date);
    destination_node->next_check == NULL;
}

/*
int sort_check_node(check_node_type *head_node, check_field_enum field_name, order_type order) {
/*
    typedef enum
    { check_resource_id, check_patron_id, checkout_date, due_date }
check_field_enum;
 * 
 * 
*/
/*
    
    check_node_type *current_node;
    check_node_type *temp_node;
    
    int done = 0;
    
    if(*head_node == NULL) {
        
    } else if (*head_node->next_check == NULL) {
        
    } else {
        if(field_name == check_field_enum->check_patron_id) {
            if ( order == ascending) {
                current_node = *head_node;
                    while(done == 0) {
                        done = 1;
                        while ( current_node->next_check != NULL) {
                            if(string_compare(current_node->patron_id, current_node->next_check, case_insensitive) > 0 ) {
                                copy_patron_node(temp_node, current_node);
                                copy_patron_node(current_node, current_node->next_check);
                                copy_patron_node(current_node->next_check, temp_node);
                                done == 0;
                            } else {
                                // keep looking...
                            }
                        }
                        current_node = current_node->next_check; // increment the node pointer
                }  
            } else if (order == descending) {
                current_node = *head_node;
                    while(done == 0) {
                        done = 1;
                        while ( current_node->next_check != NULL) {
                            if(string_compare(current_node->patron_id, current_node->next_check, case_insensitive) < 0 ) {
                                copy_patron_node(temp_node, current_node);
                                copy_patron_node(current_node, current_node->next_check);
                                copy_patron_node(current_node->next_check, temp_node);
                                done == 0;
                            } else {
                                // keep looking...
                            }
                        }
                        current_node = current_node->next_check; // increment the node pointer
                } 
            } else {
                // invalid order
            }
        } else if (field_name == check_field_enum->check_resource_id) {
            if ( order == ascending) {
                current_node = *head_node;
                    while(done == 0) {
                        done = 1;
                        while ( current_node->next_check != NULL) {
                            if(string_compare(current_node->resource_id, current_node->next_check, case_insensitive) > 0 ) {
                                copy_patron_node(temp_node, current_node);
                                copy_patron_node(current_node, current_node->next_check);
                                copy_patron_node(current_node->next_check, temp_node);
                                done == 0;
                            } else {
                                // keep looking...
                            }
                        }
                        current_node = current_node->next_check; // increment the node pointer
                } 
            } else if (order == descending) {
                current_node = *head_node;
                    while(done == 0) {
                        done = 1;
                        while ( current_node->next_check != NULL) {
                            if(string_compare(current_node->resource_id, current_node->next_check, case_insensitive) < 0 ) {
                                copy_patron_node(temp_node, current_node);
                                copy_patron_node(current_node, current_node->next_check);
                                copy_patron_node(current_node->next_check, temp_node);
                                done == 0;
                            } else {
                                // keep looking...
                            }
                        }
                        current_node = current_node->next_check; // increment the node pointer
                } 
            } else {
                // invalid order
            }
        } else if (field_name == check_field_enum->checkout_date) {
            if ( order == ascending) {
                current_node = *head_node;
                    while(done == 0) {
                        done = 1;
                        while ( current_node->next_check != NULL) {
                            if(string_compare(current_node->checkout_date, current_node->next_check, case_insensitive) > 0 ) {
                                copy_patron_node(temp_node, current_node);
                                copy_patron_node(current_node, current_node->next_check);
                                copy_patron_node(current_node->next_check, temp_node);
                                done == 0;
                            } else {
                                // keep looking...
                            }
                        }
                        current_node = current_node->next_check; // increment the node pointer
                } 
            } else if (order == descending) {
                current_node = *head_node;
                    while(done == 0) {
                        done = 1;
                        while ( current_node->next_check != NULL) {
                            if(string_compare(current_node->checkout_date, current_node->next_check, case_insensitive) < 0 ) {
                                copy_patron_node(temp_node, current_node);
                                copy_patron_node(current_node, current_node->next_check);
                                copy_patron_node(current_node->next_check, temp_node);
                                done == 0;
                            } else {
                                // keep looking...
                            }
                        }
                        current_node = current_node->next_check; // increment the node pointer
                } 
            } else {
                // invalid order
            }
        } else if (field_name == check_field_enum->due_date) {
            if ( order == ascending) {
                current_node = *head_node;
                    while(done == 0) {
                        done = 1;
                        while ( current_node->next_check != NULL) {
                            if(string_compare(current_node->due_date, current_node->next_check, case_insensitive) > 0 ) {
                                copy_patron_node(temp_node, current_node);
                                copy_patron_node(current_node, current_node->next_check);
                                copy_patron_node(current_node->next_check, temp_node);
                                done == 0;
                            } else {
                                // keep looking...
                            }
                        }
                        current_node = current_node->next_check; // increment the node pointer
                } 
            } else if (order == descending) {
                current_node = *head_node;
                    while(done == 0) {
                        done = 1;
                        while ( current_node->next_check != NULL) {
                            if(string_compare(current_node->due_date, current_node->next_check, case_insensitive) < 0 ) {
                                copy_patron_node(temp_node, current_node);
                                copy_patron_node(current_node, current_node->next_check);
                                copy_patron_node(current_node->next_check, temp_node);
                                done == 0;
                            } else {
                                // keep looking...
                            }
                        }
                        current_node = current_node->next_check; // increment the node pointer
                } 
            } else {
                // invalid order
            }
        } else {
            // invalid check_field_enum
        }
    }
}
*/
