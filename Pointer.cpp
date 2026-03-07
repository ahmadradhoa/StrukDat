#include <bits/stdc++.h>
using namespace std;

int main(){
    int angka;
    cin >> angka;
    int *ptr = &angka;

    cout << "Nilai angka: " << angka << endl;
    cout << "Alamat angka: " << &angka << endl;
    cout << "Nilai yang ditunjuk pointer: " << *ptr << endl;
    return 0;
}
