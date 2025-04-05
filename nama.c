#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nama.h"

void tambahNama(KotaNode *head) {
    if (head == NULL) {
        printf("Belum ada kota yang tersedia.\n");
        return;
    }

    char namaKota[MAX_STRING], namaOrang[MAX_STRING];
    printf("Masukkan nama kota: ");
    scanf(" %[^\n]", namaKota);

    KotaNode *temp = head;
    while (temp != NULL && strcasecmp(temp->kt, namaKota) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Kota tidak ditemukan!\n");
        return;
    }

    printf("Masukkan nama orang: ");
    scanf(" %[^\n]", namaOrang);

    NamaNode *newNode = (NamaNode *)malloc(sizeof(NamaNode));
    strcpy(newNode->nama, namaOrang);
    newNode->next = NULL;
    newNode->prev = NULL;

    if (temp->p == NULL) {
        temp->p = newNode;
    } else {
        NamaNode *curr = temp->p;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->prev = curr;
    }

    system("cls");
    printf("Nama berhasil ditambahkan!\n");
}

void hapusNama(KotaNode *head) {
    if (head == NULL) {
        printf("Belum ada kota yang tersedia.\n");
        return;
    }

    char namaKota[MAX_STRING], namaOrang[MAX_STRING];
    printf("Masukkan nama kota: ");
    scanf(" %[^\n]", namaKota);

    KotaNode *temp = head;
    while (temp != NULL && strcasecmp(temp->kt, namaKota) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Kota tidak ditemukan!\n");
        return;
    }

    printf("Masukkan nama orang yang akan dihapus: ");
    scanf(" %[^\n]", namaOrang);

    NamaNode *curr = temp->p;
    while (curr != NULL && strcasecmp(curr->nama, namaOrang) != 0) {
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Nama tidak ditemukan di kota ini.\n");
        return;
    }

    if (curr->prev != NULL) {
        curr->prev->next = curr->next;
    } else {
        temp->p = curr->next;
    }

    if (curr->next != NULL) {
        curr->next->prev = curr->prev;
    }

    free(curr);
    system("cls");
    printf("Nama berhasil dihapus!\n");
}

