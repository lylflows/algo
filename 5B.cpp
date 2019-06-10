#include <iostream>
#include <cmath>
using namespace std;
 
struct node{
    int level=0;
    int val;
    node * left;
    node * right;
    node(int x){
        val=x;
        left=NULL;
        right=NULL;
        level=-1;
    }
};
int height=0;
int res=0;
  node * add(node * root,int x){
    node * n=new node(x);
    if(root==NULL){
        root=n;
        root->level=1;
        height=max(height,root->level);
        res++;
    }
    else {
        if(x>root->val){
            if(root->right==NULL){
                root->right=n;
                root->right->level=root->level+1;
                height=max(root->right->level,height);
                res++;
            }
            else{
                add(root->right,x);
            }
        }
        else if(x<root->val){
            if(root->left==NULL){
                root->left=n;
                root->left->level=root->level+1;
                height=max(root->left->level,height);
                res++;
            }
            else{
                add(root->left,x);
            }
        }
    }
    return root;
  }
 
 
int main(){
       int x;
       node * rood=NULL;
       while(true){
        cin>>x;
        if(x==0){break;}
        else{
      rood=add(rood,x);
}
       }
        cout<<res<<endl;
return 0;
 
 
}
