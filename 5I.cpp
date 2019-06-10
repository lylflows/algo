#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
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
    int b[100100];
     
   node * add(node * root,int x){
        node * n=new node(x);
        if(root==NULL){
            root=n;
            b[x]=1;
        }
        else
        {
         if(x>root->val){
            if(root->right==NULL){
                root->right=n;
              b[x]=1;
            }
            else {
                add(root->right,x);
            }
        }
        else if(x<root->val){
            if(root->left==NULL){
                root->left=n;
            b[x]=1;
            }
            else {
                add(root->left,x);
            }
        }
        else {
            b[x]+=1;
        }
    }
        return root;
   }
 
int main(){
    int cnt=0;
    node * root=NULL;
    int x;
    while(true){
        cin>>x;
        if(x==0){
            break;
        }
        else {
            root=add(root,x);
        cnt++;
        }
    }
     for(int i=0; i<100100; i++){
      if(b[i]!=0){
        cout<<i<<" "<<b[i]<<endl;
      }
     }
    return 0;
   
}