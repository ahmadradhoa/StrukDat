#include <bits/stdc++.h>
using namespace std;

struct Bnode{
    vector<int> key;
    vector<Bnode*> child;
    bool isL;

    Bnode(bool leaf) : isL(leaf) {}
};

class Btree{
    private:
        Bnode* root;
        int ORDER;

        void splitC(Bnode* p, int i){
            Bnode* child = p->child[i];
            Bnode *newNode = new Bnode(child->isL);

            int mid = (ORDER - 1) / 2;
            int midk = child->key[mid];

            newNode->key.assign(child->key.begin() + mid + 1, child->key.end());
            child->key.resize(mid);

            if(!child->isL){
                newNode->child.assign(child->child.begin() + mid + 1, child->child.end());

                child->child.resize(mid + 1);
            }

            p->key.insert(p->key.begin() + i, midk);
            p->child.insert(p->child.begin() + i + 1, newNode);
        }

        void insertNonFull(Bnode* node, int key){
            int i = node->key.size() - 1;

            if(node->isL){
                node->key.push_back(0);

                while(i >= 0 && key < node->key[i]){
                    node->key[i + 1] = node->key[i];
                    i--;
                }

                node->key[i + 1] = key;
            }
            else {
                while(i >= 0 && key < node->key[i]) i--;

                i++;
                
                if((int)node->child[i]->key.size() == ORDER - 1){
                    splitC(node, i);
                    if(key > node->key[i]) i++;
                }

                insertNonFull(node->child[i], key);
            }
        }

        void inorder(Bnode* node){
            if(!node) return;

            int n = node->key.size();

            for(int i = 0; i < n; i++){
                if(!node->isL) inorder(node->child[i]);

                cout << node->key[i] << " ";
            }

            if(!node->isL) inorder(node->child[n]);
        }

        bool search(Bnode* node, int k){
            if(!node) return false;

            int i = 0;

            while(i < (int)node->key.size() && k > node->key[i]) i++;

            if(i < (int)node->key.size() && k == node->key[i]) return true;
            if(node->isL) return false;

            return search(node->child[i], k);
        }

        void printL(Bnode* node, int l){
            if(!node) return;

            cout << "Level " << l << " : ";

            for(int i : node->key) cout << i << " ";

            cout << "\n";

            if(!node->isL){
                for(Bnode* c : node->child) printL(c, l + 1);
            }
        }

        public:
            Btree(int order){
                ORDER = max(order, 3);
                root = new Bnode(true); 
            }

            void insert(int k){
                if((int)root->key.size() == ORDER - 1){
                    Bnode *newRoot = new Bnode(false);
                    newRoot->child.push_back(root);
                    splitC(newRoot, 0);
                    root = newRoot;
                }

                insertNonFull(root, k);
            }

            bool search(int k){
                return search(root, k);
            }

            void inorder(){
                inorder(root);
                cout << "\n";
            }

            void display(){
                printL(root, 0);
            }
};

int main(){
    int o;

    cout << "Masukkan ORDER B-Tree (>=3): ";
    cin >> o;

    Btree bt(o);

    int n;
    cout << "Jumlah Data: ";
    cin >> n;

    cout << "Masukkan data:\n";
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        bt.insert(a);
    }

    cout << "\n";
    cout << "Inorder: ";
    bt.inorder();

    cout << "\n";
    cout << "Struktur Tree:\n";
    bt.display();

    cout << "\n";

    int k;
    cout << "Cari key: ";
    cin >> k;

    cout << (bt.search(k) ? "Key ditemukan\n" : "Key tidak ditemukan\n");

    return 0;
}