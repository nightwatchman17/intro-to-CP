// problem link : https://cses.fi/problemset/task/1669
// Hint : Cycle Detection in undirected Graph and print the cycle
// Apply DFS
//--------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 3e5;

int node, edge;
vector<int> adj[inf];
bool vis[inf];
vector<int> cycle; // storing cycle

bool dfs(int src, int par)
{
     vis[src] = 1;
     cycle.push_back(src);
     for (auto u : adj[src])
     {
          if (!vis[u])
          {
               if (dfs(u, src) == true)
                    return true;
          }
          else if (u != par)
          { // back edge
               cycle.push_back(u);
               return true;
          }
     }
     cycle.pop_back(); // out of cycle
     return false;
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
     for (int i = 1; i <= node; i++)
     {
          if (!vis[i])
          {
               cycle.clear();
               if (dfs(i, -1))
               {
                    vector<int> path;
                    path.push_back(cycle[cycle.size() - 1]);

                    for (int i = cycle.size() - 2; i >= 0; i--)
                    {
                         path.push_back(cycle[i]); // print from last element untill same occurance
                         if (cycle[i] == path[0])
                              break;
                    }

                    cout << path.size() << '\n';
                    for (auto u : path)
                         cout << u << ' ';
                    cout << '\n';
                    return;
               }
          }
     }
     cout << "IMPOSSIBLE\n";
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
