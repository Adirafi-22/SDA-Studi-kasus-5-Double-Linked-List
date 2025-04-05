#include "kota.h"
#include "nama.h"
#include "tampil.h"
#include <stdio.h>

int main() {
    KotaNode *head = NULL;
    int pilihan;

    do {
        printf("\nMenu:\n");
        printf("1. Tambah Kota\n");
        printf("2. Hapus Kota\n");
        printf("3. Tambah Nama\n");
        printf("4. Hapus Nama\n");
        printf("5. Tampilkan Data\n");
        printf("6. Tampilkan Kota Tertentu\n");
        printf("7. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: tambahKota(&head); break;
            case 2: hapusKota(&head); break;
            case 3: tambahNama(head); break;
            case 4: hapusNama(head); break;
            case 5: tampilkanData(head); break;
            case 6: tampilkanKotaTertentu(head); break;
        }
    } while (pilihan != 7);

    return 0;
}

