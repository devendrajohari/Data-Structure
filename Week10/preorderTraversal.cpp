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

vector<int> preOrderiterative(Node *root){
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
        if(state==0){
            ans.push_back(cur->data);
            st.push({cur, 1});
        }else{
            if(state==1){
                st.push({cur, 2});
                st.push({cur->left, 0});
            }
            else if(state==2){
                st.push({cur->right, 0});
            }
        }
    }
    return ans;
}

void preorderRecursive(Node* root, vector<int> ans){
    if(root==NULL) return;
    ans.push_back(root->data);
    preorderRecursive(root-left, ans);
    preorderRecursive(root-right, ans);

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