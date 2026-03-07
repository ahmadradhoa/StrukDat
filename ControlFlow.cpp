#include <bits/stdc++.h>
using namespace std;

int main(){
    int angka;
    cout << "Masukkan angka: ";
    cin >> angka;

    if(angka % 2 == 0) cout << angka << " adalah Angka Genap";
    else cout << angka << " adalah Angka Ganjil";

    return 0;
}