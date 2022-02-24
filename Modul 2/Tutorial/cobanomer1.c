#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxl 255

int main(){
    int i=0;
    char namafile[20];
    FILE *data;

    printf("Masukkan nama file: ");
    scanf("%s", namafile);

    data = fopen(namafile, "r");

    char line1[maxl]; // Buat baris pertama yang bakal dicari
    char key1[maxl]; // Kata kunci 1
    char key2[maxl]; // Kata kunci 2
    char key3[maxl]; // Kata kunci 3
    char ikuzoga[maxl]; // Kata kunci ikuzo buat ngebalik


    fscanf(data, "%s\n%s\n%s\n%s\n%s\n", line1, key1, key2, key3, ikuzoga);
    fclose(data);

    int idx_1 = 0;
    int idx_2 = 0;
    int idx_3 = 0;
    char *ret1;
    char *ret2;
    char *ret3;
    char sandi_1[maxl];
    char sandi_2[maxl];
    char sandi_3[maxl];

    ret1 = strstr(line1, key1);
    idx_1 = ret1-line1+1;
    int l1 = strlen(key1);

    itoa((idx_1*l1), sandi_1, 10);


    ret2 = strstr(line1, key2);
    idx_2 = ret2-line1+1;
    int l2 = strlen(key2);

    itoa((idx_2*l2), sandi_2, 10);


    ret3 = strstr(line1, key3);
    idx_3 = ret3-line1+1;
    int l3 = strlen(key3);

    itoa((idx_3*l3), sandi_3, 10);


    strcat(sandi_1, sandi_2);
    strcat(sandi_1, sandi_3);

    if (!strcmp(ikuzoga, "ikuzo")) {
        printf("Kata sandi untuk membuka truk: %s", strrev(sandi_1));
    }
    else {
        printf("Kata sandi untuk membuka truk: %s", sandi_1);
    }


    return 0;

}
