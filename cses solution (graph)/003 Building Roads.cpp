
// problem link :https://cses.fi/problemset/task/1666/
// Hint : Counting Connected Component in a Graph. Store the nodes if dfs is called from that node
//---------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 3e5;
int node, edge;
vector<int> adj[inf]; // adjacency list
bool vis[inf];

void dfs(int src)
{
     vis[src] = true;
     for (auto u : adj[src])
          if (!vis[u])
               dfs(u);
}

void Solve()
{
     cin >> node >> edge;
     while (edge--)
     {
          int u, v;
          cin >> u >> v;
          adj[u].push_back(v);
          adj[v].push_back(u);
     }
     int cmp = 0;
     vector<int> road;
     for (int i = 1; i <= node; i++)
     {
          if (!vis[i])
          {
               dfs(i);
               cmp++;             // counting connected component
               road.push_back(i); // storing the node
          }
     }
     cout << cmp - 1 << '\n';
     for (int i = 1; i < road.size(); i++)
          cout << road[i] << ' ' << road[0] << '\n';
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int tests = 1;
     // cin >> tests;
     while (tests--)
          Solve();
     return 0;
}

// in the end, it doesn't even matter
