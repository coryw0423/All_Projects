/* 
 * File: reservation.h
 * Copy: Copyright (c) 2019 Gregory C. Myers
 * BlazerID: gmyers
 * Vers: 1.0.0 12/03/2019 GCM - Original Coding
 * Desc: Header file for aggregating functions 
 */

#if !defined reservation_defined

typedef enum
    { reservation_active, reservation_inactive }
reservationin_status_enum;

typedef enum
    { reservation_resource_id, reservation_patron_id }
reservation_field_enum;

typedef struct reservation_node {
    char resource_id[20];
    char patron_id[20];
    char reservation_date[20];
    reservationin_status_enum reservationin_status;
    struct reservation_node *next_reservation;
} reservation_node_type;

int import_reservations_node(char const filename[], reservation_node_type **head_node);
int display_reservation_node(reservation_node_type *head_node);
int examine_reservation_node(reservation_node_type *head_node );
int display_reservation_node(reservation_node_type *reservation_node );
int export_reservations_node(char const filename[], reservation_node_type *head_node);

int add_reservation_node(reservation_node_type **head_node,  reservation_node_type *reservation_node);
int remove_reservation_node(reservation_node_type **head_node, reservation_node_type *reservation_node);

int isa_reservation_all_fields_list(reservation_node_type *head_node, reservation_node_type *reservation_node);
int isa_reservation_node(reservation_node_type *head_node, char resource_id[], char patron_id[]);

int get_reservation_all_fields_list(reservation_node_type *head_node, reservation_node_type *reservation_node);
int get_reservation_node(reservation_node_type *head_node, char reservation_id[], reservation_node_type *reservation_node);

int compare_reservation_node(reservation_node_type *first_reservation_node, reservation_node_type *second_reservation_node);
int copy_reservation_node(reservation_node_type *destination_node, reservation_node_type *source_node);

int sort_reservation_node(reservation_node_type *head_node, reservation_field_enum field_name, order_type order);

#endif
