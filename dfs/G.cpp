#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

vector<int> v[222];
int dist[222];
bool used[222];
int mini=0;
int cnt=1;
queue<int> q;
void bfs(int val){
    q.push(val);
    used[val]=true;
   while(!q.empty()){
   	int cur=q.front();
   	q.pop();
   	for(int i=0; i<v[cur].size(); i++){
   		int to=v[cur][i];
   		if(!used[to]){
   		dist[to]=1+dist[cur];
   			used[to]=true;
   			q.push(to);
   		}
   	}
   }
    
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
    
    cout<<1<<' '<<0<<endl;
    bfs(1);

    for(int i = 2; i <= n; i++){
    	if(used[i]==0)
    		cout<<i<<" "<<-1<<endl;
    	else cout<<i << " " << dist[i]<<endl;
    }


	return 0;
}
