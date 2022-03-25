#include "relasi.h"

// membuat list relasi baru
void createList_relasi(List_relasi &L){
    first_relasi(L)=NULL;
}

// mendefinisikan ukuran memori pada elemen relasi
address_relasi alokasi_relasi(address_mahasiswa PP, address_matkul PB){
    address_relasi P = new elmList_relasi;
    matkull(P)= PB;
    mahasiswa(P)=PP;
    next_relasi(P)= NULL;
    return P;
}

// menghapus ukuran memori pada elemen relasi
void dealokasi_relasi(address_relasi &P){
    delete P;
}

// menginput data relasi pada awal list
void insertFirst_relasi(List_relasi &L, address_relasi P){
    if(first_relasi(L)==NULL){
        first_relasi(L)=P;
        next_relasi(first_relasi(L))=first_relasi(L);
        prev_relasi(first_relasi(L))=first_relasi(L);
    }
    else{
        address_relasi Q=prev_relasi(first_relasi(L));
        if(next_relasi(first_relasi(L))==first_relasi(L)){
            next_relasi(P)=first_relasi(L);
            prev_relasi(P)=Q;
            next_relasi(Q)=P;
            prev_relasi(Q)=P;
            first_relasi(L)=P;
        }
        else{
            next_relasi(P)=first_relasi(L);
            prev_relasi(P)=Q;
            prev_relasi(first_relasi(L))=P;
            next_relasi(Q)=P;
            first_relasi(L)=P;
        }
    }
}

// menginput data relasi pada akhir list
void insertLast_relasi(List_relasi &L, address_relasi P){
    if(first_relasi(L)==NULL){
        first_relasi(L)=P;
        next_relasi(first_relasi(L))=first_relasi(L);
        prev_relasi(first_relasi(L))=first_relasi(L);
    }
    else{
        address_relasi Q=prev_relasi(first_relasi(L));
        prev_relasi(P)=Q;
        prev_relasi(first_relasi(L))=P;
        next_relasi(P)=first_relasi(L);
        next_relasi(Q)=P;
    }
}

// mengecek data relasi pada list
address_relasi findElm_relasi(List_relasi L, address_mahasiswa PP, address_matkul PB){
    address_relasi P = first_relasi(L);
    bool found = false;
    if (first_relasi(L) != NULL){
        while ((next_relasi(P)!=NULL)&&(found == false)){
            if (mahasiswa(P) == PP&& matkull(P) == PB){
                found = true;
                return P;
            }else{
                P=next_relasi(P);
            }
        }
    }
    else{
        P=NULL;
    }
    return P;
}

// menghapus data relasi pada awal list
void deleteFirst_relasi(List_relasi &L, address_relasi &P){
    if(first_relasi(L)!=NULL){
        P=first_relasi(L);
        if(next_relasi(first_relasi(L))==first_relasi(L)){
            first_relasi(L)=NULL;
        }
        else{
            address_relasi Q=prev_relasi(first_relasi(L));
            first_relasi(L)=next_relasi(P);
            prev_relasi(first_relasi(L))=Q;
            next_relasi(Q)=first_relasi(L);
            next_relasi(P)=NULL;
            prev_relasi(P)=NULL;
        }
    }
    else{
        cout<<"Data kosong"<<endl;
    }
}

// menghapus data relasi pada akhir list
void deleteLast_relasi(List_relasi &L, address_relasi &P){
        if(first_relasi(L)!=NULL){
        if(next_relasi(first_relasi(L))==first_relasi(L)){
            P=first_relasi(L);
            createList_relasi(L);
        }
        else{
            address_relasi Q=prev_relasi(prev_relasi(first_relasi(L)));
            P=next_relasi(Q);
            next_relasi(Q)=first_relasi(L);
            prev_relasi(first_relasi(L))=Q;
            next_relasi(P)=NULL;
            prev_relasi(P)=NULL;
        }
    }
    else{
        cout<<"Data kosong"<<endl;
    }
}

// menampilkan data relasi pada list
void print_relasi(List_relasi L){
    address_relasi P;
    if (first_relasi(L) == NULL){
        cout << "                                                   Daftar Matkul Yang Diambil Mahasiswa                                                    " << endl;
        cout << "==========================================================================================================================================" << endl;
        cout<<endl;
        cout<<"\t      Belum Ada Mahasiswa Yang Meminjam matkul\n"<<endl;
    }
    else{
        cout << "                                                   Daftar Matkul Yang Diambil Mahasiswa                                                    " << endl;
        cout << " " << endl;
        cout << "==========================================================================================================================================" << endl;
        cout << "|         NIM          |           Nama           |           Jurusan             |       ID matkul        |           Nama matkul           |" << endl;
        cout << "==========================================================================================================================================" << endl;
        P = first_relasi(L);
        while (next_relasi(P) != first_relasi(L)){
            cout.setf(ios::left|ios::showpoint);
            cout << "|";
            cout.width(22);
            cout<<info_mahasiswa(mahasiswa(P)).nim;
            cout << "|";
            cout.width(26);
            cout<<info_mahasiswa(mahasiswa(P)).nama;
            cout << "|";
            cout.width(31);
            cout<<info_mahasiswa(mahasiswa(P)).jurusan;
            cout << "|";
            cout.width(22);
            cout<<info_matkul(matkull(P)).id_matkul;
            cout << "|";
            cout.width(31);
            cout<<info_matkul(matkull(P)).nama_matkul;
            cout << "|\n";
            cout<<endl;

            P = next_relasi(P);
        }
            cout << "|";
            cout.width(22);
            cout<<info_mahasiswa(mahasiswa(P)).nim;
            cout << "|";
            cout.width(26);
            cout<<info_mahasiswa(mahasiswa(P)).nama;
            cout << "|";
            cout.width(31);
            cout<<info_mahasiswa(mahasiswa(P)).jurusan;
            cout << "|";
            cout.width(22);
            cout<<info_matkul(matkull(P)).id_matkul;
            cout << "|";
            cout.width(31);
            cout<<info_matkul(matkull(P)).nama_matkul;
            cout << "|\n";
            cout<<endl;
    }
}

// menginput data relasi pada setelah pointer pada list
void insertAfter_relasi(List_relasi &L, address_relasi prec, address_relasi &P){
    if (first_relasi(L) == NULL){
        first_relasi(L) = P;
     }
     else{
         next_relasi(P) = next_relasi(prec);
         next_relasi(prec) = P;
     }
}

// menghapus data relasi pada setelah pointer pada list
void deleteAfter_relasi(address_relasi Prec, address_relasi &P){
    P=next_relasi(Prec);
    prev_relasi(next_relasi(P))=prev_relasi(P);
    next_relasi(Prec)=next_relasi(P);
    next_relasi(P)=NULL;
    prev_relasi(P)=NULL;
}

// menghapus data relasi
void delete_relasi(List_relasi &L, address_relasi &P){
    address_relasi Q, Prec;
    if(P!=NULL){
        Q=first_relasi(L);
        do{
            Q=next_relasi(Q);
        }while (next_relasi(Q)!= first_relasi(L));
        if(P==first_relasi(L)){
             if(next_relasi(P)==first_relasi(L)){
                first_relasi(L)=NULL;
            }
            else{
                deleteFirst_relasi(L, P);
            }
        }
        else if(P==Q){
            deleteLast_relasi(L, P);
        }
        else{
            Prec = prev_relasi(P);
            deleteAfter_relasi(Prec, P);
        }
    }
}

// menghapus data relasi sesuai element yg dicari
void deleteSearch_relasi(List_relasi &L, address_relasi &P){
    address_relasi Q, Prec;
    if(P!=NULL){
        Q=first_relasi(L);
        while (next_relasi(Q)!= first_relasi(L)){
            Q=next_relasi(Q);
        }
        Q=next_relasi(Q);
        if(P==first_relasi(L)){
            if(next_relasi(P)==first_relasi(L)){
                first_relasi(L)=NULL;
            }
            else{
                deleteFirst_relasi(L, P);
                P=first_relasi(L);
            }
        }
        else if(P==Q){
            deleteLast_relasi(L, P);
            P=Q;
        }
        else{
            Prec = prev_relasi(P);
            deleteAfter_relasi(Prec, P);
            P=Prec;
        }
    }
}

// menghapus data mahasiswa
void delete_mahasiswa(List_relasi &LR, List_mahasiswa &LP, address_mahasiswa &PP){
    address_relasi P=first_relasi(LR);
    if(first_relasi(LR)!=NULL){
       do{
            if(mahasiswa(P)==PP){
                deleteSearch_relasi(LR, P);
            }
            P=next_relasi(P);
        } while(next_relasi(P)!=first_relasi(LR));
        if(mahasiswa(P)==PP){
            deleteSearch_relasi(LR, P);
        }
    }
    deleteSearch_mahasiswa(LP, PP);

}

// menghapus data matkul
void delete_matkul(List_relasi &LR, List_matkul &LB, address_matkul &PB){
    address_relasi P=first_relasi(LR);
    if(first_relasi(LR)!=NULL){
        do{
            if(matkull(P)==PB){
                deleteSearch_relasi(LR, P);
            }
            P=next_relasi(P);
        }while(next_relasi(P)!=first_relasi(LR));
        if(matkull(P)==PB){
            deleteSearch_relasi(LR, P);
        }
    }

    deleteSearch_matkul(LB, PB);
}

// menginput data relasi mahasiswa dan matkul
void input_relasi(List_mahasiswa LP, List_matkul LB, List_relasi &LR){
    address_mahasiswa PP;
    address_matkul PB;
    address_relasi PR;

    mahasiswa pdicari;
    matkul bdicari;
    printInfo_mahasiswa(LP);

    cout<<"Masukkan Nim Anda : ";
    cin.ignore();
    cin>>pdicari.nim;
    cin.ignore();
    PP=findElm_mahasiswa(LP,pdicari.nim);
    if (PB!=NULL){
        system("cls");
        printInfo_matkul(LB);
        cout<<"Masukkan Nim Anda : "<<pdicari.nim<<endl;
        cout<<"Id matkul Yang Ingin Diambil : ";
        cin>>bdicari.id_matkul;
        cin.ignore();
        PB=findElm_matkul(LB, bdicari.id_matkul);
        if (PB!=NULL){
            PR=alokasi_relasi(PP,PB);
            insertLast_relasi(LR,PR);
            cout<<endl;
            cout<<"Mahasiswa Berhasil Registrasi Matkul"<<endl;
        }
        else{
            cout<<endl;
            cout<<"matkul Tesebut Tidak Tersedia"<<endl;
        }
    }
    else{
        cout<<"Data Mahasiswa tidak ditemukan"<<endl;
    }
}

// mengecek data relasi pada list
address_relasi find_relasi(List_relasi L, string x, string y){
    bool cek;
    address_relasi P;
    if(first_relasi(L)!=NULL){
        cek=false;
        P=first_relasi(L);
        while((cek==false)&&(next_relasi(P)!=first_relasi(L))){
            if(info_mahasiswa(mahasiswa(P)).nim == x){
                if(info_matkul(matkull(P)).id_matkul == y){
                    cek=true;
                    return P;
                }
            }
            else{
                P=next_relasi(P);
            }
        }
        if (cek == false){
            if(info_mahasiswa(mahasiswa(P)).nim == x){
                if(info_matkul(matkull(P)).id_matkul == y){
                    cek=true;
                }
            }
        }
    }
    if(cek!=true){
        return P=NULL;
    }
    return P;
}

// mencari data relasi mahasiswa dengan matkul
void search_mahasiswa(List_mahasiswa LP, List_relasi LR, address_mahasiswa PP){
    address_relasi PR=first_relasi(LR);
    int i=0;
    while (next_relasi(PR) != first_relasi(LR)){
        if(info_mahasiswa(PP).nama == info_mahasiswa(mahasiswa(PR)).nama){
            i++;
            cout<<"Matkul Yang Diambil Ke-"<<i<<" : "<<info_matkul(matkull(PR)).nama_matkul<<endl;
        }
        PR = next_relasi(PR);
    }
    if(info_mahasiswa(PP).nama == info_mahasiswa(mahasiswa(PR)).nama){
            i++;
            cout<<"Matkul Yang Diambil Ke-"<<i<<" : "<<info_matkul(matkull(PR)).nama_matkul<<endl;
        }
    if(i==0){
        cout<<"Mahasiswa Ini Tidak Mengambil matkul"<<endl;
    }
}

// mencari data relasi matkul dengan mahasiswa
void search_matkul(List_matkul LB, List_relasi LR, address_matkul PB){
    address_relasi PR=first_relasi(LR);
    int i=0;
    while (next_relasi(PR) != first_relasi(LR)){
        if(info_matkul(PB).nama_matkul == info_matkul(matkull(PR)).nama_matkul){
            i++;
            cout<<i<<". "<<info_mahasiswa(mahasiswa(PR)).nama<< "( "  <<info_mahasiswa(mahasiswa(PR)).nim<< " )" << endl;
        }
        PR = next_relasi(PR);
    }
    if(info_matkul(PB).nama_matkul == info_matkul(matkull(PR)).nama_matkul){
            i++;
            cout<<i<<". "<<info_mahasiswa(mahasiswa(PR)).nama<<  "( "  <<info_mahasiswa(mahasiswa(PR)).nim<< " )" << endl;
    }
    if(i==0){
        cout<<"Belum Ada mahasiswa Yang Meminjam matkul Ini"<<endl;
    }
}

// deklarasi variable
void data_relasi (List_relasi &L, List_mahasiswa LP, List_matkul LB){
    address_relasi P;
    address_mahasiswa PP;
    address_matkul PB;
}

// tampilan menu
void menu (List_mahasiswa LP, List_matkul LB, List_relasi LR) {
    int pil;
    mahasiswa pdicari;
    matkul bdicari;
    address_mahasiswa PP;
    address_matkul PB;
    address_relasi PR;
    data_mahasiswa (LP);
    data_matkul (LB);
    data_relasi(LR, LP, LB);
    do {
        system("cls");
        cout << "Kelompok 3" << endl;
        cout << "Anggota : Muhammad Rafi Alfarisi      (1302194024)" << endl;
        cout << "          Leonardho R Sitanggang      (1302194041)" << endl;
        cout << " " << endl;
        cout << "==================================================" << endl;
        cout << "     Igracias Telkom University      " << endl;
        cout << "==================================================" << endl;
        cout << " -- INSERT -- " << endl;
        cout << "1.  Input Data Mahasiswa" << endl;
        cout << "2.  Input Data Matkul" << endl;
        cout << "3.  Input Data Registrasi Matkul" << endl;
        cout << " " << endl;

        cout << " -- UPDATE -- " << endl;
        cout << "4.  Ubah Data Mahasiswa" << endl;
        cout << "5.  Ubah Data Matkul" << endl;
        cout << " " << endl;

        cout << " -- SHOW -- " << endl;
        cout << "6.  Lihat Data Mahasiswa" << endl;
        cout << "7.  Lihat Data Matkul" << endl;
        cout << "8.  Lihat Data Registrasi Matkul" << endl;
        cout << " " << endl;

        cout << " -- DELETE -- " << endl;
        cout << "9.  Hapus Data Mahasiswa" << endl;
        cout << "10. Hapus Data matkul" << endl;
        cout << "11. Hapus Data Registrasi Matkul" << endl;
        cout << " " << endl;

        cout << " -- FIND -- " << endl;
        cout << "12. Cari Data Mahasiswa Yang Mengambil Matkul" << endl;
        cout << "13. Cari Data Matkul Yang Diambil Mahasiswa" << endl;
        cout << " " << endl;

        cout << " -- COUNTING -- " << endl;
        cout << "14. Menghitung Jumlah Mahasiswa Yang Mengambil Matkul" << endl;
        cout << "15. Menghitung Jumlah Matkul Yang Terdaftar" << endl;
        cout << " " << endl;

        cout<<endl;
        cout << "0.  Exit " << endl;
        cout<<endl;
        cout << "Masukkan Pilihan : ";
        cin >> pil;
            switch(pil){
        case 1:
            system("CLS");
            cout << "               Input Data Mahasiswa               " << endl;
            cout << "==================================================" << endl;
            PP=input_mahasiswa();
            insertLast_mahasiswa(LP,PP);
            cout<<endl;
            cout<<"Mahasiswa Baru Berhasil terdaftar"<<endl;
            cout<<endl;
            system("pause");
            break;

        case 2:
            system("CLS");
            cout << "                  Input Data Matkul               " << endl;
            cout << "==================================================" << endl;
            PB=input_matkul();
            insertLast_matkul(LB,PB);
            cout<<endl;
            cout<<"matkul Berhasil ditambahkan"<<endl;
            cout<<endl;
            system("pause");
            break;

        case 3:
            system("cls");
            input_relasi(LP,LB,LR);
            cout<<endl;
            system("pause");
            break;

        case 4:
            system("Cls");
            printInfo_mahasiswa(LP);
            cout<<"Masukkan Nim Yang Ingin Diubah: ";
            cin.ignore();
            cin>>pdicari.nim;
            cin.ignore();
            PP=findElm_mahasiswa(LP,pdicari.nim);
            if(PP!=NULL){
                cout<<"Data Mahasiswa Ditemukan"<<endl;
                system("PAUSE");
                system("CLS");
                editInfo_mahasiswa(LP,PP);
                cout<<"Data Mahasiswa Berhasil Diubah"<<endl;
            }
            else{
                cout<<"Data Mahasiswa Tidak Ditemukan"<<endl;
            }
            system("PAUSE");
            break;

        case 5:
            system("cls");
            printInfo_matkul(LB);
            cout<<"Masukkan Id Matkul Yang Ingin Diubah: ";
            cin.ignore();
            cin>>bdicari.id_matkul;
            cin.ignore();
            PB=findElm_matkul(LB,bdicari.id_matkul);
            if(PP!=NULL){
                cout<<"Data Matkul Ditemukan"<<endl;
                system("cls");
                editInfo_matkul(LB,PB);
                cout<<"Data matkul Berhasil Diubah"<<endl;
            }
            else{
                cout<<"Tidak Ada Data matkul Tersebut"<<endl;
            }
            system("pause");
            break;

        case 6:
            system("CLS");
            printInfo_mahasiswa(LP);
            system("PAUSE");
            break;

        case 7:
            system("CLS");
            printInfo_matkul(LB);
            system("PAUSE");
            break;

        case 8:
            system("cls");
            print_relasi(LR);
            system("PAUSE");
            break;

        case 9:
            system("Cls");
            printInfo_mahasiswa(LP);
            cout<<"Masukkan Nim Mahasiswa Yang Ingin Dihapus: ";
            cin.ignore();
            cin>>pdicari.nim;
            cin.ignore();
            PP=findElm_mahasiswa(LP,pdicari.nim);
            if(PP!=NULL){
                delete_mahasiswa(LR, LP, PP);
                cout<<endl;
                cout<<"Data Mahasiswa Berhasil Dihapus"<<endl;
                cout<<endl;
            }
            else{
                cout<<endl;
                cout<<"Data Mahasiswa Tidak Ditemukan"<<endl;
                cout<<endl;
            }
            system("PAUSE");
            break;

        case 10:
            system("cls");
            printInfo_matkul(LB);
            cout<<"Masukkan Id Matkul Yang Ingin Dihapus: ";
            cin.ignore();
            cin>>bdicari.id_matkul;
            cin.ignore();
            PB=findElm_matkul(LB,bdicari.id_matkul);
            if(PB!=NULL){
                delete_matkul(LR,LB, PB);
                cout<<endl;
                cout<<"Data matkul Berhasil Dihapus"<<endl;
                cout<<endl;
            }
            else{
                cout<<endl;
                cout<<"Data matkul tidak Ditemukan"<<endl;
                cout<<endl;
            }
            system("PAUSE");
            break;

        case 11:
            system("cls");
            print_relasi(LR);
            cout<<"Masukkan Nim Mahasiswa Yang Ingin Dihapus: ";
            cin.ignore();
            cin>>pdicari.nim;
            cin.ignore();
            cout<<"Masukkan Id matkul Yang Ingin Dihapus: ";
            cin>>bdicari.id_matkul;
            cin.ignore();
            PR = find_relasi(LR, pdicari.nim, bdicari.id_matkul);
            if(PR != NULL){
                delete_relasi(LR, PR);
                cout<<"Data mahasiswa Berhasil Dihapus"<<endl;
            }
            else{
                cout<<"Data mahasiswa Tidak Ditemukan"<<endl;
            }
            system("pause");
            break;

        case 12:
            system("cls");
            printInfo_mahasiswa(LP);
            cout<<"Masukkan Nim Mahasiswa Yang Dicari: ";
            cin.ignore();
            cin>>pdicari.nim;
            cin.ignore();
            PP=findElm_mahasiswa(LP, pdicari.nim);
            if(PP!=NULL){
                cout<<endl;
                search_mahasiswa(LP, LR, PP);
                cout<<endl;
            }
            else{
                cout<<"\Mahasiswa tidak ditemukan\n"<<endl;
            }
            system("pause");
            break;

        case 13:
            system("cls");
            printInfo_matkul(LB);
            cout<<"Masukkan Id Matkul Yang Dicari: ";
            cin.ignore();
            cin>>bdicari.id_matkul;
            cin.ignore();
            PB=findElm_matkul(LB, bdicari.id_matkul);
            if(PP!=NULL){
                cout<<endl;
                cout<<"mahasiswa Yang Registrasi matkul "<<bdicari.nama_matkul<<" : "<<endl;
                search_matkul(LB, LR, PB);
                cout<<endl;
            }
            else{
                cout<<"\nmatkul tidak ditemukan\n"<<endl;
            }
            system("pause");
            break;

        case 14:
            system("cls");
            count_mahasiswa(LP);
            system("pause");
            break;

        case 15:
            system("cls");
            count_matkul(LB);
            system("pause");
            break;

        case 0:
            cout<<"\nTerima Kasih Telah Menggunakan Igracias Telkom University\n"<<endl;
            system("PAUSE");
            break;
        default:
            cout<<endl;
            cout << "Angka yang anda masukkan salah, silahkan masukkan angka dari 0-13" << endl;
            cout<<endl;
            system("PAUSE");
            break;
        }
    }while (pil!=0);
}
