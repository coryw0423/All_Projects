/* 
 * File: check.h
 * Copy: Copyright (c) 2019 Gregory C. Myers
 * BlazerID: gmyers
 * Vers: 1.0.0 12/03/2019 GCM - Original Coding
 * Desc: Header file for aggregating functions 
 */

#if !defined check_defined

typedef enum
    { check_resource_id, check_patron_id, checkout_date, due_date }
check_field_enum;

typedef struct check_node {
    char resource_id[20];
    char patron_id[20];
    char checkout_date[20];
    char due_date[20];
    char checkin_date[20];
    struct check_node *next_check;
} check_node_type;

int import_checks_node(char const filename[], check_node_type **head_node);
int display_checks_node(check_node_type *head_node);
int examine_check_node(check_node_type *head_node );
int display_check_node(check_node_type *check_node );
int export_checks_node(char const filename[], check_node_type *head_node);

int add_check_node(check_node_type **head_node,  check_node_type *check_node);
int remove_check_node(check_node_type **head_node, check_node_type *check_node);

int isa_check_all_fields_list(check_node_type *head_node, check_node_type *check_node);
int isa_check_node(check_node_type *head_node, char resource_id[], char patron_id[]);

int get_check_all_fields_list(check_node_type *head_node, check_node_type *check_node);
int get_check_node(check_node_type *head_node, char check_id[], check_node_type *check_node);

int compare_check_node(check_node_type *first_check_node, check_node_type *second_check_node);
int copy_check_node(check_node_type *destination_node, check_node_type *source_node);

int sort_check_node(check_node_type *head_node, check_field_enum field_name, order_type order);

#endif
