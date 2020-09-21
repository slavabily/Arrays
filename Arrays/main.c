//
//  main.c
//  Arrays
//
//  Created by slava bily on 16.09.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_data(int d[], int size) {
    int i;
    for (i = 1; i <= size; i++) {
        printf("%d\t", d[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
}

double average(int d[], int size) {
    int i;
    double avg = 0.0;
    
    for (i = 1; i <= size; i++) {
        avg += d[i];
    }
    return avg / size;
}

int max_value(int d[], int size) {
    int i;
    
    for (i = 1; i <= size; i++) {
        if (d[1] < d[i]) {
            d[1] = d[i];
        }
    }
    return d[1];
}

int main(int argc, const char * argv[]) {
    FILE *ifp, *ofp;
    char number[20];
    char comment[50];
    int i, sz;
    int data[10];
    
    ifp = fopen("arr", "r");
    ofp = fopen("answer-hw3", "w");
    
    // MARK: Reading the first array element
    fscanf(ifp, "%d", &sz);
    
    sprintf(number, "%d", sz);
    strcpy(comment, "The number of elements in array is:\t");
    
    if ( ofp == NULL )
    {
        printf( "Could not open file answer-hw3" ) ;
        return 1;
    }
    
    // writing to the file
    if (number > 0 && comment > 0) {
        fputs(comment, ofp);
        fputs(number, ofp) ;
        fputs("\n", ofp) ;
    }
 // printing to the console
    printf("%s %d\n",comment, sz);
    
    // MARK: Reading the array itself
    for (i = 1; i <= sz; i++) {
        fscanf(ifp, "%d", &data[i]);
    }
    // writing to the file
    strcpy(comment, "The array itself is: \t");
    if (number > 0 && comment > 0) {
        fputs(comment, ofp);
        for (i = 1; i <= sz; i++) {
            sprintf(number, "%d", data[i]);
            fputs(number, ofp);
            fputs("\t", ofp);
        }
        fputs("\n", ofp) ;
    }
    // printing to the console
    printf("%s", comment);
    print_data(data, sz);
    
    printf("\n%g\n", average(data, sz));
    
    printf("%d\n", max_value(data, sz));
    
    return 0;
}
