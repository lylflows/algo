#include <iostream>
#include <vector>


using namespace std;
 
 vector<int> v[222];
 bool used[222];
 int time_in[222];
 int time_out[222];
 int timer=1;

 void dfs(int val){
    
    used[val]=true;
    time_in[val] = timer;
    timer++;
   
   for(int i = 0; i < v[val].size(); i++){
      if(used[v[val][i]] == false){
         dfs(v[val][i]);
      }
   }
    
    time_out[val] = timer;
    timer++;
  }

int main(){
   
   int n,l,x,y;
   cin>>n;
   for(int i = 0; i < n; i++){
      cin >> x >> l;
       for(int j = 0; j < l; j++){
        cin >> y;
        v[x].push_back(y);
       }      
   }

    for(int i=1; i<=n; i++){
      if(used[i]==false){
        dfs(i);
      }
    }


   for(int i=1; i<=n; i++){
    cout<<i<<" "<<time_in[i]<<" "<<time_out[i]<<endl;
   }

   return 0;
}