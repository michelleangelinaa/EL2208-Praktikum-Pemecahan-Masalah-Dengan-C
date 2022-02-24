#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i;
    int j;
    char kode[255];
    char filejancuk[255];


    char barisaneh[255];
    char key1[255];
    char key2[255];
    char key3[255];
    char ikuzocok[255];

    printf("Masukkan nama file: ");
    scanf("%s", &filejancuk);

    FILE* openjancuk = fopen(filejancuk, "r");

    while (fgets(bariscok, 255, openjancuk)) {

        token = strtok(bariscok, "\n");
        strcpy(barisaneh, token);

        token = strtok(NULL, "\n");
        strcpy(key1, token);

        token = strtok(NULL, "\n");
        strcpy(key2, token);

        token = strtok(NULL, "\n");
        strcpy(key3, token);

        token = strtok(NULL, "\n");
        strcpy(ikuzocok, token);

    }

    int valid = 0;
    for (i=0; i<255; i++) {
        if (key1[0] == barisaneh[i]) {
            valid += 1;
            j = 1;
            k = i+1;
            while (key1[j] == barisaneh[k]) {
                valid += 1;

            }


        }

    }










    printf("Kata sandi untuk membuka truk: %s", kode);
    return 0;

}
