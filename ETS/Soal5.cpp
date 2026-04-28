#include <bits/stdc++.h>
using namespace std;

string layani;

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
    string s;
    while(cin >> s){
        if(s == "layani"){
            layaniMahasiswa(q);
        }
        else if(s == "tampilkan"){
            cekAntrian(q);
        }
        else {
            tambahMahasiswa(q, s);
        }
    }

    return 0;
}