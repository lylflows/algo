#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int n, cnt=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(a[i]<a[n-1] && a[i]>a[0]) cnt++;
	}
	cout<<cnt;
}