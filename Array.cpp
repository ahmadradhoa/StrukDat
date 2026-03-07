#include <bits/stdc++.h>
using namespace std;

int getMin(int arr[], int n){
    int res = arr[0];
    for(int i = 0; i < n; i++){
        res = min(res, arr[i]);
    }
    
    return res;
}

int getMax(int arr[], int n){
    int res = arr[0];
    for(int i = 0; i < n; i++){
        res = max(res, arr[i]);
    }

    return res;
}

int main(){
    int angka;
    cout << "Masukkan Jumlah deret: ";
    cin >> angka;

    int arr[angka];
    cout << "Masukkan deret: ";
    for(int i = 0; i < angka; i++){
        cin >> arr[i];
    }

    cout << "Elemen minimum adalah: " << getMin(arr, angka) << endl;
    cout << "Elemen maksimum adalah: " << getMax(arr, angka) << endl;

    return 0;
}