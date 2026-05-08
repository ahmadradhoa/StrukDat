#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *left, *right;
    
    Node(int n){
        val = n;
        left = right = NULL;
    }
};

Node* insert(Node* root, int n){
    if(!root) return new Node(n);

    if(n < root->val) root->left = insert(root->left, n);
    else root->right = insert(root->right, n);

    return root;
}

void Preorder(Node* root){
    if(!root) return;

    cout << root->val << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(Node* root){
    if(!root) return;

    Inorder(root->left);
    cout << root->val << " ";
    Inorder(root->right);
}

void Postorder(Node* root){
    if(!root) return;

    Postorder(root->left);
    Postorder(root->right);
    cout << root->val << " ";
}

void levelOrder(Node* root){
    if(!root) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        cout << curr->val << " ";

        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}

int main(){
    Node* root = NULL;
    int n;
    cin >> n;

    while(n--){
        int x;
        cin >> x;

        root = insert(root, x);
    }

    cout << "PreOrder\t:";
    Preorder(root);
    cout << "\n";

    cout << "InOrder\t\t:";
    Inorder(root);
    cout << "\n";

    cout << "PostOrder\t:";
    Postorder(root);
    cout << "\n";

    cout << "LevelOrder\t:";
    levelOrder(root);
    cout << "\n";

    return 0;
}