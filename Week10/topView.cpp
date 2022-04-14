// Top View of Binary Tree

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

vector<int> topView(Node *root){
    map<int, int> freq;
    queue<pair<Node*,int>> q;
    q.push({root, 0});
    
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            pair<Node*, int> deleted = q.front();
            q.pop();
            Node* cur = deleted.first;
            int hd = deleted.second;
            if(freq.find(hd) == freq.end()){
                freq[hd] = cur->data;
            }
            if(cur->left != NULL){
                q.push({cur->left, hd-1});
            }
            if(cur->right != NULL){
                q.push({cur->right. hd+1});
            }
        }
    } 
    vector<int> ans;
    for(auto x: freq){
        ans.push_back(x.second);
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