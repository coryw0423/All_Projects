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

int file_read( char const file_name[], char contents[] ) {
        // looks for end of file
    FILE *input;
    int results;
    int index;
    char chunk;
    
    index = 0;
    results = 0;
    
    input = fopen( file_name, "r" );
    if (input != NULL) {
        while (fscanf( input, "%c", &chunk ) != EOF ) {
            contents[ index ] = chunk;
            results++;
            index++;
        }
    } else {
        printf("Error: no valid file!\n");
    }
    return( results );    
}

int file_read_line( FILE *input, char line[] ) {
    // looks for end of line.. (new line)
    int results;
    char chunk;
    int done;
    
    results = 0;
    done = 0;
    
    if (input != NULL) {
/*
        while ((fscanf( input, "%c", chunk ) != EOF) && (chunk != '\n')) {
            line[ results ] = chunk;
            results++;
        }
        line[ results ] = '\0';
*/                    
        while ((done == 0) && (fscanf( input, "%c", &chunk ) != EOF)) {
            if (chunk == '\n') {
                line[ results ] = '\0';
                done = 1;
            } else {
                // keep storing/looking..
                line[ results ] = chunk;
            }
            results++;
        }
    } else {
        printf("Error: no valid file pointer\n");
        results = -1;
    }
    return( results );
}

int char_find( char contents[], int contents_length, char search, int locations[]) {
    // return the number of found locations...
    // contents is a char vector 
    int results;
    int contents_index;
    
    results = 0;
    contents_index = 0;
    while ( contents_index < contents_length ) {
        if (search == contents[ contents_index ]) {
            // we found a match!
            locations[ results ] = contents_index; // where was it found in the contents..
            results++;
        } else { 
            // keep looking...
        }
        contents_index++;
    }        
    return( results );    
}

int string_find( char contents[], char search[], int locations[]) {
    int contents_index;
    int search_index;
    int count;
    int contents_length;
    int search_length;
    int matching; // flag
    
    contents_index = 0;
    search_index = 0;
    count = 0;
    matching = 0;
    
    contents_length = string_length( contents );
    search_length = string_length( search );
    
    if ((contents_length != 0 ) && (search_length != 0 ) && (search_length <= contents_length)) {
        while ( contents_index < (contents_length - search_length)) {
            matching = 1;
            search_index = 0; 
            while ((search_index < search_length ) && (matching == 1 )) {
                if (contents[ contents_index + search_index ] == search[ search_index ]) {
                    // keep looking...
                } else {
                    matching = 0;
                }
                search_index++;
            }
            if (matching == 1) {
                // store the location
                locations[ count ] = contents_index;
                count++;
            } else {
                // keep on looking...
            }
            contents_index++; // moves to the next character
        }                
    } else {
        // we assume we have nothing to search...
    }
    
    return( count );    
}

int string_split( char contents[], char delimiter, char chunks[][chunk_length_max]) {
    int chunk_index; // row in the chunks 
    int char_index; // column in a specific chunk
    int contents_index;
    
    chunk_index = 0;
    char_index = 0;
    contents_index = 0;
        
    // while not EOS, chunk_length_max, chunk_count_max
    while ((contents[ contents_index ] != '\0') && (char_index < chunk_length_max) && (chunk_index < chunk_count_max)) {
        // look for our delimiter...
        // create a new chunk...
        if (contents[ contents_index ] == delimiter ) {
            // start a new chunk - must also close out the last chunk...
            chunks[ chunk_index ][ char_index ] = '\0';
            chunk_index++;
            char_index = 0;
        } else {
            // we want to keep the character in our existing chunks..
            chunks[ chunk_index ][ char_index ] = contents[ contents_index ];
            char_index++; // moves to the next columnm...
        }
        
        contents_index++;
    }
    chunks[ chunk_index ][ char_index ] = '\0';
    
    return( chunk_index + 1);
}

int string_compare( char const first[], char const second[], case_sensitivity_type sensitivity ) {
    /* Upper case: (A-Z) --> (65-90)
     * Lower case: (a-z) --> (97-122)
     */   
    
    /* check to see if a char falls within the range alphabetic characters
     * 
     * comparing two words....
     *  need to get the length of both words (for loop)
     *  use the end of string character --> use a while loop...
     * character by character comparison...
     * char1 is part of string1
     * char2 is part of string2
     *  if char1 < char2 --> string1 < string2
     *  if char1 > char2 --> string1 > string2
     *  if char1 == char2 --> string1 == string2 (if this is true for all char and
     *      they are the same length...
     * 
     * deal with sensitivity first...
     * return values:
     *  -1 : first comes before second
     *   0 : first is the same as second
     *   1 : first comes after second
     */
    
    int first_length;
    int second_length;
    int shortest_length;
    int index;
    int results;
    char first_modified[ 20 ];
    char second_modified[ 20 ];
        
    results = 0; /// assume they are equal...
    
    printf("Length of %s is %Iu\n", first, strlen(first));
    printf("Length of %s is %d\n", first, (int) strlen(first));
    
    printf("Length of %s is %Iu\n", second, strlen(second));
    printf("Length of %s is %d\n", second, (int) strlen(second));
    
    if (sensitivity == case_sensitive) {
        // case matters
        strcpy( first_modified, first);
        strcpy( second_modified, second );
        
        first_length = string_length( first );
        second_length = string_length( second );
        if (second_length < first_length) {
            shortest_length = second_length;
        } else {
            shortest_length = first_length;
        }
        // we either run out of chars or they no longer match...
        while ((index < shortest_length ) && (results == 0)) {
            if (first_modified[ index ] < second_modified[ index ]) {
                // first word comes before the second..
                results = -1;
            } else if (first_modified[ index ] > second_modified[ index ] ) {
                // first comes after the second...
                results = 1;
            } else {
                // assume equal...
                results = 0; 
            }
            index++;
        }
        if (results == 0) {
            // it made it here with all of the chars matching...
            if (first_length < second_length) {
                results = -1;
            } else if (first_length > second_length ) {
                results = 1;
            } else {
                results = 0; // they are the same length AND the same chars
            }
        } else {
            // results are already either -1 or 1 indicating an order...
        }        
    } else if (sensitivity == case_insensitive) {
        // case does not matter...
        // pick either upper or lower and shift all the char to that range...
        string_lower( first_modified, first );
        string_lower( second_modified, second );
        
        first_length = string_length( first );
        second_length = string_length( second );
        if (second_length < first_length) {
            shortest_length = second_length;
        } else {
            shortest_length = first_length;
        }
        // we either run out of chars or they no longer match...
        while ((index < shortest_length ) && (results == 0)) {
            if (first_modified[ index ] < second_modified[ index ]) {
                // first word comes before the second..
                results = -1;
            } else if (first_modified[ index ] > second_modified[ index ] ) {
                // first comes after the second...
                results = 1;
            } else {
                // assume equal...
                results = 0; 
            }
            index++;
        }
        if (results == 0) {
            // it made it here with all of the chars matching...
            if (first_length < second_length) {
                results = -1;
            } else if (first_length > second_length ) {
                results = 1;
            } else {
                results = 0; // they are the same length AND the same chars
            }
        } else {
            // results are already either -1 or 1 indicating an order...
        }     
    } else {
        printf("Error: Unhandled sensitivity\n");
    }
                  
    return( results );
}

int string_length( char const source[] ) {
    int index;
    
    index = 0;
    
    while (source[ index ] != '\0') {
        index++;
    }
    return( index );
}

int string_upper( char destination[], char const source[] ) {
    int index;
    int count;
    
    index = 0;
    count = 0;
    
    while (source[ index ] != '\0') {
        if (( source[ index ] >= 97 ) && ( source[ index ] <= 122 )) {
            destination[ index ] = source[ index ] - 32;
            count++;
        } else {
            destination[ index ] = source[ index ];
        }
        index++;
    }
    destination[ index ] = '\0';
    return( count );
}

int string_lower( char destination[], char const source[] ) {
    int index;
    int count;
    
    index = 0;
    count = 0;
    
    while (source[ index ] != '\0') {
        if (( source[ index ] >= 65 ) && ( source[ index ] <= 90 )) {
            destination[ index ] = source[ index ] + 32;
            count++;
        } else {
            destination[ index ] = source[ index ];
        }
        index++;
    }
    destination[ index ] = '\0';
    return( count );    
}

int count_string( char const input_filename[], char const output_filename[], case_sensitivity_type sensitivity, column_name_type column_name, order_type order ) {
    
}
int count_char( char const input_filename[], char const output_filename[], case_sensitivity_type sensitivity, column_name_type column_name, order_type order ) {
    
}
int count_double( char const input_filename[], char const output_filename[], column_name_type column_name, order_type order ) {
    
}
int count_int( char const input_filename[], char const output_filename[], column_name_type column_name, order_type order ) {
    
}

int sort_string(char strings[][string_length_max], case_sensitivity_type sensitivity, order_type order, int new_order[], int n ) {
    
}
int sort_char(char chars[], case_sensitivity_type sensitivity, order_type order, int new_order[], int n ) {
    
}

int sort_double(double numbers[], order_type order, int new_order[], int n ) {
    
}

int sort_int(int numbers[], order_type order, int new_order[], int n ) {
    
}

int export_int2Darray(int array[n_max][m_max], int n, int m, char *filename, char *delimiter)  {
    FILE *output;
    output = fopen(filename, "w");
    int n_count;
    int m_count;
    if (output != NULL) {
        for ( n_count = 0; n_count < n; n_count++) {

            for ( m_count = 0; m_count < m; m_count++) {
                if (m_count = m - 1) {
                    fprintf(output, "%d\n", array[n_count][m_count]);
                } else {
                    fprintf(output, "%d",array[n_count][m_count]);
                }
            }
        }
        fclose(output);
        return (EXIT_SUCCESS);
    }
}

int export_double2Darray(double array[n_max][m_max], int n, int m, char *filename, char *delimiter)  {
    FILE *output;
    output = fopen(filename,"w");
    int n_count;
    int m_count;
    if (output != NULL) {
        for (n_count = 0; n_count < n; n_count++) {

            for (m_count = 0; m_count < m; m_count++) {
                if (m_count == m - 1) {
                    fprintf(output, "%lf\n", array[n_count][m_count]);
                } else {
                    fprintf(output, "%lf",array[n_count][m_count]);
                }
            }
        }
        fclose(output);
        return (EXIT_SUCCESS);
    }    
}

int export_char2Darray(char array[n_max][m_max], int n, int m, char *filename, char *delimiter)  {
    FILE *output;
    output = fopen(filename,"w");
    int n_count;
    int m_count;
    if (output != NULL) {
        for (n_count = 0; n_count < n; n_count++) {

            for (m_count = 0; m_count < m; m_count++) {
                if (m_count == m - 1) {
                    fprintf(output, "%c\n", array[n_count][m_count]);
                } else {
                    fprintf(output, "%c",array[n_count][m_count]);
                }
            }
        }
        fclose(output);
        return (EXIT_SUCCESS);
    }    
}

int export_string2Darray(char array[n_max][m_max][chunk_length_max], int n, int m, char *filename, char *delimiter)  {
    FILE *output;
    output = fopen(filename,"w");
    int n_count;
    int m_count;
    if (output != NULL) {
        for (n_count = 0; n_count < n; n_count++) {

            for (m_count = 0; m_count < m; m_count++) {
                if (m_count == m - 1) {
                    fprintf(output, "%s\n", array[n_count][m_count]);
                } else {
                    fprintf(output, "%s",array[n_count][m_count]);
                }
            }
        }
        fclose(output);
        return (EXIT_SUCCESS);
    }    
}


