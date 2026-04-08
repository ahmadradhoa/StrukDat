#include <bits/stdc++.h>
using namespace std;

int Precedence(char op){
    if(op == '^')
        return 3;
    else if(op == '*' || op == '/')
        return 2;
    else if(op == '+' || op == '-')
        return 1;
    else 
        return 0;
}

bool Operator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void Convert(string s){
    stack<char> st;
    string pos = "";
    string mst = "";

    for(char c : s){

        if(isalnum(c)){
            pos += c;
            cout << c << "\t\t" << pos << "\t\t" << mst << "\n";
        }
        else if(c == '('){
            st.push(c);
            mst += c;
            cout << c << "\t\t" << pos << "\t\t" << mst << "\n";
        }
        else if(c == ')'){
            while(!st.empty() && st.top() != '('){
                pos += st.top();
                st.pop();
                mst.pop_back();
            }
            if(!st.empty()){
                st.pop();
                mst.pop_back();
            }
            cout << c << "\t\t" << pos << "\t\t" << mst << "\n";
        }
        else if(Operator(c)){
            while(!st.empty() && Precedence(st.top()) >= Precedence(c)){
                pos += st.top();
                st.pop();
                mst.pop_back();
            }
            st.push(c);
            mst += c;
            cout << c << "\t\t" << pos << "\t\t" << mst <<"\n";
        }
    }

    while(!st.empty()){
        pos += st.top();
        st.pop();
    }
    cout << "Postfix: " << pos << "\n";
}

int main(){
    string s;

    cout << "Masukkan ekspresi infix: ";
    cin >> s;

    cout << "Symbol | Postfix String | Stack\n";
    Convert(s);
    return 0;
}