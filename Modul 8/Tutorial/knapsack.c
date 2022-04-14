/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
 *  Modul               : 8 - Algorithms
 *  Percobaan           : Tutorial
 *  Hari dan Tanggal    : Rabu, 7 April 2021
 *  Nama File           : knapsack.c
 *	Pembuat				: Tito Irfan
 *  Deskripsi           : Penyelesaian 0/1 knapsack problem dengan backtracking.
 */

/** Perintah Kompilasi
 * 
 * Linux/MacOS  - gcc -o knapsack knapsack.c
 * Windows      - gcc -o knapsack.exe knapsack.c
 * 
 * atau dengan Makefile:
 * 
 * Linux/MacOS - make
 */

#include <stdio.h>
#include <stdlib.h>

// Struct daftar barang
typedef struct ItemList {
    int* value;
    int* weight;
    int data_amt;
} ItemList;

/** is_promising. Cek apakah solusi menjanjikan untuk ditelusuri lebih jauh.
 * 
 * Hitung batas atas keuntungan yang dapat diperoleh dengan menambah barang
 * yang bisa ditambah secara greedy dan menambah fraksi harga barang yang
 * tersisa bila ada. 
 * 
 * Barang yang dicek untuk ditambah hanya barang yang memiliki indeks setelah
 * indeks barang yang diperiksa saat ini.
 * 
 * @param idx indeks barang yang diperiksa saat ini.
 * @param cur_value harga total barang saat ini.
 * @param cur_weight berat total barang saat ini.
 * @param best_value keuntungan terbaik yang telah ditemukan.
 * @param item_list list harga barang dan beratnya.
 * @param weight_limit batas berat barang.
 * @return 1 bila menjanjikan, 0 bila tidak.
 */
int is_promising(
    int idx,
    int cur_value,
    int cur_weight,
    int* best_value,
    ItemList* item_list,
    int weight_limit) {
    // Bila berat melebihi batas, solusi tidak menjanjikan
    if (cur_weight >= weight_limit)
        return 0;
    
    // Ambil barang dengan indeks setelah idx secara greedy, catat keuntungan dan beratnya
    int it = idx + 1;
    float bound = cur_value;
    int weight_so_far = cur_weight;

    while (it < item_list->data_amt && weight_so_far + item_list->weight[it] <= weight_limit) {
        weight_so_far += item_list->weight[it];
        bound += item_list->value[it];
        ++it;
    }

    // Bila masih ada sisa barang, tambahkan fraksi harga barang tersebut untuk
    // memenuhi ransel (seakan barang tersisa bisa dibagi)
    if (it < item_list->data_amt)
        bound += (weight_limit - weight_so_far) * item_list->value[it] / (float) item_list->weight[it];

    // Bila batas atas keuntungan melebihi keuntungan terbesar saat ini, solusi menjanjikan
    return bound > *best_value;
}

/** knapsack_recursive. Selesaikan masalah knapsack secara rekursif
 * dengan algoritma backtracking.
 * 
 * @param idx indeks barang yang diperiksa saat ini.
 * @param cur_value harga barang total pada kombinasi ini.
 * @param cur_weight berat barang total pada kombinasi ini.
 * @param item_combination kombinasi barang.
 * @param best_value keuntungan terbaik yang telah ditemukan.
 * @param best_combination kombinasi yang menghasilkan keuntungan terbaik.
 * @param item_list list harga barang dan beratnya.
 * @param weight_limit limit harga barang.
 * @result best_value dan best_combination menyimpan keuntungan terbaik dan
 *  kombinasi yang menghasilkannya.
 */
void knapsack_recursive(
    int idx,
    int cur_value,
    int cur_weight,
    int* item_combination,
    int* best_value,
    int* best_combination,
    ItemList* item_list,
    int weight_limit) {
    // Cek apakah solusi saat ini merupakan terbaik
    if (cur_weight <= weight_limit && cur_value > *best_value) {
        // Set solusi saat ini sebagai solusi terbaik
        *best_value = cur_value;
        for (int i = 0; i < item_list->data_amt; ++i)
            best_combination[i] = item_combination[i];
    }

    // Bila solusi menjanjikan, lakukan rekursi penambahan barang
    if (is_promising(
            idx, 
            cur_value, 
            cur_weight, 
            best_value, 
            item_list, 
            weight_limit)) {
        // Eksplor solusi dengan menyertakan barang pada idx
        item_combination[idx + 1] = 1;
        knapsack_recursive(
            idx + 1, 
            cur_value + item_list->value[idx + 1], 
            cur_weight + item_list->weight[idx + 1], 
            item_combination, 
            best_value, 
            best_combination, 
            item_list, 
            weight_limit);

        // Backtrack, lanjutkan eksplor solusi tanpa menyertakan barang pada idx
        item_combination[idx + 1] = 0;
        knapsack_recursive(
            idx + 1, 
            cur_value, 
            cur_weight, 
            item_combination, 
            best_value, 
            best_combination, 
            item_list, 
            weight_limit);
    }
}

/** print_knapsack. Fungsi driver untuk menyelesaikan 0/1 knapsack problem.
 * 
 * @param item_list list harga dan berat barang.
 * @param weight_limit batas berat barang.
 * @result keuntungan terbanyak dan kombinasinya tercetak di layar.
 */
void print_knapsack(ItemList* item_list, int weight_limit) {
    int* item_combination = (int*) calloc(item_list->data_amt, sizeof(int));
    int* best_combination = (int*) calloc(item_list->data_amt, sizeof(int));
    int best_value = 0;

    knapsack_recursive(-1, 0, 0, item_combination, &best_value, best_combination, item_list, weight_limit);

    printf("\nBest value: %d\n", best_value);

    printf("Best combination:\n");
    for (int i = 0; i < item_list->data_amt; ++i) {
        if (best_combination[i])
            printf("Item #%d, Value: %d, Weight: %d\n", i + 1, item_list->value[i], item_list->weight[i]);
    }
}

int main() {
    // Input barang dan batas berat secara dinamis
    ItemList item_list;
    int weight_limit;

    printf("Input data amount: ");
    scanf("%d", &(item_list.data_amt));

    item_list.value = (int*) malloc(item_list.data_amt * sizeof(int));
    item_list.weight = (int*) malloc(item_list.data_amt * sizeof(int));

    for (int i = 0; i < item_list.data_amt; ++i) {
        printf("\nInput item #%d value: ", i + 1);
        scanf("%d", &(item_list.value[i]));
        printf("Input item #%d weight: ", i + 1);
        scanf("%d", &(item_list.weight[i]));
    }

    printf("\nInput weight limit: ");
    scanf("%d", &weight_limit);

    // Selesaikan 0/1 knapsack problem
    print_knapsack(&item_list, weight_limit);

    return 0;
}