#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
struct node{
       node *left;
       node * right;
       int val;
       node(int x){
        left=NULL;
        right=NULL;
        val=x;
       }
   };
    node * add(node * root,int x){
        node * n=new node(x);
        if(root==NULL){
            root=n;
 
        }
        else
        {
         if(x>root->val){
            if(root->right==NULL){
                root->right=n;
 
            }
            else {
                add(root->right,x);
            }
        }
        else if(x<root->val){
            if(root->left==NULL){
                root->left=n;
            }
            else {
                add(root->left,x);
            }
        }
    }
        return root;
   }
   void f(node * root){
        if(root->left!=NULL && root->right==NULL){
            v.push_back(root->val);
            f(root->left);
        }
        else if(root->left==NULL && root->right!=NULL){
            v.push_back(root->val);
            f(root->right);
        }
        else if(root->left!=NULL && root->right!=NULL){
            f(root->left);
            f(root->right);
        }
   }
int main(){
 
    int x;
    node *root=NULL;
    while(true){
        cin>>x;
        if(x==0){
            break;
        }
        else {
            root=add(root,x);
        }
    }
      f(root);
      sort(v.begin(),v.end());
      for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
      }
    return 0;
}