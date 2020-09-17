//
//  main.c
//  Arrays
//
//  Created by slava bily on 16.09.2020.
//

#include <stdio.h>

void read_data(FILE *ptr, int d[], int *size) {
    *size = 0;
    while (fscanf(ptr, "%d", &d[*size]) == 1) {
        (*size)++;
    }
}

void print_data(int d[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d\t", d[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
}

double average(int d[], int size) {
    int i;
    double avg = 0.0;
    
    for (i = 0; i < size; i++) {
        avg += d[i];
    }
    return avg / size;
}

int max_score(int d[], int size) {
    int i;
    
    for (i = 0; i < size; i++) {
        if (d[0] < d[i]) {
            d[0] = d[i];
        }
    }
    return d[0];
}


int main(int argc, const char * argv[]) {
    FILE *ifp;
    int i, sz;
    int data[10];
    
    ifp = fopen("arr", "r");
    
    fscanf(ifp, "%d", &sz);
    
    printf("%d\n", sz);
    
    return 0;
}
