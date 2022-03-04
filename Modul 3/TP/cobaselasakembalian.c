#include <stdio.h>
#include <stdlib.h>

int main() {
    int barang, uang;

    printf("Masukkan jumlah uang: ");
    scanf("%d", &uang);
    printf("Masukkan jumlah barang: ");
    scanf("%d", &barang);

    if (uang < barang) {
        printf("Uang anda tidak cukup!");
    }

    else if (uang == barang) {
        printf("Tidak ada kembalian!");
    }

    else {
        kembalian(uang, barang);
    }

    return 0;
}

void kembalian(int uang, int barang) {
    int selisih = uang - barang;

    int lembaran[9] = {1000000, 500000, 100000, 50000, 20000, 10000, 5000, 2000, 1000};

    for (int i = 0; i < 9; i++) {
        int lbr = selisih/lembaran[i];

            if (lbr == 0) {
            }

            else {
                if (lembaran[i] == 1000000) {
                    printf("%d lembar uang 1.000.000\n", lbr);
                    selisih %= lembaran[i]*lbr;
                }

                else if (lembaran[i] == 500000) {
                    printf("%d lembar uang 500.000\n", lbr);
                    selisih %= lembaran[i]*lbr;
                }

                else if (lembaran[i] == 100000) {
                    printf("%d lembar uang 100.000\n", lbr);
                    selisih %= lembaran[i]*lbr;
                }

                else if (lembaran[i] == 50000) {
                    printf("%d lembar uang 50.000\n", lbr);
                    selisih %= lembaran[i]*lbr;
                }

                else if (lembaran[i] == 20000) {
                    printf("%d lembar uang 20.000\n", lbr);
                    selisih %= lembaran[i]*lbr;
                }

                else if (lembaran[i] == 10000) {
                    printf("%d lembar uang 10.000\n", lbr);
                    selisih %= lembaran[i]*lbr;
                }

                else if (lembaran[i] == 5000) {
                    printf("%d lembar uang 5.000\n", lbr);
                    selisih %= lembaran[i]*lbr;
                }

                else if (lembaran[i] == 2000) {
                    printf("%d lembar uang 2.000\n", lbr);
                    selisih %= lembaran[i]*lbr;
                }

                else {
                    printf("%d lembar uang 1.000\n", lbr);
                    selisih %= lembaran[i]*lbr;
                }

                }
    }

    if (selisih != 0) {
        printf("%d coin\n", selisih);
    }

}
