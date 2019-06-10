#include<iostream>

using namespace std;

int n, k, m, b[1001], x;

int main()
{
	cin>>n;	
	for(int i = 0; i < n; i++)
	{	
		cin >> x;
		if (b[x] == 0)  
            k++;
		b[x]++;
		m = max(m,b[x]);
	}
	cout<<m<<" "<<k;
	return 0;
}