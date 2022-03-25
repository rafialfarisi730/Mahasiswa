#include <iostream>
#include "relasi.h"

using namespace std;

int main()
{
    List_mahasiswa LP;
    List_matkul LB;
    List_relasi LR;
    address_mahasiswa PP;
    address_matkul PB;
    address_relasi PR;
    createList_mahasiswa(LP);
    createList_matkul(LB);
    createList_relasi(LR);
    menu(LP,LB,LR);

    return 0;
}
