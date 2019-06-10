#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;

long long n, m, x, y;
vector<long long> g[100000];
vector<int> ans;
bool used[100000];
   void dfs(int v){
   used[v]=1;
   for(int i = 0; i < int(g[v].size()); i++){
   		if(used[g[v][i]]==0)
   			dfs(g[v][i]);
   }
   ans.pb(v+1);
}

int main(){
   

   while(true){
       cin >> n >> m;
       if(n == 0 && m == 0) break;
       ans.clear();
       for(int i=0; i<=n; i++){
       	g[i].clear();
       	used[i] = 0;
       }

       for(int i = 0; i < m; i++){
       		
       		cin >> x >> y;
       		x--;
       		y--;
       		g[x].push_back(y);

       }
       
       for(int  i = 0; i < n; i++){
       	if(used[i]==0)
       		dfs(i);
       }
       reverse(ans.begin(),ans.end());
       for(int i = 0; i < ans.size(); i++){
       	cout<<ans[i]<<" ";
       }
       cout<<endl;
   }
 

	return 0;
}