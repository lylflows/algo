#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){

  int n;
  cin>>n;
  string s;
  vector<string> v;
  map<int,int> m;
  map<string,int> :: iterator it;
  for(int i  = 0; i < n; i++){
      cin>>s;
      int p=31;
      long long h=0;
      for(int j=0; j<s.size(); j++){
        h = h * p + (s[j] - 'a' + 1);
          
      }
      m[h] ++;

      
      if(m[h] == 1)
        cout<<"OK"<<endl;
      else cout<<s<<m[h]-1<<endl;
  }
    
  



	return 0;
}