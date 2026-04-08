#include <bits/stdc++.h>
using namespace std;

void Postfix(string exp){
    stack<int> st;
    stringstream ss(exp);
    string token;
    vector<string> mst;

    while(ss >> token){
        if(token == "+" || token == "-" || token == "*" || token == "/" || token == "^"){
            mst.pop_back();
            int val2 = st.top();
            st.pop();
            mst.pop_back();
            mst.pop_back();
            int val1 = st.top();
            st.pop();
            mst.pop_back();

            if(token == "+"){
                st.push(val1 + val2);
                mst.push_back(to_string(val1 + val2));
            }
            else if(token == "-"){
                st.push(val1 - val2);
                mst.push_back(to_string(val1 - val2));
            }
            else if(token == "*"){
                st.push(val1 * val2);
                mst.push_back(to_string(val1 * val2));
            }
            else if(token == "/"){
                st.push(val1 / val2);
                mst.push_back(to_string(val1 / val2));
            }
            else if(token == "^"){
                st.push(pow(val1, val2));
                mst.push_back(to_string(int(pow(val1, val2))));
            }
            
            cout << token << "\t\t";
            for(string s : mst){
                cout << s;
            }
            cout << "\n";
            mst.push_back(",");
        }
        else {
            st.push(stoi(token));
            mst.push_back(token);
            cout << token << "\t\t";
            for(string s : mst){
                cout << s;
            }
            cout << "\n";
            mst.push_back(",");
        }
    }

    cout << "Hasil evaluasi: " << st.top() << "\n";
}

int main(){
    string s;

    cout << "Masukkan ekspresi postfix (pisahkan dengan spasi): ";
    getline(cin, s);

    cout << "Symbol\t| Stack\n";
    Postfix(s);
    return 0;
}