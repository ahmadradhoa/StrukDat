#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Masukkan Panjang Elemen: ";
    cin >> n;

    int nilai[n];
    for(int i = 0; i < n; i++){
        cout << "Masukkan Nilai Ke-" << i << ": ";
        cin >> nilai[i];
    }

    cout << "Elemen yang dimasukkan: " << endl;
    for(int i = 0; i < n; i++){
        cout << nilai[i] << " ";
    }

    return 0;
}