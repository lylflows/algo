#include <iostream>
#include <vector>
using namespace std;
vector<int >v;
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
   
void dfs(node * root){
  if(root->left==NULL && root->right==NULL){
    v.push_back(root->val);
  }
  else
    {
      if(root->left!=NULL && root->right!=NULL) {
        dfs(root->left);
        dfs(root->right);
      }
      else if(root->left!=NULL) dfs(root->left);
      else if(root->right!=NULL) dfs(root->right);
}
}
 
int main(){
    node * root=NULL;
    int x;
    while(true){
        cin>>x;
        if(x==0){
            break;
        }
        else {
            root=add(root,x);
        }
    }
       dfs(root);    
    for(int i=0; i<v.size();i++){
      cout<<v[i]<<" ";
    }
    return 0;
}