// Level order Tree Traversal
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

vector<int> levelOrderTraversal(Node *root){
    queue<TreeNode*> q;
    q.push(root);
    int level=0;
    vector<vector<int>> ans;
    while(!q.empty()){
        int size = q.size();
        vector<int> vec;
        cout<<level<<": ";
        for(int i=0; i<size;i++){
            TreeNode* deleted = q.front();
            q.pop();
            cout<<deleted->data<<", ";
            vec.push_back(deleted->data);
            if(deleted->left!=NULL){
                q.push(deleted->left);
            }
            if(deleted->right!=NULL){
                q.push(deleted->right);
            }
        }
        cout<<"\n";
        ans.push_back(vec);
        level++;
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