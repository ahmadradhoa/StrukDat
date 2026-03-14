#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Masukkan Panjang Data: ";
    cin >> n;

    int nilai[n];
    int total = 0;
    float rata;
    for(int i = 0; i < n; i++){
        cout << "Masukkan Nilai Ke-" << i+1 << ": ";
        cin >> nilai[i];
        total += nilai[i];
    }

    rata = (float)total / n;

    cout << "Total Nilai: " << total << endl;
    cout << "Rata-rata: " << rata << endl;

    return 0;
}