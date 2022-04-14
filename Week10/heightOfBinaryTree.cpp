// Height of the Binary Tree

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


// Recursive Approach 
int heightOfTreeRecursive(struct Node* root){
    if(root==NULL){
        return 0;
    }
    
    return max(heightOfTreeRecursive(root->left), heightOfTreeRecursive(root->right)) + 1;
}

// Level Order Approach
int heightOfTree(struct Node* root){
    queue<Node*> q;
    q.push(root);
    int level = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            Node* cur = q.front();
            q.pop();
            if(cur->left != NULL){
                q.push(cur->left);
            }
            if(cur->right != NULL){
                q.push(cur->right);
            }
        }
        level++;
    }
    return level;
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