#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
  string s, t; 
  int n;
  cin>>n;

while(n--){
   int x,y;
   cin>>x>>y;
   cin>>s;
   const int p = 31;
   vector<long long> p_pow (x);
   p_pow[0] = 1;
   for (size_t i=1; i<x; ++i)
   	p_pow[i] = p_pow[i-1] * p;
   vector<long long> h (x);
   for (size_t i=0; i<x; ++i){
   	h[i] = (s[i] - 'a' + 1) * p_pow[i];
   	if (i)  h[i] += h[i-1];
   }
   set<long long>st;
   for (size_t i = 0; i  < x-y+1; ++i)
   { 
	long long cur_h = h[i+y-1];
	if (i)  cur_h -= h[i-1];
	cur_h*=p_pow[x-i-y];
	// cout<<cur_h<<" ";
	// if (cur_h == h_s * p_pow[i])
		st.insert(cur_h);
	// cout<<cur_h<<" ";

}   
     cout<<st.size()<<endl;
}
	return 0;
}