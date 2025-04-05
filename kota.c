#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kota.h"

void tambahKota(KotaNode **head) {
    KotaNode *newNode = (KotaNode *)malloc(sizeof(KotaNode));
    if (newNode == NULL) {
        printf("Gagal menambahkan kota!\n");
        return;
    }

    printf("Masukkan nama kota: ");
    scanf(" %[^\n]", newNode->kt);
    newNode->p = NULL;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        KotaNode *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    system("cls");
    printf("Kota berhasil ditambahkan!\n");
}

void hapusKota(KotaNode **head) {
    if (*head == NULL) {
        printf("Belum ada kota yang tersimpan.\n");
        return;
    }

    char namaKota[MAX_STRING];
    printf("Masukkan nama kota yang akan dihapus: ");
    scanf(" %[^\n]", namaKota);

    KotaNode *temp = *head;
    while (temp != NULL && strcasecmp(temp->kt, namaKota) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Kota tidak ditemukan!\n");
        return;
    }

    // Hapus semua nama dalam kota tersebut
    NamaNode *curr = temp->p;
    while (curr != NULL) {
        NamaNode *toDelete = curr;
        curr = curr->next;
        free(toDelete);
    }

    // Hapus kota dari linked list
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    system("cls");
    printf("Kota dan semua data nama berhasil dihapus!\n");
}

