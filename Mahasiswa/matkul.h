#ifndef MATKUL_H_INCLUDED
#define MATKUL_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
using namespace std;

#define info_matkul(P) (P)->info_matkul
#define next_matkul(P) (P)->next_matkul
#define prev_matkul(P) (P)->prev_matkul
#define first_matkul(L) (L).first_matkul
#define matkull(P) (P)->matkull

// kumpulan tipe data bentukan dari matkul
struct matkul{
    char id_matkul[15];
    string nama_matkul;
    string kode_dosen;
};

// definisi pointer menunjuk elmList_matkul
typedef struct elmList_matkul *address_matkul;

// kumpulan tipe data pointer dari elmList_matkul
struct elmList_matkul{
    matkul info_matkul;
    address_matkul next_matkul;
    address_matkul prev_matkul;
};

// kumpulan tipe data node dari List_matkul
struct List_matkul{
    address_matkul first_matkul;
};

// procedure & function
void createList_matkul(List_matkul &L);
address_matkul alokasi_matkul(matkul x);
void dealokasi_matkul(address_matkul &P);
void insertFirst_matkul(List_matkul &L, address_matkul P);
void insertLast_matkul(List_matkul &L, address_matkul P);
address_matkul findElm_matkul(List_matkul L, string x);
void deleteFirst_matkul(List_matkul &L, address_matkul &P);
void deleteLast_matkul(List_matkul &L, address_matkul &P);
void printInfo_matkul(List_matkul L);
void insertAfter_matkul(address_matkul Prec, address_matkul P);
void deleteAfter_matkul(address_matkul Prec, address_matkul &P);
address_matkul input_matkul();
void editInfo_matkul(List_matkul L, address_matkul &P);
void data_matkul (List_matkul   L);
void deleteSearch_matkul(List_matkul &L, address_matkul &P);
void count_matkul(List_matkul L);

#endif // MATKUL_H_INCLUDED
