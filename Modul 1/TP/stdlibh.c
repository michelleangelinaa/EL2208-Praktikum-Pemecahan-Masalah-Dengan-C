#include <stdlib.h>
#include <stdio.h>

int ngesort (const void*a, const void*b) {
    // angka pertama = *(int*)a == *(int*)b = angka selanjutnya
   return ( *(int*)a - *(int*)b );
}

int main () {
   int i;
   int num[5] = { 3, 96, 20, 42, 1 };
   
   qsort(num, 5, sizeof(int), ngesort);
   for( i=0 ; i<5; i++ ) {
      printf("%d ", num[i]);
   }

   return 0;
}
