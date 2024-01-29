
// problem link : https://cses.fi/problemset/task/1678
// Hint : Cycle Detection in Directed Graph and print the cycle (Important Concept)
// Apply DFS and save path
//--------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 3e5;
int node, edge;
vector<int> adj[inf];

bool vis[inf];
bool pathVis[inf];
vector<int> cycle;

bool dfs(int src)
{
     vis[src] = 1;
     pathVis[src] = 1;
     cycle.push_back(src);

     for (auto u : adj[src])
     {
          if (!vis[u])
          {
               if (dfs(u) == true)
                    return true;
          }
          else if (pathVis[u])
          { // the node has to be visited in the same path
               cycle.push_back(u);
               return true;
          }
     }

     pathVis[src] = 0; // backtracking
     cycle.pop_back();
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
     }
     for (int i = 1; i <= node; i++)
     {
          if (!vis[i])
          {
               cycle.clear();
               if (dfs(i))
               {
                    vector<int> path;
                    path.push_back(cycle[cycle.size() - 1]);
                    for (int i = cycle.size() - 2; i >= 0; i--)
                    { // from last node to it's occurance again
                         path.push_back(cycle[i]);
                         if (path[0] == cycle[i])
                              break;
                    }
                    cout << path.size() << '\n';
                    reverse(path.begin(), path.end()); // directed graph
                    for (auto u : path)
                         cout << u << ' ';
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
