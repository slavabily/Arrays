//
//  main.c
//  Arrays
//
//  Created by slava bily on 16.09.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void read_data(FILE *ptr, int d[], int *size) {
//    *size = 0;
//    while (fscanf(ptr, "%d", &d[*size]) == 1) {
//        (*size)++;
//    }
//}

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
    
    for (i = 0; i <= size; i++) {
        avg += d[i];
    }
    return avg / size;
}

int max_value(int d[], int size) {
    int i;
    
    for (i = 0; i <= size; i++) {
        if (d[0] < d[i]) {
            d[0] = d[i];
        }
    }
    return d[0];
}


int main(int argc, const char * argv[]) {
    FILE *ifp, *ofp;
    char str[20];
    char comment[50];
    int i, sz;
    int data[10];
    
    ifp = fopen("arr.txt", "r");
    ofp = fopen("answer-hw3.txt", "a");
    
    fscanf(ifp, "%d", &sz);
    
    sprintf(str, "%d", sz);
    strcpy(comment, "The number of elements in array is:\t");
    
    if ( ofp == NULL )
    {
        printf( "Could not open file test.txt" ) ;
        return 1;
    }
    
    // writing to the file
    if (str > 0 && comment > 0) {
        fputs(comment, ofp);
        fputs(str, ofp) ;
        fputs("\n", ofp) ;
    }
    fclose(ofp);
     
    printf("%d\n", sz);
    
    
    for (i = 1; i <= sz; i++) {
        fscanf(ifp, "%d", &data[i]);
    }
    
    print_data(data, sz);
    
    printf("\n%g\n", average(data, sz));
    
    printf("%d\n", max_value(data, sz));
    
    return 0;
}
