#include <stdio.h>
#include "tampil.h"

void tampilkanData(KotaNode *head) {
    KotaNode *temp = head;
    while (temp != NULL) {
        system("cls");
        printf("Kota: %s\n", temp->kt);

        NamaNode *curr = temp->p;
        while (curr != NULL) {
            printf("  - %s\n", curr->nama);
            curr = curr->next;
        }
        temp = temp->next;
    }
}

void tampilkanKotaTertentu(KotaNode *head) {
    if (head == NULL) {
        printf("Belum ada kota yang tersedia.\n");
        return;
    }

    char namaKota[MAX_STRING];
    printf("Masukkan nama kota yang ingin ditampilkan: ");
    scanf(" %[^\n]", namaKota);

    KotaNode *temp = head;
    while (temp != NULL && strcasecmp(temp->kt, namaKota) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Kota tidak ditemukan!\n");
        return;
    }

    printf("Kota: %s\n", temp->kt);
    NamaNode *curr = temp->p;
    while (curr != NULL) {
        printf("  - %s\n", curr->nama);
        curr = curr->next;
    }
}

