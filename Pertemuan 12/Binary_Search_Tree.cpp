#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key, height;
    Node *left, *right;

    Node(int k) : key(k), height(0), left(nullptr), right(nullptr) {}
};

int getHeight(Node* root){
    return root ? root->height : 0;
}

void updateHeight(Node* root){
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
}

Node* insert(Node* root, int k){
    if(!root) return new Node(k);

    if(k < root->key) root->left = insert(root->left, k);
    else root->right = insert(root->right, k);

    updateHeight(root);
    return root;
}

bool search(Node* root, int k){
    if(!root) return false;

    if(k == root->key) return true;
    if(k < root->key) return search(root->left, k);

    return search(root->right, k);
}

void inorder(Node* root){
    if(!root) return;

    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int findMinNode(Node *root) {
    Node *curr = root;

    while (curr && curr->left) curr = curr->left;

    return curr->key;
}

int findMaxNode(Node *root) {
    Node *curr = root;

    while (curr && curr->right) curr = curr->right;

    return curr->key;
}

int main(){
    Node* root = nullptr;
    
    int n;
    cout << "Jumlah data: ";
    cin >> n;

    cout << "Masukkan data:\n";
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;

        root = insert(root, a);
    }

    cout << "\n";
    cout << "Inorder: ";
    inorder(root);

    cout << "\n";
    cout << "Data minimum: " << findMinNode(root);
    cout << "\n";
    cout << "Data maksimum: " << findMaxNode(root);
    cout << "\n";
    cout << "Panjang root: " << root->height << "\n";

    int k;
    cout << "Cari key: ";
    cin >> k;

    cout << (search(root, k) ? "Data ditemukan\n" : "Data tidak ditemukan\n");

    return 0;
}