#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
using namespace std;

#define info_mahasiswa(P) (P)->info_mahasiswa
#define next_mahasiswa(P) (P)->next_mahasiswa
#define prec_mahasiswa(P) (P)->prec_mahasiswa
#define first_mahasiswa(L) (L).first_mahasiswa
#define matkul(P) (P)->matkul
#define mahasiswa(P) (P)->mahasiswa

// kumpulan tipe data bentukan dari mahasiswa
struct mahasiswa{
    char nim[15];
    string nama;
    string jurusan;
    string alamat;
    char no_telp[15];
};

// definisi pointer menunjuk elmList_mahasiswa
typedef struct elmList_mahasiswa *address_mahasiswa;

// kumpulan tipe data pointer dari elmList_mahasiswa
struct elmList_mahasiswa{
    mahasiswa info_mahasiswa;
    address_mahasiswa next_mahasiswa;
    address_mahasiswa prec_mahasiswa;
};

// kumpulan tipe data node dari List_mahasiswa
struct List_mahasiswa{
    address_mahasiswa first_mahasiswa;
};

// procedure & function
void createList_mahasiswa(List_mahasiswa &L);
address_mahasiswa alokasi_mahasiswa(mahasiswa x);
void dealokasi_mahasiswa(address_mahasiswa &P);
void insertFirst_mahasiswa(List_mahasiswa &L, address_mahasiswa P);
void insertLast_mahasiswa(List_mahasiswa &L, address_mahasiswa P);
address_mahasiswa findElm_mahasiswa(List_mahasiswa L, string x);
void deleteFirst_mahasiswa(List_mahasiswa &L, address_mahasiswa &P);
void deleteLast_mahasiswa(List_mahasiswa &L, address_mahasiswa &P);
void printInfo_mahasiswa(List_mahasiswa L);
void insertAfter_mahasiswa(address_mahasiswa Prec, address_mahasiswa P);
void deleteAfter_mahasiswa(address_mahasiswa Prec, address_mahasiswa &P);
void editInfo_mahasiswa(List_mahasiswa L, address_mahasiswa &P);
address_mahasiswa input_mahasiswa();
void deleteSearch_mahasiswa(List_mahasiswa &LP, address_mahasiswa &P);
void data_mahasiswa (List_mahasiswa &L);
void count_mahasiswa(List_mahasiswa L);

#endif // MAHASISWA_H_INCLUDED
