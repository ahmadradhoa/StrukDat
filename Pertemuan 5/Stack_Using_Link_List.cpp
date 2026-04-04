#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Stack{
    private:
        Node* top;

    public:
        Stack(){
            top = NULL;
        }

        void push(int x){
            Node* newNode = new Node();
            newNode->data = x;
            newNode->next = top;
            top = newNode;

            cout << x << " ditambahkan ke Stack\n";
        }

        void pop(){
            if(top == NULL){
                cout << "Stack Underflow\n";
                return;
            }

            Node* temp = top;
            cout << temp->data << " dihapus dari stack\n";
            top = top->next;
            delete temp;
        }

        void peek(){
            if(top == NULL){
                cout << "Stack Kosong\n";
            }
            else {
                cout << "Elemen teratas: " << top->data << '\n';
            }
        }

        bool isEmpty(){
            return (top == NULL);
        }
};

int main(){
    Stack s;
    int n;
    cout << "Masukkan jumlah perintah: ";
    cin >> n;
    
    while(n--){
        string p;
        cout << "Masukkan perintah (push/pop/peek/isEmpty): ";
        cin >> p;

        if(p == "push"){
            int a;
            cin >> a;
            s.push(a);
        }
        else if(p == "pop"){
            s.pop();
        }
        else if(p == "peek"){
            s.peek();
        }
        else if(p == "isEmpty"){
            if(s.isEmpty()){
                cout << "Stack kosong\n";
            }
            else {
                cout << "Stack terisi\n";
            }
        }
    }

    return 0;
}