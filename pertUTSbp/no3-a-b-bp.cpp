#include <iostream>
using namespace std;

void segitigaBintang_1 (int n){
    for (int i = n; i >= 1; i--) {
        for (int j = i; j > 0; j--) {
            cout << "*";
        }
        cout << endl;
    }
}
void segitigaBintang_2 (int n){
   for (int i = n; i >= 1; i--) {
        for (int k = n - i; k > 0; k--) {
            cout << " ";
        }
        for (int j = i; j > 0; j--) {
            cout << "*";
        }
        cout << endl;
    }
}

int main (){
    int n =5;
    segitigaBintang_1(n);
    cout<<endl;
    segitigaBintang_2(n);
    return 0;
}