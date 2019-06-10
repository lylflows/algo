#include <iostream>

using namespace std;

int n,m,a[1001],cnt,t;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t;
		a[t]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;i++){
			if(a[i]>a[j])
				swap(a[i],a[j]);
		}
	}
	for(int i=1;i<=1000;i++){
		if(a[i]>0)
			cnt++;
		if(a[i]>m)
			m=a[i];


	}
	cout<<m<<' '<<cnt;
	return 0;

}