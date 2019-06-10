#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
#define ull unsigned long long

int f(string s){
   int ans=0;
   ull p=31;
   unordered_map <ull, bool> st;
   for(int i = 0; i < s.size(); i++){
   		ull h = 0;
      	for(int j=i; j < s.size(); j++){
      		h = h * p + (s[j] - 'A' + 1);
      		st[h] = 1;
      	}
   }
   return st.size();

}
  
int main(){

    int n;
    cin>>n;
    string s;

    for(int i=0; i<n; i++){
     cin>>s;
      cout<<f(s)<<endl;
    }

	return 0;
}