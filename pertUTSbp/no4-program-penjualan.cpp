#include <iostream>
using namespace std;

struct ukuran_baju{
    double harga;
    string ukuran_bj [4] ={"S","M","Ukuran Lain"};
};
struct nama_bj{
    ukuran_baju uk_bj[6];
    string theNama [6]={"IMP","Prada", "Gucci","Louis Vuitton","Kick Denim"};
};
struct toko {
    nama_bj n_bj[6];
    int indeks [6]={1,2,3,4,5};  
};

toko toko_baju;
void setHarga();
void katalog();

int main (){
    int barang = 0;
    int checkpoint=0;
    bool menuCashier = true;
    int menuChoose;
    int kodeBajunya[30];
    int ukuranBajunya[30];
    int nampung_hrg=0;
    int nampung_brg=0;
    int menuTambahbrg=1;
    setHarga();
    while (menuCashier==true){
        //system("CLS");
        cout<<"Menu : \n"
            <<"0. Keluar\n"
            <<"1. Buat pesanan\n"
            <<"2. Tampilkan pesanan dan total \n"
            <<"3. Cetak pesanan dan membersihkan pesanan \n"
            <<"4. Hapus semua pesanan \n";
        cout<<"Pilih menu : ";
        cin>>menuChoose;
        while (menuChoose>4||menuChoose<0)
        {
            cout<<"Menu tidak ada! "<<endl;
            cout<<"Pilih lagi menu lagi : ";
            cin>>menuChoose;
        }
        switch (menuChoose){
            case 0 :
            system("clear");
            cout<<"Keluar...";
            menuCashier = false;
            break;
            case 1 :
            ward1:
            system("clear");
            cout<<"Masukan banyaknya barang : ";
            checkpoint=barang+checkpoint;
            cin>>barang;
            katalog();
            for (int i=checkpoint; i<barang+checkpoint; i++){
                cout<<"Kode : ";
                cin>>kodeBajunya[i];
                while(kodeBajunya[i]>5||kodeBajunya[i]<1){
                    cout<<"Kode tidak ada"<<"! Pilih yang ada!"<<endl;
                    cout<<"Kode : ";
                    cin>>kodeBajunya[i];
                }
                kodeBajunya[i]=kodeBajunya[i]-1;
                cout<<"Ukuran (1=S, 2=M, 3=Ukuran Lain) : ";
                cin>>ukuranBajunya[i];
                while(ukuranBajunya[i]>3||ukuranBajunya[i]<1){
                    cout<<"Kode tidak ada"<<"! Pilih yang ada!"<<endl;
                    cout<<"Ukuran (1=S, 2=M, 3=Ukuran Lain) : ";
                    cin>>ukuranBajunya[i];
                }
                ukuranBajunya[i]=ukuranBajunya[i]-1;
                nampung_hrg=nampung_hrg+toko_baju.n_bj[kodeBajunya[i]].uk_bj[ukuranBajunya[i]].harga;
                nampung_brg++;
            }
            while(menuTambahbrg==1){
                cout<<"Tambah lagi? ya=1 no=0 :";
                cin>>menuTambahbrg;
                if(menuTambahbrg==1){
                    goto ward1;
                }
                else{
                    menuTambahbrg=0;
                }
            }
            menuTambahbrg=1;
            system("clear");
            break;

            case 2:
            system("clear");
            cout<<endl;
            if (nampung_brg>0){
            for (int i=0; i<nampung_brg; i++){
                 cout<<"Nama Baju : "<<toko_baju.n_bj[kodeBajunya[i]].theNama[kodeBajunya[i]]<<endl;
                 cout<<"Ukuran Baju : "<<toko_baju.n_bj[kodeBajunya[i]].uk_bj[ukuranBajunya[i]].ukuran_bj[ukuranBajunya[i]]<<endl;
                 cout<<"Harga : "<<toko_baju.n_bj[kodeBajunya[i]].uk_bj[ukuranBajunya[i]].harga<<endl<<endl;
            }
            }
            cout<<endl<<"Total harga : "<<nampung_hrg<<endl<<endl;
            break;

            case 3:
            system("clear");
            cout<<endl;
            if (nampung_brg>0){
            for (int i=0; i<nampung_brg; i++){
                 cout<<"Nama Baju : "<<toko_baju.n_bj[kodeBajunya[i]].theNama[kodeBajunya[i]]<<endl;
                 cout<<"Ukuran Baju : "<<toko_baju.n_bj[kodeBajunya[i]].uk_bj[ukuranBajunya[i]].ukuran_bj[ukuranBajunya[i]]<<endl;
                 cout<<"Harga : "<<toko_baju.n_bj[kodeBajunya[i]].uk_bj[ukuranBajunya[i]].harga<<endl<<endl;
            }
            }
            cout<<endl<<"Total harga : "<<nampung_hrg<<endl<<endl;
            cout<<"Mencetak struk....."<<endl;
            cout<<"Membersihkan pesanan......"<<endl;
            for (int i=0; i<nampung_brg; i++){
                kodeBajunya[i]=10;
                ukuranBajunya[i]=10;
            }
            nampung_brg = 0;
            nampung_hrg = 0 ;
            checkpoint = 0;
            barang =0;
            break;

            case 4:
            system("clear");
            cout<<"Menghapus Semua Pesanan..."<<endl;
            for (int i=0; i<nampung_brg; i++){
                kodeBajunya[i]=10;
                ukuranBajunya[i]=10;
            }
            nampung_brg = 0;
            nampung_hrg = 0 ;
            checkpoint = 0;
            barang =0;
            break;

            default :
            cout<<"Menu tidak ada!";
            break;
        }
    }
    return 0;
}
void setHarga(){
    toko_baju.n_bj[0].uk_bj[0].harga=200000;
    toko_baju.n_bj[0].uk_bj[1].harga=220000;
    toko_baju.n_bj[0].uk_bj[2].harga=250000;
    toko_baju.n_bj[1].uk_bj[0].harga=150000;
    toko_baju.n_bj[1].uk_bj[1].harga=160000;
    toko_baju.n_bj[1].uk_bj[2].harga=170000;
    toko_baju.n_bj[2].uk_bj[0].harga=200000;
    toko_baju.n_bj[2].uk_bj[1].harga=200000;
    toko_baju.n_bj[2].uk_bj[2].harga=200000;
    toko_baju.n_bj[3].uk_bj[0].harga=300000;
    toko_baju.n_bj[3].uk_bj[1].harga=300000;
    toko_baju.n_bj[3].uk_bj[2].harga=350000;
    toko_baju.n_bj[4].uk_bj[0].harga=100000;
    toko_baju.n_bj[4].uk_bj[1].harga=120000;
    toko_baju.n_bj[4].uk_bj[2].harga=130000;
}
void katalog(){
    cout<<endl<<"Katalog : "<<endl<<endl;
    for(int i=0; i<5; i++){
        cout<<"Kode Baju : "<<toko_baju.indeks[i]<<endl;
         cout<<"Nama Baju : "<<toko_baju.n_bj[i].theNama[i]<<endl;
        for(int j=0; j<3; j++){
            cout<<"Ukuran Baju : "<<toko_baju.n_bj[i].uk_bj[j].ukuran_bj[j]
            <<" : "<<toko_baju.n_bj[i].uk_bj[j].harga<<endl;
        }
        cout<<endl;
    }
}