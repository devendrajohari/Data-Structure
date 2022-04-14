// Left View of Binary Tree

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
}

Node* insert(Node* root, int item){
    if(root==NULL){
        Node* ptr = new Node;
        ptr->data = item;
        ptr->left = NULL;
        ptr->right = NULL;
        return ptr;
    }
    if(item<=root->data){
        root->left = insert(root->left, item);
    }else{
        root->right = insert(root->right, item);
    }
    return root;
}

vector<int> leftView(Node *root){
    if(root==NULL){
        return {};
    }
    queue<Node*> q;
    q.push(root);
    vector<int> ans;
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            Node* deleted = q.front();
            q.pop();
            if(i==0){
                ans.push_back(deleted->data)
            }
            if(deleted->left!=NULL){
                q.push(deleted->left);
            }
            if(deleted->right!=NULL){
                q.push(deleted->right);
            }
        }
    } 
    return ans;
}


int main(){
    Node* root = new Node();
    int n;
    cout<<"Enter no of nodes : ";
    cin>>n;
    int item;    
    for(int i=0; i<n; i++){
        cout<<"Enter item : ";
        cin>>item;
        root = insertNode(root, item);
    }
}