#include <bits/stdc++.h>
using namespace std;

#define MAX 10000

class Stack{
    private:
        int arr[MAX];
        int top;
    
    public:
        Stack(){
            top = -1;
        }

        void push(int x){
            if(top == MAX - 1){
                cout << "Stack Overflow\n";
            }
            else {
                arr[++top] = x;
                cout << x << " ditambahkkan ke stack\n";
            }
        }

        void pop(){
            if(top == -1){
                cout << "Stack Underflow\n";
            }
            else {
                cout << arr[top--] << " dihapus dari stack\n";
            }
        }

        void peek(){
            if(top == -1){
                cout << "Stack Kosong\n";
            }
            else {
                cout << "Elemen Teratas: " << arr[top] << '\n';
            }
        }
};

int main(){
    Stack s;
    int n;
    cout << "Masukkan jumlah perintah: ";
    cin >> n;
    
    while(n--){
        string p;
        cout << "Masukkan perintah (push/pop/peek): ";
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
    }

    return 0;
}