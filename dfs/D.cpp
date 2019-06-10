#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int f = 0,s = 1, t = 2;
int main()
{  
    int n;
    while (cin >> n, n != 0)
    {
        vector<vector<int>> G(n);
        vector<int> color(n, t);
        bool is = true;
        int k;
        cin >> k;
        for(int i = 0; i < k; i++){
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        queue<int> q; 
        color[0] = f;
        q.push(0);
        while (!q.empty() && is)
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < G[u].size(); ++i)
            {
               // 0:  1 2
               // 1: 0 2
               // 2: 0 1
                int cur = G[u][i];
                if (color[cur] == color[u])
                {
                    is = false;
                    break;
                }
                else if (color[cur] == t)
                {
                    color[cur] = 1 - color[u]; 
                    q.push(cur);
                }
            }
        }
        if (is)
            cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;
    }
    return 0;
}