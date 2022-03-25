#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "mahasiswa.h"
#include "matkul.h"
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <iostream>
using namespace std;

#define next_relasi(P) (P)->next_relasi
#define prev_relasi(P) (P)->prev_relasi
#define first_relasi(L) (L).first_relasi

// definisi pointer menunjuk elmList_relasi
typedef struct elmList_relasi *address_relasi;

// kumpulan tipe data pointer dari elmList_relasi
struct elmList_relasi{
    address_relasi next_relasi;
    address_relasi prev_relasi;
    address_matkul matkull;
    address_mahasiswa mahasiswa;
};

// kumpulan tipe data node dari List_relasi
struct List_relasi{
    address_relasi first_relasi;
};

// procedure & function
void createList_relasi(List_relasi &L);
address_relasi alokasi_relasi();
void dealokasi_relasi(address_relasi &P);
void insertFirst_relasi(List_relasi &L, address_relasi P);
void insertLast_relasi(List_relasi &L, address_relasi P);
address_relasi find_relasi(List_relasi L, string x, string y);
void deleteFirst(List_relasi &L, address_relasi &P);
void deleteLast(List_relasi &L, address_relasi &P);
void print_relasi(List_relasi L);
void insertAfter_relasi(address_relasi Prec, address_relasi P);
void deleteAfter_relasi(address_relasi Prec, address_relasi &P);
void menu(List_mahasiswa LP, List_matkul LB, List_relasi LR);
void input_relasi(List_mahasiswa LP, List_matkul LB, List_relasi &LR);
void deleteSearch_relasi(List_relasi &L, address_relasi &P);
void delete_mahasiswa(List_relasi &LR, List_mahasiswa &LP, address_mahasiswa &PP);
void delete_matkul(List_relasi &LR, List_matkul &LB, address_matkul &PB);
void search_mahasiswa(List_mahasiswa LP, List_relasi LR, address_mahasiswa P);
void search_matkul(List_matkul LB, List_relasi LR, address_matkul PB);
void data_relasi (List_relasi &L, List_mahasiswa LP, List_matkul LB);
void delete_relasi(List_relasi &L, address_relasi &P);
void count_mahasiswa(List_mahasiswa L);

#endif // RELASI_H_INCLUDED
