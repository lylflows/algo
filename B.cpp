#include <bits/stdc++.h>
using namespace std;

int q,num;
string cmd;
bool check=true;
deque <int> dq;

int main()
{
	cin>>q;
	for(int i=0; i<q; i++)
	{
		cin>>cmd;
		if (cmd=="push_back")
		{
			cin>>num;
			if (check==true)
				dq.push_back(num);
			else 
				dq.push_front(num);
		}
		else if (cmd=="push_front")
		{
			cin>>num;
			if (check==true)
				dq.push_front(num);
			else 
				dq.push_back(num);
		}
		else if (cmd=="back")
		{
			if (dq.empty())
				cout<<";("<<endl;
			else
			{
				if (check==true)
				{
					cout<<dq.back()<<endl;
					dq.pop_back();
				}
				else{
					cout<<dq.front()<<endl;
					dq.pop_front();
				}
			}
		}
		else if (cmd=="front")
		{
			if (dq.empty())
				cout<<";("<<endl;
			else
			{
				if (check==true)
				{
					cout<<dq.front()<<endl;
					dq.pop_front();
				}
				else{
					cout<<dq.back()<<endl;
					dq.pop_back();
				}
			}
		}
		else if (cmd=="reverse")
		{
			if (check==true)
				check=false;
			else
				check=true;
		}
	}
	return 0;
}