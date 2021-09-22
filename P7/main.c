/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Cory
 *
 * Created on November 19, 2019, 4:03 PM
 * 
 * Arguments:
 *  argv[1]: table options are /patron /resource /check
 *  argv[2]: action options are /add /remove /sort /display /export
 *  argv[3]: add options are based on table
 *              /patron /add <patron_id> <first_name> <last_name> <address> <city> <state> <zip>
 *              /resource /add <resource_id> <resource_title> <resource_type> <resource_price>
 *              /check /add <resource_id> <patron_id>
 *  argv[3]: remove options are based on table
 *              /patron /remove <patron_id> --> active goes to inactive
 *              /resource /remove <resource_id> --> active goes to inactive
 *              /check /remove <resource_id> <patron_id>
 *  argv[3]: sort options are based on table
 *              /patron /sort <patron_id | patron_last_name> /ascending or /descending>
 *              /resource /sort <resource_id | resource_type> /ascending or /descending>
 *              /check /sort <resource_id | patron_id | checkout_date | due_date(???)> /ascending or /descending>
 *  argv[3]: display options are based on table
 *              /patron /display /patron_id <patron_id>
 *              /resource /display /resource_id <resource_id>
 *              /check /display /resource_id <resource_id> /patron_id <patron_id>
 *              /check /display /resource_id <resource_id> --> show all Patron(s) that have checked out the Resource
 *              /check /display /patron_id <patron_id> --> show all checked out Rsources
 *  argv[3]: export options are based on table
 *              /patron /export /patron_id <patron_id>
 *              /resource /export /resource_id <resource_id> 
 *              /check /export /patron_id <patron_id>
 *              /check /export /resource_id <resource_id>             
 *              /check /export /patron_usage --> includes patron_id, patron_first_name, patron_last_name, check_count
 *              /check /export /resource_usage --> include resource_id, resource_title, check_count
 *              /check /export /over_due --> include resource_id, patron_id, checkout_date, due_date, fine
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "corelib.h"
#include "patron.h"

void help (void);

/*
 * 
 */
int main(int argc, char** argv) {
    
    char patron_id[10];
    char first_name[15];
    char last_name[15];
    char address[45];
    char city[20];
    char state[2];
    char zip[5];
    
    char resource_id[10];
    char resource_title[20];
    char author[50];
    char resource_type[10];
    double resource_price;
    
    patron_node_type *head_node;
    
    head_node = NULL;
    
    import_patrons_node("patrons.csv", head_node);
    
    if (strcmpi(argv[1], "/patron") == 0) {
        if (strcmpi(argv[2], "/add") == 0) {
            printf("Add Patron\n");
            // <patron_id> <first_name> <last_name> <address> <city> <state> <zip>
            printf("Enter Patron ID\n");
            scanf("%c", &patron_id);
            printf("Enter Patron first name\n");
            scanf("%c", &first_name);
            printf("Enter Patron last name\n");
            scanf("%c", &last_name);
            printf("Enter Patron address\n");
            scanf("%c", &address);
            printf("Enter Patron city\n");
            scanf("%c", &city);
            printf("Enter Patron state\n");
            scanf("%c", &state);
            printf("Enter Patron zip\n");
            scanf("%c", &zip);
            patron_structure_builder( patron_id, first_name, last_name, address, city, state, zip);
            
            // now that all info is gathered call add patron to function to add them to patron.csv
        } else if (strcmpi(argv[2], "/remove") == 0) {
            printf("Remove Patron\n");
            printf("Enter Patron ID\n");
            scanf("%c", &patron_id);
            
            // search for patron in csv and change their status to inactive
        } else if (strcmpi(argv[2], "/sort") == 0) {
            printf("Patron Sort\n");
        } else if (strcmpi(argv[2], "/display") == 0) {
            printf("Patron Display\n");
        } else if (strcmpi(argv[2], "/export") == 0) {
            printf("Patron Export\n");
        } else {
            printf("Error: Please select valid patron action\n");
            help();
        }
    } else if (strcmpi(argv[1], "/resource") == 0) {
        if (strcmpi(argv[2], "/add") == 0) {
            printf("Add Resource\n");
            // <resource_id> <resource_title> <resource_type> <resource_price>
            printf("Enter Resource ID\n");
            scanf("%c", &resource_id);
            printf("Enter Resource title\n");
            scanf("%c", &resource_title);
            printf("Enter Resource type\n");
            scanf("%c", &resource_type);
            printf("Enter author name\n");
            scanf("%c", &author);
            printf("Enter Resource price\n");
            scanf("%lf", &resource_price);
            
            // now that all info is gathered, add the resource to resource.csv
        } else if (strcmpi(argv[2], "/remove") == 0) {
            printf("Remove Resource\n");
            printf("Enter resource ID\n");
            scanf("%c", &resource_id);
        } else if (strcmpi(argv[2], "/sort") == 0) {
            printf("Resource Sort\n");
        } else if (strcmpi(argv[2], "/display") == 0) {
            printf("Resource Display\n");
        } else if (strcmpi(argv[2], "/export") == 0) {
            printf("Resource Export\n");
        } else {
            printf("Error: Please select valid resource action\n");
            help();
        }
    } else if (strcmpi(argv[1], "/check") == 0) {
        if (strcmpi(argv[2], "/add") == 0) {
            printf("Check Add\n");
            // return resource
        } else if (strcmpi(argv[2], "/remove") == 0) {
            printf("Check Remove");
            // check out resource
        } else if (strcmpi(argv[2], "/sort") == 0) {
            printf("Sort Checks");
        } else if (strcmpi(argv[2], "/display") == 0) {
            if (strcmpi(argv[3], "/resource_id") == 0) {
                printf("Display Resource ID\n");
            } else if (strcmpi(argv[3], "/patron_id") == 0) {
                printf("Display Patron ID\n");
            } else {
                printf("Error: Please enter a valid display option\n");
                help();
            }
        } else if (strcmpi(argv[2], "/export") == 0) {
            if (strcmpi(argv[3], "patron_id") == 0) {
                printf("Export Patron ID\n");
            } else if (strcmpi(argv[3], "resource_id") == 0) {
                printf("Export Resource ID\n");
            } else if (strcmpi(argv[3], "patron_usage") == 0) {
                printf("Export Patron Usage\n");
            } else if (strcmpi(argv[3], "resource_usage") == 0) {
                printf("Export Resource Usage\n");
            } else if (strcmpi(argv[3], "over_due") == 0) {
                printf("Export Over Due\n");
            } else {
                printf("Error: Please enter a valid export option\n");
                help();
            }
        } else {
            printf("Error: Please enter a valid check option\n");
            help();
        }
    } else {
        printf("Error: Please enter valid action\n");
        help();
    }

    return (EXIT_SUCCESS);
}

void help (void) {
    printf("help here\n");
}