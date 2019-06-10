#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, pair<int,int> > >g;
int arr[101];

int getBig(int v)
{
	if(arr[v] == v) return v;
	return arr[v] = getBig(arr[v]);
}

void doo(int a,int b)
{
	int x = getBig(a);
	int y = getBig(b);
	if(x != y)
	{
		arr[y] = x;
	}
}

int main()
{
	int n;
    
    while(cin>>n) { 
	
	g.clear();
	for(int i = 0;i<n;i++)
	{
		arr[i] = i;
		for(int j = 0;j<n;j++)
		{
			int x;
			cin>>x;
			if(x!=0)
			{
				g.push_back(make_pair(x,make_pair(i,j)));
			}
		}

	} 
     int minDistance = 0;
     sort(g.begin(), g.end());
	for(int i = 0;i<g.size();i++)
	{
	        int a = g[i].second.first;
			int b = g[i].second.second;
			if(a != b && getBig(a) != getBig(b))
			{
                minDistance +=g[i].first;
				doo(a,b);
			}
	}
	cout<<minDistance<<endl;
}
	return 0;
}