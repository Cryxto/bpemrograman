#include <iostream>
using namespace std;

int main (){
    int v,c,n,i,flag;
	v=c=n=flag=0;
	string search;
    flag = 0;
    int orang;
    string nama[80];
    cout<<"\n === MENCARI NAMA DALAM SEBUAH KELAS ==="<<endl;
    cout<<"Masukan banyaknya orang :"; cin>>orang;
    cin.ignore();
    for(i=0; i<orang; i++){
        cout<<"Nama : "; getline(cin, nama[i]);
    }
    ward2 :
    cout<<"Masukan nama yang dicari : "; getline(cin, search);
    for(i=0; i<orang; i++){
			if(nama[i]==search){
			flag = flag +1;
			cout<<"Nama "<<search<<" ditemukan pada daftar ke-"<<i+1<<endl;}
		  }
		if (flag==0){
			cout<<"Nama "<<search<<" tidak ditemukan,silahkan coba lagi\n"<<endl;goto ward2;
		}
    return 0;
}