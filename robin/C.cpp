#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
 int n ;
 cin>>n;
 while(n!=0){
  map<string,int> m;
  int maxcnt = 0 ;
  vector<string> v(n);
  for(int i =0 ; i<n;i++){
   string l;
   cin>>l;
   v[i]=l;
  }
  string t;
  cin>>t;
  int p = 31;
  vector<long long> p_pow(t.size());
  p_pow[0]=1;
  for(int i = 1 ;i < t.size();i++){
   p_pow[i]=p_pow[i-1]*p;
  }
  vector<long long> h(t.size());
  for(int i = 0 ; i<t.size();i++){
   h[i]=(t[i]-'a'+1)*p_pow[i];
   if(i>0){
    h[i]=h[i]+h[i-1];
   }
  }
  for(int i = 0 ; i<v.size();i++){
   int cnt = 0 ;
   string z=v[i];
   long long h_v = 0;
   for(size_t o = 0 ; o<z.size();o++){
    h_v=h_v+(z[o]-'a'+1)*p_pow[o];
   }
   for(size_t j = 0 ; j<t.size()-z.size()+1;j++){
    long long cur_h = h[j+z.size()-1];
    if(j>0){
     cur_h = cur_h -h[j-1];
    }
    if(cur_h == h_v*p_pow[j]){
     cnt++;
    }
   }
   if(cnt>maxcnt){
    maxcnt=cnt;
   }
   m[z]=cnt;
  }
  cout<<maxcnt<<endl;
  for(int i = 0 ; i<v.size();i++){
   string q=v[i];
   if(m[q]==maxcnt){
    cout<<q<<endl;
   }
  }
  cin>>n;
 }
 return 0 ; 
}