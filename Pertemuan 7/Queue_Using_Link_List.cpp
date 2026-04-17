#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Queue{
    private:
        Node *front, *rear;

    public:
        Queue(){
            front = rear = NULL;
        }

        bool isEmpty(){
            return (front == NULL);
        }

        void enqueue(int n){
            Node* newNode = new Node();
            newNode->data = n;
            newNode->next = NULL;

            if(rear == NULL){
                front = rear = newNode;
            }
            else {
                rear->next = newNode;
                rear = newNode;
            }

            cout << "Elemen " << n << " masuk ke queue\n";
        }

        void dequeue(){
            if(isEmpty()){
                cout << "Queue kosong\n";
                return;
            }

            Node* temp = front;
            cout << "Elemen " << temp->data << " keluar dari queue\n";

            front = front->next;

            if(front == NULL){
                rear = NULL;
            }

            delete temp;
        }

        void display(){
            if(isEmpty()){
                cout << "Queue kosong\n";
                return;
            }

            Node* temp = front;
            cout << "Isi Queue: ";
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
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