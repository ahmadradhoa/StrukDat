#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n <= 1) return false;

    for(int i = 2; i < n; i++){
        if(n % i == 0) return false;
    }

    return true;
}

int main(){
    int angka;
    cout << "Masukkan Angka: ";
    cin >> angka;

    if(isPrime(angka)) cout << angka << " Adalah bilangan Prima";
    else cout << angka << " Bukan bilangan Prima";
    return 0;
}