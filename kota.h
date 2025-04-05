#ifndef KOTA_H
#define KOTA_H

#include "boolean.h"

#define MAX_STRING 50

typedef struct NamaNode {
    char nama[MAX_STRING];
    struct NamaNode *prev;
    struct NamaNode *next;
} NamaNode;

typedef struct KotaNode {
    char kt[MAX_STRING];
    struct KotaNode *prev;
    struct KotaNode *next;
    NamaNode *p;
} KotaNode;

void tambahKota(KotaNode **head);
void hapusKota(KotaNode **head);
#endif

