/* 
 * File: resource.h
 * Copy: Copyright (c) 2019 Gregory C. Myers
 * BlazerID: gmyers
 * Vers: 1.0.0 12/03/2019 GCM - Original Coding
 * Desc: Header file for aggregating functions 
 */

#if !defined resource_defined

typedef enum 
    { book, journal, audio_video, electronic, archive }
resource_option_enum;

typedef enum
    { resource_active, resource_inactive }
resource_status_enum;

typedef enum
    { resource_id, resource_option }
resource_field_enum;

typedef struct resource_node {
    char resource_id[20];
    char resource_title[50];
    resource_option_enum resource_option;
    double resource_price;
    char resource_date[20];
    resource_status_enum resource_status;
    struct resource_node *next_resource;
} resource_node_type;

int import_resources_node(char const filename[], resource_node_type **head_node);
int display_resource_node(resource_node_type *head_node);
int examine_resource_node(resource_node_type *head_node );
int display_resource_node(resource_node_type *resource_node );
int export_resources_node(char const filename[], resource_node_type *head_node);

int add_resource_node(resource_node_type **head_node,  resource_node_type *resource_node);
int remove_resource_node(resource_node_type **head_node, resource_node_type *resource_node);

int isa_resource_all_fields_list(resource_node_type *head_node, resource_node_type *resource_node);
int isa_resource_node(resource_node_type *head_node, char resource_id[]);

int get_resource_all_fields_list(resource_node_type *head_node, resource_node_type *resource_node);
int get_resource_node(resource_node_type *head_node, char resource_id[], resource_node_type *resource_node);

int compare_resource_node(resource_node_type *first_resource_node, resource_node_type *second_resource_node);
int copy_resource_node(resource_node_type *destination_node, resource_node_type *source_node);

int sort_resource_node(resource_node_type *head_node, resource_field_enum field_name, order_type order);

#endif
