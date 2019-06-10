#include <iostream>

using namespace std;
  
  char arr[222][222];
  bool used[222][222]; 

  void dfs(int x,int y){

     used[x][y]=true;

     if(used[x - 1][y + 1] == false && arr[x - 1][y + 1]=='@') dfs(x - 1, y + 1);
     if(used[x][y + 1] == false && arr[x][y + 1]=='@') dfs(x, y + 1);
     if(arr[x + 1][y + 1] == '@' && used[x + 1][y + 1] == false ) dfs(x + 1, y + 1);
     
     if(arr[x - 1][y] == '@' && used[x - 1][y] == false) dfs(x - 1, y);
     if(arr[x + 1][y] == '@' && used[x + 1][y] == false) dfs(x + 1, y);

     if(arr[x - 1][y - 1] == '@' && used[x - 1][y - 1] == false) dfs(x - 1, y - 1);
     if(arr[x][y - 1] == '@' && used[x][y - 1] == false) dfs(x, y - 1);
     if(arr[x + 1][y - 1] == '@' && used[x + 1][y - 1] == false) dfs(x + 1, y - 1);

}

int main(){

   while(true){
      int n, m;  
      int cnt=0;
      cin>>n>>m;
      if(m == 0) break;
         

      for(int i=1; i<=n; i++){
      	for(int j=1; j<=m; j++){
      		used[i][j]=false;

           cin>>arr[i][j];
       	}
      }
       	
      for(int i=1; i<=n; i++){
      	for(int j=1; j<=m; j++){
      		if(arr[i][j]=='@' && used[i][j]==false){
      			dfs(i,j);
        		cnt++;
        	   }
        	}
      }
         cout<<cnt<<endl;
   }

	return 0;
}