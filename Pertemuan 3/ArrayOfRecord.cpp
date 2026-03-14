#include <bits/stdc++.h>
using namespace std;

struct mahasiswa{
    string nama, nrp, jurusan;
    int umur;
    string hobi[3], alergi[3];
};

int main(){
    int n;
    cout << "Masukkan Banyak Mahasiswa: ";
    cin >> n;

    mahasiswa mhs[n];
    for(int i = 0; i < n; i++){
        cout << "Data Mahasiswa ke-" << i+1 << endl;

        cout << "NRP    : ";
        cin >> mhs[i].nrp;

        cout << "Nama   : ";
        cin.ignore();
        getline(cin, mhs[i].nama);

        cout << "Jurusan: ";
        getline(cin, mhs[i].jurusan);

        cout << "Ketik '0' untuk Menghentikan Memasukkan Hobi Jika Kurang dari 3" << endl;
        for(int j = 0; j < 3; j++){
            cout << "Hobi ke-" << j+1 << ": ";
            getline(cin, mhs[i].hobi[j]);
            if(mhs[i].hobi[j].compare("0") == 0) break;
        }

        cout << "Ketik '0' untuk Menghentikan Memasukkan Alergi Jika Kurang dari 3/Tidak Ada" << endl;
        for(int j = 0; j < 3; j++){
            cout << "Alergi ke-" << j+1 << ": ";
            getline(cin, mhs[i].alergi[j]);
            if(mhs[i].alergi[j].compare("0") == 0) break;
        }

        cout << endl;
    }

    cout << endl;

    cout << "============ Display Data Mahasiswa ============" << endl;
    for(int i = 0; i < n; i++){
        cout << endl;
        cout << "Mahasiswa Ke-" << i+1 << endl;
        cout << "NRP: " << mhs[i].nrp << endl;
        cout << "Nama: " << mhs[i].nama << endl;
        cout << "Jurusan: " << mhs[i].jurusan << endl;
        bool koma = false;
        cout << "Hobi: ";
        for(int j = 0; j < 3; j++){
            if(mhs[i].hobi[j].compare("0") == 0) break;

            if(koma)cout << ", ";
            cout << mhs[i].hobi[j];
            koma = true;
        }
        koma = false;
        cout << endl;
        cout << "Alergi: ";
        if(mhs[i].alergi[0].compare("0") == 0)cout << "-";
        else {
            for(int j = 0; j < 3; j++){
                if(mhs[i].alergi[j].compare("0") == 0) break;
                if(koma)cout << ", ";
                cout << mhs[i].alergi[j];
                koma = true;
            }
        }

        cout << endl;
    }

    return 0;
}