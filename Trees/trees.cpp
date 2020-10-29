#include<bits/stdc++.h>
using namespace std;

struct node{
    node *left,*right;
    int data;
    node(int d){
        data = d;
        left=NULL;
        right=NULL;
    }
};

int ans = INT_MIN;

int diameterOfBinaryTree(node *root){
    if(root){
        int l = diameterOfBinaryTree(root->left), r = diameterOfBinaryTree(root->right);
        ans = max(ans,l+r+1);
        return max(l,r)+1;
    }
    return 0;
}

int maxSumPathAnyNode(node *root){
    if(root){
        int l = maxSumPath(root->left), r = maxSumPath(root->right);
        ans = max(ans,l+r+root->data);
        return max(max(l,r)+root->data,root->data);
    }
    return 0;
}

int maxSumPathLeafNode(node *root){
    if(root){
        int l = maxSumPath(root->left), r = maxSumPath(root->right);
        ans = max(ans,l+r+root->data);
        return max(l,r)+root->data;
    }
    return 0;
}

int main(){
    node *root = new node(1);
    root->right = new node(2);
    root->left = new node(3);
    root->left->right = new node(4);
    root->left->left = new node(5);
    diameterOfBinaryTree(root);
    cout<<ans<<endl;
    ans = INT_MIN;
    maxSumPathAnyNode(root);
    cout<<ans<<endl;
    ans = INT_MIN;
    maxSumPathLeafNode(root);
    cout<<ans<<endl;
}