#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char fp[255];
    char line[31];

    printf("Input pesan: ");
    scanf("%s", &fp);

    FILE* filenya = fopen(fp, "r");

    while (fgets(line, 31, filenya)) {


}
