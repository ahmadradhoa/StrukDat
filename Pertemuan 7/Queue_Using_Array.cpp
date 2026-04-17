#include <bits/stdc++.h>
using namespace std;

#define MAX 10000

class Queue{
    private:
        int arr[MAX];
        int front, rear;

    public:
        Queue(){
            front = -1;
            rear = -1;
        }

        bool isEmpty(){
            return (front == -1);
        }

        bool isFull(){
            return (rear == MAX -1);
        }

        void enqueue(int n){
            if(isFull()){
                cout << "Queue Overflow\n";
                return;
            }

            if(isEmpty()){
                front = 0;
            }

            arr[++rear] = n;
            cout << "Elemen " << n << " masuk ke queue\n";
        }

        void dequeue(){
            if(isEmpty()){
                cout << "Queue Underflow\n";
            }

            cout << "Elemen " << arr[front] << " keluar dari queue\n";
            if(front == rear){
                front = rear = -1;
            }
            else {
                front++;
            }
        }

        void display(){
            if(isEmpty()){
                cout << "Queue kosong\n";
                return;
            }

            cout << "Isi Queue: ";
            for(int i = front; i <= rear; i++){
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
};

int main(){
    Queue q;

    int n;
    cout << "Masukkan jumlah perintah: ";
    cin >> n;

    while(n--){
        string s;
        cout << "Masukkan perintah (enqueue/dequeue/display): ";
        cin >> s;

        if(s == "enqueue"){
            int m;
            cin >> m;
            q.enqueue(m);
        }
        else if(s == "dequeue"){
            q.dequeue();
        }
        else if(s == "display"){
            q.display();
        }
    }

    return 0;
}