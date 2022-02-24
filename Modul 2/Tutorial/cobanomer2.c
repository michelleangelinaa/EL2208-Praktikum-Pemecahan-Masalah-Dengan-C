
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxl 255

int main(){
    int i=0;
    char namafile[20];
    FILE *data;
    char line[maxl];

    printf("Masukkan nama file: ");
    scanf("%s", namafile);

    data = fopen(namafile, "r");

    while (fgets(line, maxl, data)) {
        if ()

    }

