#include <iostream>
#include <cmath>
using namespace std;
struct node{
  int val;
  int level = 0;
  node * left;
  node * right;
  node(int x){
    val = x;
    left = NULL;
    right = NULL;
    level = -1;
  }
};
int height = 0;
node * add(int x,node * root){
  node *nd = new node(x);
  if(root == NULL){
    root = nd;
    root->level=1;
    height = max(height,root->level);
  }else{
    if(x<root->val){
      if(root->left == NULL){
        root->left = nd;
        root->left->level = root->level+1;
        height = max(height,root->left->level);
      }else{
        add(x,root->left);
      }
    }else{
      if(x>root->val){
        if(root->right==NULL){
          root->right = nd;
          root->right->level = root->level+1;
          height = max(height,root->right->level);
        }else{
          add(x,root->right);
        }
      }
    }
  }
  return root;
}
     int k=0;
    void f(node * root){
     int length=height;
   
   
    node * cur=root;
    if(cur!=NULL){
     if(cur->left->level-cur->right->level>1) k++;
    }
     f(cur->left);
     f(cur->right);
         
   }
 
int main(){
  node * root = NULL;
  while(true){
    int x;
    cin>>x;
    if(x==0){
      break;
    }else{
    root=add(x,root);
    }
  }
  if(k>0){
    cout<<"YES";
 
  }
  else cout<<"NO";
  return 0;
}
