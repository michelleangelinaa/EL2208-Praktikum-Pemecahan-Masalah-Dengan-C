#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 255
float nilai;

int counts(char s[], char c)
{
    // Count variable
    int res = 0;

    for (int i=0;i<strlen(s);i++)

        // checking character in string
        if (s[i] == c)
            res++;

    return res;
}

int main(){
    int i = 0;
    int valuegasabar = 0;
    char filename[MAX_LEN];
    printf("\nInput pesan: ");
    scanf("%s", &filename);

    // Array mama mahasiswa
    char text[MAX_LEN][MAX_LEN];

    // Variabel penyimpan baris dari file sementara
    char line[MAX_LEN];

    // Token penyimpan string sementara untuk parsing
    char* token;

    // Buka file untuk dibaca
    FILE* stream = fopen(filename, "r");

    while(fgets(line, MAX_LEN, stream)) {
    // Parse baris
    // Ambil string pada baris hingga tanda koma (koma tidak ikut dibaca)
    token = strtok(line, "\n");
    strcpy(text[i], token);

    // Copy string dari token ke array nama
    // String pada C tidak bisa di-assign dengan operator =, gunakan strcpy

    // Iterasi
    i++;
    }
    int count=0;
    if (counts(text[0], 'p') == 0){
        i+=1;
    }
    for (i=1;i<=4;i++){
        if (counts(text[i], 'p')==1){
            valuegasabar += 1;
            }
        else if (counts(text[i], 'p')==2){
            valuegasabar +=2;
            }
        else if (counts(text[i], 'p') ==3){
            valuegasabar +=4;
            }
        else if (counts(text[i], 'p') ==4){
            valuegasabar +=8;
            }
        else if (counts(text[i], 'p') ==5){
            valuegasabar +=16;
            }
        else if (counts(text[i], 'p') > 5){
            valuegasabar += 1000;
            break;
        }
        else{
            i++;
        }
        }
    printf("%d", valuegasabar);
    double hasilakhir;
    if (valuegasabar != 1000){
        hasilakhir = (valuegasabar/5.0f);
    }
    else{
        hasilakhir = valuegasabar;
    }
    printf("%d\n", counts(text[3], 'p'));
    printf("Nilai ketidaksabaran: %.2lf", hasilakhir);
    fclose(stream);
}
