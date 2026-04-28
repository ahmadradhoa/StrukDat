#include <bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

string Convert(string infix){
    stack<char> st;
    string postfix;

    for(char c : infix){
        if(isalnum(c)){
            postfix += c;
            postfix += ' ';
        }
        else if(c == '('){
            st.push(c);
        }
        else if(c == ')'){
            while(!st.empty() && st.top() != '('){
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }
            if(!st.empty()) st.pop();
        }
        else {
            while(!st.empty() && precedence(st.top()) >= precedence(c)){
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()){
        postfix += st.top();
        postfix += ' ';
        st.pop();
    }

    return postfix;
}

int main(){
    string infix;
    cout << "Infix: ";
    cin >> infix;

    cout << "Postfix: " << Convert(infix);
    return 0;
}