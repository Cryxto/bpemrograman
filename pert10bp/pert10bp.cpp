#include <iostream>
#include <conio.h>
#include <stdio.h>
#include<string.h>
using namespace std;
int main(){
	int v,c,n,i,flag;
	v=c=n=flag=0;
	char kalimat [80];
	char search;
	cout<<"Masukan kalimat : ";
	cin.getline(kalimat,80);
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
	cout<<"\n"<<"Masukan data yang akan dicari (posisi spasi dihitung): ";cin>>search;
	
		for(i=0; kalimat[i]!='\0'; i++){
			if(kalimat[i]==search){
			flag = flag +1;
			cout<<"Data "<<search<<" terdapat pada posisi ke-"<<i+1<<endl;}
		  }
		if (flag==0){
			cout<<"Data "<<search<<" tidak ditemukan,silahkan coba lagi"<<endl;goto ward;
		}
getch();
return 0;
}
