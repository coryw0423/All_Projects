/* 
 * File: patron.h
 * Copy: Copyright (c) 2019 Gregory C. Myers
 * BlazerID: gmyers
 * Vers: 1.0.0 12/03/2019 GCM - Original Coding
 * Desc: Header file for aggregating functions 
 */

#if !defined patron_defined

typedef enum
    { patron_active, patron_inactive }
patron_status_enum;

typedef enum
    { patron_id, patron_last_name }
patron_field_enum;

typedef struct patron_node {
    char patron_id[20];
    char patron_first_name[20];
    char patron_last_name[20];
    char patron_address[50];
    char patron_city[20];
    char patron_state[20];
    char patron_zip[10];
    patron_status_enum patron_status;  
    struct patron_node *next_patron;
} patron_node_type;

int import_patrons_node(char const filename[], patron_node_type **head_node);
int display_patrons_node(patron_node_type *head_node);
int examine_patron_node(patron_node_type *head_node );
int display_patron_node(patron_node_type *patron_node );
int export_patrons_node(char const filename[], patron_node_type *head_node);

int add_patron_node(patron_node_type **head_node,  patron_node_type *patron_node);
int remove_patron_node(patron_node_type **head_node, patron_node_type *patron_node);

int isa_patron_all_fields_list(patron_node_type *head_node, patron_node_type *patron_node);
int isa_patron_node(patron_node_type *head_node, char patron_id[]);

int get_patron_all_fields_list(patron_node_type *head_node, patron_node_type *patron_node);
int get_patron_node(patron_node_type *head_node, char patron_id[], patron_node_type *patron_node);

int compare_patron_node(patron_node_type *first_patron_node, patron_node_type *second_patron_node);
int copy_patron_node(patron_node_type *destination_node, patron_node_type *source_node);

int sort_patron_node(patron_node_type *head_node, patron_field_enum field_name, order_type order);

int patron_structure_builder( char patron_id[], char first_name[], char last_name[], char address[], char city[], char state[], char zip[]);

#endif
