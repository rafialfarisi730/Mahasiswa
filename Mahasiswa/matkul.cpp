#include "matkul.h"

// membuat list matkul baru
void createList_matkul(List_matkul &L){
    first_matkul(L)=NULL;
}

// mendefinisikan ukuran memori pada elemen matkul
address_matkul alokasi_matkul(matkul x){
    address_matkul P=new elmList_matkul;
    info_matkul(P)=x;
    next_matkul(P)=NULL;
    prev_matkul(P)=NULL;
    return P;
}

// menghapus ukuran memori pada elemen matkul
void dealokasi_matkul(address_matkul &P){
    delete P;
}

// menginput data matkul pada awal list
void insertFirst_matkul(List_matkul &L, address_matkul P){
    address_matkul Q;
    if(first_matkul(L)==NULL){
        first_matkul(L)=P;
        next_matkul(P)=first_matkul(L);
    }
    else{
        Q=first_matkul(L);
        while(next_matkul(Q)!=first_matkul(L)){
            Q=next_matkul(Q);
        }
        next_matkul(P)=first_matkul(L);
        first_matkul(L)=P;
        prev_matkul(first_matkul(L))=P;
        next_matkul(Q)=P;
        prev_matkul(P)=Q;
    }
}

// menginput data matkul pada akhir list
void insertLast_matkul(List_matkul &L, address_matkul P){
    address_matkul Q;
    if(first_matkul(L)==NULL){
        first_matkul(L)=P;
        next_matkul(P)=first_matkul(L);
    }
    else{
        Q=first_matkul(L);
        while(next_matkul(Q)!=first_matkul(L)){
            Q=next_matkul(Q);
        }
        next_matkul(Q)=P;
        next_matkul(P)=first_matkul(L);
        prev_matkul(P)=Q;
        prev_matkul(first_matkul(L))=P;
    }
}

// mengecek data matkul pada list
address_matkul findElm_matkul(List_matkul L, string x){
    bool cek;
    address_matkul P;

    if(first_matkul(L)!=NULL){
        cek=false;
        P=first_matkul(L);

        while((cek==false)&&(next_matkul(P)!=first_matkul(L))){
            if(info_matkul(P).id_matkul == x){
                cek=true;
            }
            else{
                P=next_matkul(P);
            }
        }

        if (cek == false){
            if(info_matkul(P).id_matkul == x){
                cek=true;
            }
        }
    }

    if(cek==false){
        return P=NULL;
    }
    return P;
}

// menghapus data matkul pada awal list
void deleteFirst_matkul(List_matkul &L, address_matkul &P){
    address_matkul Q;
    if(first_matkul(L)!=NULL){
        Q=first_matkul(L);
        while(next_matkul(Q)!=first_matkul(L)){
            Q=next_matkul(Q);
        }
        P=first_matkul(L);
        first_matkul(L)=next_matkul(first_matkul(L));
        next_matkul(P)=NULL;
        prev_matkul(first_matkul(L))=Q;
        next_matkul(Q)=first_matkul(L);
    }
}

// menghapus data matkul pada akhir list
void deleteLast_matkul(List_matkul &L, address_matkul &P){
    address_matkul Prec;
    if(first_matkul(L)!=NULL){
        P=first_matkul(L);
        do{
            Prec=P;
            P=next_matkul(P);
        }while(next_matkul(P)!=first_matkul(L));
        next_matkul(Prec)=first_matkul(L);
        prev_matkul(first_matkul(L))=Prec;
    }
}

// menghapus data matkul sesuai element yg dicari
void deleteSearch_matkul(List_matkul &L, address_matkul &P){
    address_matkul Q, Prec;
    Q=first_matkul(L);
    do{
        Q=next_matkul(Q);
    }while (next_matkul(Q)!=first_matkul(L));
    if(P!=NULL){
        if(P==first_matkul(L)){
            if(next_matkul(P)==first_matkul(L)){
                first_matkul(L)=NULL;
            }
            else{
                deleteFirst_matkul(L, P);
            }
        }else if(P==Q){
            deleteLast_matkul(L, P);
           }else{
            Prec = prev_matkul(P);
            deleteAfter_matkul(Prec, P);
        }
    }

}

// menampilkan data matkul pada list
void printInfo_matkul(List_matkul L){
    address_matkul P;

    if(first_matkul(L)==NULL){
        cout << "                                    Daftar Matkul                                    " << endl;
        cout << "===================================================================================" << endl;
        cout<<endl;
        cout<<"\t\t  Belum Ada matkul yang Terdaftar\n"<<endl;
    }
    else{
        system("cls");
        cout << "                                  Daftar matkul                                    " << endl;
        cout << " " << endl;
        cout << "===================================================================================" << endl;
        cout << "|       ID matkul        |           Nama matkul           |      Kode Dosen      |" << endl;
        cout << "===================================================================================" << endl;
        P=first_matkul(L);
        while(next_matkul(P)!=first_matkul(L)){
            cout.setf(ios::left|ios::showpoint);
            cout << "|";
            cout.width(22);
            cout<<info_matkul(P).id_matkul;
            cout << "|";
            cout.width(31);
            cout<<info_matkul(P).nama_matkul;
            cout << "|";
            cout.width(26);
            cout<<info_matkul(P).kode_dosen;
            cout << "|\n";
            cout<<endl;
            P=next_matkul(P);
        }
            cout.setf(ios::left|ios::showpoint);
            cout << "|";
            cout.width(22);
            cout<<info_matkul(P).id_matkul;
            cout << "|";
            cout.width(31);
            cout<<info_matkul(P).nama_matkul;
            cout << "|";
            cout.width(26);
            cout<<info_matkul(P).kode_dosen;
            cout << "|\n";
            cout<<endl;
            P=next_matkul(P);
            cout<<"\n\n";
    }
}

// menginput data matkul pada setelah pointer pada list
void insertAfter_matkul(address_matkul Prec, address_matkul P){
        next_matkul(P)=next_matkul(Prec);
        prev_matkul(next_matkul(Prec))=P;
        next_matkul(Prec)=P;
        prev_matkul(P)=Prec;
}

// menghapus data matkul pada setelah pointer pada list
void deleteAfter_matkul(address_matkul Prec, address_matkul &P){
        P=next_matkul(Prec);
        prev_matkul(next_matkul(P))=next_matkul(P);
        next_matkul(Prec)=next_matkul(P);
        next_matkul(P)=NULL;
        prev_matkul(P)=NULL;
}

// tampilan edit matkul
void editInfo_matkul(List_matkul L, address_matkul &P){
    cout<<"ID matkul \t\t: ";
    cin>>info_matkul(P).id_matkul;
    cin.ignore();
    cout<<"Nama matkul \t\t: ";
    getline(cin,info_matkul(P).nama_matkul);
    cout<<"Kode Dosen  \t\t: ";
    cin>>info_matkul(P).kode_dosen;
}

// tampilan tambah matkul
address_matkul input_matkul(){
    matkul x;
    cout<<"ID matkul \t\t: ";
    cin>>x.id_matkul;
    cin.ignore();
    cout<<"Nama matkul \t\t: ";
    getline(cin,x.nama_matkul);
    cout<<"Kode Dosen \t\t: ";
    cin>>x.kode_dosen;

    return alokasi_matkul(x);
}

// deklarasi variable
void data_matkul (List_matkul L){
    matkul matkul;
    address_matkul P;
}

// menghitung jumlah matkul
void count_matkul(List_matkul L){
    address_matkul P;
    int count = 1;
    if(first_matkul(L)!=NULL){
        P=first_matkul(L);
        while(next_matkul(P)!=first_matkul(L)){
            count++;
            P=next_matkul(P);
        }
        cout << "Jumlah matkul: " << count << endl;
    } else {
        cout << "Data masih kosong" << endl;
    }
}
