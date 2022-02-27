#include <iostream>
#include <iomanip>
using namespace std;

int main (){
    int m[30][30], baris, kolom, i=0, j=0, jmlh=0;
    cout<<"Baris : ";cin>>baris;
    cout<<"Kolom : ";cin>>kolom;

    for (i=0; i<baris; i++){
        for (j=0; j<kolom; j++){
            m[i][j]=jmlh;
            cout<<setw(3)<<right<<jmlh<<" ";
            jmlh++;
            if (jmlh%kolom==0 && kolom!=0){
                cout<<"\n";
            }
        }
    }
    return 0;
}