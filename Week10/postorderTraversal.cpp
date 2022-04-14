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

vector<int> postOrderiterative(Node *root){
    vector<int> ans;
    stack<pair<Node*, int>> st;
    st.push({root, 0});
    while(!st.empty()){
        pair<Node*, int> deleted = st.top();
        st.pop();
        Node* cur = deleted.first;
        int state = deleted.second;
        if(cur==NULL){
            continue;
        }
        if(state==2){
            ans.push_back(cur->data);
        }else{
            if(state==0){
                st.push({cur, 1});
                st.push({cur->left, 0});
            }
            else if(state==1){
                st.push({cur, 2});
                st.push({cur->right, 0});
            }
        }
    }
    return ans;
}

void postorderRecursive(Node* root, vector<int> ans){
    if(root==NULL) return;
    postorderRecursive(root-left, ans);
    postorderRecursive(root-right, ans);
    ans.push_back(root->data);

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