#include <bits/stdc++.h>
using namespace std;

void Postfix(string exp){
    stack<int> st;
    string mst = "";

    for(char c : exp){
        if(isdigit(c)){
            st.push(c - '0');
            mst += c;
            cout << c << "\t\t" << mst << "\n";
            mst += ",";
        }
        else {
            mst.pop_back();
            int val2 = st.top();
            st.pop();
            mst.pop_back();
            mst.pop_back();
            int val1 = st.top();
            st.pop();
            mst.pop_back();
            
            switch(c){
                case '+':
                    st.push(val1 + val2);
                    mst += to_string(val1 + val2);
                    cout << c << "\t\t" << mst << "\n";
                    mst += ",";
                    break;
                case '-':
                    st.push(val1 - val2);
                    mst += to_string(val1 - val2);
                    cout << c << "\t\t" << mst << "\n";
                    mst += ",";
                    break;
                case '*':
                    st.push(val1 * val2);
                    mst += to_string(val1 * val2);
                    cout << c << "\t\t" << mst << "\n";
                    mst += ",";
                    break;
                case '/':
                    st.push(val1 / val2);
                    mst += to_string(val1 / val2);
                    cout << c << "\t\t" << mst << "\n";
                    mst += ",";
                    break;
                case '^':
                    st.push(pow(val1, val2));
                    mst += to_string(int(pow(val1, val2)));
                    cout << c << "\t\t" << mst << "\n";
                    mst += ",";
                    break;
            }
        }
    }

    cout << "Hasil evaluasi: " << st.top() << "\n";
}

int main(){
    string s;

    cout << "Masukkan ekspresi postfix: ";
    cin >> s;

    cout << "Symbol\t| Stack\n";
    Postfix(s);
    return 0;
}