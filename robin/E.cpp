#include <iostream>
#include <string>
using namespace std;

bool check(string &s, int len) {
	for(int i = 0; i < len; ++i) {
		for(int j = i; j < s.size(); j += len) {
			if (s[i] != s[j]) return false;
		}
	}
	return true;
}

int main(){
     string ch,t,s;

     while(1){
     	cin>>s;
     	if(s==".") break;
     	int n = s.size();
     	int ans = 0;
     	for(int i = 1; i <= n; ++i) {
     		if (n % i == 0 && check(s, i)) {
     			ans = i;
     			break;
     		}
     	}
     	cout << n / ans << endl;
     }

	return 0;
}