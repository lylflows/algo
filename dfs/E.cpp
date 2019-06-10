#include <bits/stdc++.h>
#define pb push_back
#define cl clear
using namespace std;

bool used[1005];
vector<int> kk;
vector<int> personat;
vector<vector<int> > g;
void dfs(int v){
  personat[v]++;
  used[v] = true;
  for (vector<int>::iterator it=g[v].begin(); it!=g[v].end(); ++it)
      if (!used[*it])
         dfs (*it);
}

int main(){
  int cs,k,n,m,x,y;
  cin>>cs;
  int nk;

  for(int j = 1;  j <= cs; ++j){  
  g.cl();
  kk.cl();
  personat.cl();
  memset(used,0,1005);
    cin>>k>>n>>m;
    g.resize(n+3);
    personat.assign(n+3, 0);
    for(int i = 0; i < k; ++i){
      cin>>nk;
      kk.pb(nk - 1);
    }
  for(int i = 0; i < m; ++i){
    cin>>x>>y;
    g[x - 1].pb(y - 1);
  }
  for(int i = 0; i < k; ++i){
    memset(used, 0, sizeof(used));
    dfs(kk[i]);
  }
  int res = 0;
  for(int i = 0; i < n; ++i){
    if(personat[i] == k)
    res++;
  }
  cout<<"Case "<<j <<": "<<res<<endl;
  }
    return 0;
}