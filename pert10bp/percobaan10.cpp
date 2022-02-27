#include <iostream>
using namespace std;
int main(){
    cout<<"=== MENCARI KARAKTER DALAM SEBUAH NAMA ==="<<endl;
	int v,c,n,i,flag;
	v=c=n=flag=0;
	string kalimat;
	string search;
	cout<<"Masukan kalimat : ";
	getline(cin, kalimat);
	for(int i=0; kalimat[i]!='\0'; ++i){
		if (kalimat[i]=='a'||
			kalimat[i]=='i'||
			kalimat[i]=='u'||
			kalimat[i]=='e'||
			kalimat[i]=='o'||
			kalimat[i]=='A'||
			kalimat[i]=='I'||
			kalimat[i]=='U'||
			kalimat[i]=='E'||
			kalimat[i]=='O')
			{++v;
			}
		else if((kalimat[i]>='a'&&kalimat[i]<='z')||
				(kalimat[i]>='A'&&kalimat[i]<='Z'))
			{++c;
			}
				
		else if (kalimat[i]>='0'&&kalimat[i]<='9')
			{++n;
			}
	}
	cout<<"\n"<<"Huruf vokal = "<<" = "<<v<<" = ";
	for(i=0; kalimat[i]!='\0'; i++){
		if (kalimat[i]=='a'||
			kalimat[i]=='A'||
			kalimat[i]=='i'||
			kalimat[i]=='I'||
			kalimat[i]=='u'||
			kalimat[i]=='U'||
			kalimat[i]=='e'||
			kalimat[i]=='E'||
			kalimat[i]=='o'||
			kalimat[i]=='O')
				cout<<kalimat[i]<<", ";
	}cout<<"\n";
	
	cout<<"\n"<<"Huruf konsonan = "<<c<<" = ";
	for(i=0; kalimat[i]!='\0'; i++){
		if(
			kalimat[i]!='a'&&
			kalimat[i]!='A'&&
			kalimat[i]!='i'&&
			kalimat[i]!='I'&&
			kalimat[i]!='u'&&
			kalimat[i]!='U'&&
			kalimat[i]!='e'&&
			kalimat[i]!='E'&&
			kalimat[i]!='o'&&
			kalimat[i]!='O'&&
			(kalimat[i]>='a'&&
			kalimat[i]<='z'||
			kalimat[i]>='A'&&
			kalimat[i]<='Z'))
			cout<<kalimat[i]<<", ";
	}cout<<"\n";
	
	cout<<"\n"<<"Numerik = "<<n<<" = ";
	for(i=0; kalimat[i]!='\0'; i++){
		if(kalimat[i]>='0'&&kalimat[i]<='9')
			cout<<kalimat[i]<<", ";
	}cout<<"\n";
	ward:
	cout<<"\n"<<"Masukan data yang akan dicari (posisi spasi dihitung): ";getline(cin,search);
	
		for(i=0; kalimat[i]!='\0'; i++){
			if(kalimat[i]==search[0]){
			flag = flag +1;
			cout<<"Data "<<search<<" terdapat pada posisi ke-"<<i+1<<endl;}
		  }
		if (flag==0){
			cout<<"Data "<<search<<" tidak ditemukan,silahkan coba lagi"<<endl;goto ward;
		}
    /*flag = 0;
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
*/
//getch();
return 0;
}
