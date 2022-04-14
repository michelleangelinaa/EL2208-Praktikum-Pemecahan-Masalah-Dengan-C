#include <stdio.h>

int fibonacci(int i) {
	if (i <= 0) { // Karena diambil index 2 sebelumnya, anggap index yang negatif = 0 supaya tidak mengganggu deret
        return 0;
	}
	else if (i == 1) {
        return 1;
	}
	else {
        return (fibonacci(i-1)+fibonacci(i-2)); // Mengambil 2 nilai sebelumnya untuk dijumlahkan, terjadi rekursif
    }
}

int main() {
    int n, a;
    int fibo = 0;

    printf("Masukkan n: ");
    scanf("%d", &n);

    fibo = fibonacci(n);
    printf("F(n) = %d", fibo);

    return 0;
}
