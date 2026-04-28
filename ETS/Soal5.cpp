#include <bits/stdc++.h>
using namespace std;

void tambahMahasiswa(queue<string>& q, string nama){
    q.push(nama);
    cout << "Mahasiswa " << nama << " berhasil mengambil nomor antrian\n";
}

void layaniMahasiswa(queue<string>& q){
    if(q.empty()){
        cout << "Tidak ada antrian mahasiswa saat ini\n";
    }
    else {
        cout << "Mahasiswa " << q.front() << " telah dilayani\n";
        q.pop();
    }
}

void cekAntrian(queue<string> q){
    if(q.empty()){
        cout << "Antrian kosong\n";
    }
    else {
        cout << "=== Status Antrian ===\n";
        cout << "Sedang dilayani: " << q.front() << endl;
        cout << "Antrian terakhir: " << q.back() << endl;
        cout << "Total dalam antrian: " << q.size() << " orang\n";
        cout << "Antrian: \n";
        while(!q.empty()){
            cout << q.front() << "\n";
            q.pop();
        }
        cout << "======================\n";
    }
}

int main(){
    queue<string> q;
    int n;
    while(true){
        cout << "===================================\n";
        cout << "1. Ambil Antrian (Tambah Mahasiswa)\n";
        cout << "2. Panggil Loket (layani Mahasiswa)\n";
        cout << "3. Tampilkan Status Antrian\n";
        cout << "4. Keluar Program\n";
        cout << "===================================\n";
        cout << "Pilih menu (1-4)\n";
        cin >> n;
        if(n == 1){
            string s;
            cout << "Masukkan Nama: ";
            cin >> s;
            tambahMahasiswa(q, s);
            cout << "\n";
        }
        else if(n == 2){
            layaniMahasiswa(q);
            cout << "\n";
        }
        else if(n == 3){
            cekAntrian(q);
            cout << "\n";
        }
        else {
            cout << "Program selesai\n";
            break;
        }
    }

    return 0;
}