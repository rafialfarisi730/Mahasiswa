#include "mahasiswa.h"

// membuat list mahasiswa baru
void createList_mahasiswa(List_mahasiswa &L){
    first_mahasiswa(L)=NULL;
}

// mendefinisikan ukuran memori pada elemen mahasiswa
address_mahasiswa alokasi_mahasiswa(mahasiswa x){
    address_mahasiswa P=new elmList_mahasiswa;
    info_mahasiswa(P)=x;
    next_mahasiswa(P)=NULL;
    prec_mahasiswa(P)=NULL;
}

// menghapus ukuran memori pada elemen mahasiswa
void dealokasi_mahasiswa(address_mahasiswa &P){
    delete P;
}

// menginput data mahasiswa pada awal list
void insertFirst_mahasiswa(List_mahasiswa &L, address_mahasiswa P){
    address_mahasiswa Q;
    if(first_mahasiswa(L)==NULL){
        first_mahasiswa(L)=P;
        next_mahasiswa(P)=first_mahasiswa(L);
    }
    else{
        Q=first_mahasiswa(L);
        while(next_mahasiswa(Q)!=first_mahasiswa(L)){
            Q=next_mahasiswa(Q);
        }
        next_mahasiswa(P)=first_mahasiswa(L);
        first_mahasiswa(L)=P;
        prec_mahasiswa(first_mahasiswa(L))=P;
        next_mahasiswa(Q)=P;
        prec_mahasiswa(P)=Q;
    }
}

// menginput data mahasiswa pada akhir list
void insertLast_mahasiswa(List_mahasiswa &L, address_mahasiswa P){
    address_mahasiswa Q;
    if(first_mahasiswa(L)==NULL){
        first_mahasiswa(L)=P;
        next_mahasiswa(P)=first_mahasiswa(L);
    }
    else{
        Q=first_mahasiswa(L);
        while(next_mahasiswa(Q)!=first_mahasiswa(L)){
            Q=next_mahasiswa(Q);
        }
        next_mahasiswa(Q)=P;
        next_mahasiswa(P)=first_mahasiswa(L);
        prec_mahasiswa(P)=Q;
        prec_mahasiswa(first_mahasiswa(L))=P;
    }
}

// mengecek data mahasiswa pada list
address_mahasiswa findElm_mahasiswa(List_mahasiswa L, string x){
    bool cek;
    address_mahasiswa P;
    if(first_mahasiswa(L)!=NULL){
        cek=false;
        P=first_mahasiswa(L);
        while((cek==false)&&(next_mahasiswa(P)!=first_mahasiswa(L))){
            if(info_mahasiswa(P).nim == x){
                cek=true;
            }
            else{
                P=next_mahasiswa(P);
            }
        }
        if (cek == false){
            if(info_mahasiswa(P).nim == x){
                cek=true;
            }
        }
    }
    if(cek!=true){
        return P=NULL;
    }
    return P;
}

// menghapus data mahasiswa pada awal list
void deleteFirst_mahasiswa(List_mahasiswa &L, address_mahasiswa &P){
    address_mahasiswa Q;
    if(first_mahasiswa(L)!=NULL){
        Q=first_mahasiswa(L);
        while(next_mahasiswa(Q)!=first_mahasiswa(L)){
            Q=next_mahasiswa(Q);
        }
        P=first_mahasiswa(L);
        first_mahasiswa(L)=next_mahasiswa(first_mahasiswa(L));
        next_mahasiswa(P)=NULL;
        prec_mahasiswa(first_mahasiswa(L))=Q;
        next_mahasiswa(Q)=first_mahasiswa(L);
    }
}

// menghapus data mahasiswa pada akhir list
void deleteLast_mahasiswa(List_mahasiswa &L, address_mahasiswa &P){
    address_mahasiswa Prec;
    if(first_mahasiswa(L)!=NULL){
        P=first_mahasiswa(L);
        do{
            Prec=P;
            P=next_mahasiswa(P);
        }while(next_mahasiswa(P)!=first_mahasiswa(L));
        next_mahasiswa(Prec)=first_mahasiswa(L);
        prec_mahasiswa(first_mahasiswa(L))=Prec;
    }
}

// menampilkan data mahasiswa pada list
void printInfo_mahasiswa(List_mahasiswa L){
    address_mahasiswa P;
    if(first_mahasiswa(L)==NULL){
        cout << "                                                          Data Mahasiswa                                                           " << endl;
        cout << "===================================================================================================================================" << endl;
        cout<<endl;
        cout<<"\t\t\t\t\tBelum Ada mahasiswa\n"<<endl;
    }
    else{
        cout << "                                                          Data Mahasiswa                                                           " << endl;
        cout << " " << endl;
        cout << "===================================================================================================================================" << endl;
        cout << "|         NIM          |           Nama           |           Jurusan             |            Alamat             |    No.Telp    |" << endl;
        cout << "===================================================================================================================================" << endl;
        P=first_mahasiswa(L);
        while(next_mahasiswa(P)!=first_mahasiswa(L)){
            cout.setf(ios::left|ios::showpoint);
            cout << "|";
            cout.width(22);
            cout<<info_mahasiswa(P).nim;
            cout << "|";
            cout.width(26);
            cout<<info_mahasiswa(P).nama;
            cout << "|";
            cout.width(31);
            cout<<info_mahasiswa(P).jurusan;
            cout << "|";
            cout.width(32);
            cout<<info_mahasiswa(P).alamat;
            cout << "|";
            cout.width(15);
            cout<<info_mahasiswa(P).no_telp;
            cout << "|\n";
            cout<<endl;
            P=next_mahasiswa(P);
        }
            cout.setf(ios::left|ios::showpoint);
            cout << "|";
            cout.width(22);
            cout<<info_mahasiswa(P).nim;
            cout << "|";
            cout.width(26);
            cout<<info_mahasiswa(P).nama;
            cout << "|";
            cout.width(31);
            cout<<info_mahasiswa(P).jurusan;
            cout << "|";
            cout.width(32);
            cout<<info_mahasiswa(P).alamat;
            cout << "|";
            cout.width(15);
            cout<<info_mahasiswa(P).no_telp;
            cout << "|\n";
            cout<<"\n\n";
    }
}

// menginput data mahasiswa pada setelah pointer pada list
void insertAfter_mahasiswa(address_mahasiswa Prec, address_mahasiswa P){
        next_mahasiswa(P)=next_mahasiswa(Prec);
        prec_mahasiswa(next_mahasiswa(Prec))=P;
        next_mahasiswa(Prec)=P;
        prec_mahasiswa(P)=Prec;
}

// menghapus data mahasiswa pada setelah pointer pada list
void deleteAfter_mahasiswa(address_mahasiswa Prec, address_mahasiswa &P){
        P=next_mahasiswa(Prec);
        prec_mahasiswa(next_mahasiswa(P))=prec_mahasiswa(P);
        next_mahasiswa(Prec)=next_mahasiswa(P);
        next_mahasiswa(P)=NULL;
        prec_mahasiswa(P)=NULL;
}

// menghapus data mahasiswa sesuai element yg dicari
void deleteSearch_mahasiswa(List_mahasiswa &LP, address_mahasiswa &P){
    address_mahasiswa Q, Prec;
    Q=first_mahasiswa(LP);
    do{
        Q=next_mahasiswa(Q);
    }while (next_mahasiswa(Q)!=first_mahasiswa(LP));
    if(P!=NULL){
        if(P==first_mahasiswa(LP)){
            if(next_mahasiswa(P)==first_mahasiswa(LP)){
                first_mahasiswa(LP)=NULL;
            }
            else{
                deleteFirst_mahasiswa(LP, P);
            }
        }else if(P==Q){
            deleteLast_mahasiswa(LP, P);
        }else{
            Prec = prec_mahasiswa(P);
            deleteAfter_mahasiswa(Prec, P);
        }
    }
}

// tampilan edit mahasiswa
void editInfo_mahasiswa(List_mahasiswa L, address_mahasiswa &P){
    cout<<"NIM \t\t: ";
    cin>>info_mahasiswa(P).nim;
    cin.ignore();
    cout<<"Nama \t\t: ";
    getline(cin,info_mahasiswa(P).nama);
    cout<<"Jurusan \t: ";
    getline(cin,info_mahasiswa(P).jurusan);
    cout<<"Alamat \t\t: ";
    getline(cin,info_mahasiswa(P).alamat);
    cout<<"No.Telp  \t: ";
    cin>>info_mahasiswa(P).no_telp;
}

// tampilan tambah mahasiswa
address_mahasiswa input_mahasiswa(){
    mahasiswa x;
    cout<<"NIM \t\t: ";
    cin>>x.nim;
    cin.ignore();
    cout<<"Nama \t\t: ";
    getline(cin,x.nama);
    cout<<"Jurusan \t: ";
    getline(cin,x.jurusan);
    cout<<"Alamat \t\t: ";
    getline(cin,x.alamat);
    cout<<"No.Telp \t: ";
    cin>>x.no_telp;

    return alokasi_mahasiswa(x);
}

// deklarasi variable
void data_mahasiswa (List_mahasiswa &L){
    mahasiswa mp;
    address_mahasiswa P;
}

// menghitung jumlah mahasiswa
void count_mahasiswa(List_mahasiswa L){
    address_mahasiswa P;
    int count = 1;
    if(first_mahasiswa(L)!=NULL){
        P=first_mahasiswa(L);
        while(next_mahasiswa(P)!=first_mahasiswa(L)){
            count++;
            P=next_mahasiswa(P);
        }
        cout << "Jumlah mahasiswa: " << count << endl;
    } else {
        cout << "Data masih kosong" << endl;
    }
}
