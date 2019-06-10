#include <iostream>

using namespace std;

int n, a[100005], m, x, sum, l, r;

int main()
{
	cin>>n;
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		sum += a[i];
		a[i] = sum;
	}
	cin >> m;
	while(m--)
	{        
		cin >> x;
		l = 0,r = n;
		while(l<r)
		{
			int mid = (l + r) / 2;
			if (a[mid] < x)	
                l = mid + 1;
			else	
                r = mid;	
		}
		cout << r << '\n';
	}
	return 0;	
}