#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Masukkan Banyak Mahasiswa: ";
    cin >> n;

    int min;
    cout << "Nilai Minimum Untuk Lulus: ";
    cin >> min;

    int nilai[n];
    for(int i = 0; i < n; i++){
        cout << "Masukkan Nilai Mahasiswa Ke-" << i+1 << ": ";
        cin >> nilai[i];
    }

    cout << endl;
    cout << "Status Kelulusan" << endl;
    for(int i = 0; i < n; i++){
        if(nilai[i] >= min){
            cout << "Mahasiswa " << i+1 << ": Lulus" << endl;
        }
        else {
            cout << "Mahasiswa " << i+1 << ": Tidak Lulus" << endl;
        }
    }

    return 0;
}