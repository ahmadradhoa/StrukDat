#include <bits/stdc++.h>
using namespace std;

int main(){
    int tinggi;
    cout << "Masukkan Tinggi Segitiga: ";
    cin >> tinggi;

    for(int i = 0; i < tinggi; i++){
        for(int j = 0; j < tinggi - i; j++){
            cout << " ";
        }

        for(int k = 0; k < i * 2 + 1; k++){
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}