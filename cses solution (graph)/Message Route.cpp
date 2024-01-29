// problem link : https://cses.fi/problemset/task/1667
// Hint : single source shortest path in a graph. apply BFS.
// store parent nodes. path retrival
//--------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 3e5;
int node, edge;
vector<int> adj[inf];
int lev[inf];
int par[inf];
void bfs(int src)
{
     memset(lev, -1, sizeof lev);
     queue<int> q;
     q.push(src);
     lev[src] = 0; // can implement initializing by 1 also
     par[src] = -1;
     while (!q.empty())
     {
          int at = q.front();
          q.pop();
          for (auto u : adj[at])
          {
               if (lev[u] == -1)
               {
                    q.push(u);
                    lev[u] = lev[at] + 1;
                    par[u] = at;
               }
          }
     }
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

     bfs(1);

     vector<int> path;
     if (lev[node] == -1)
          cout << "IMPOSSIBLE\n";
     else
     {
          int target = node;
          path.push_back(target);
          while (par[target] != -1)
          {
               path.push_back(par[target]);
               target = par[target];
          }
          reverse(path.begin(), path.end());
          cout << lev[node] + 1 << '\n'; // +1 is for number of computers
          for (auto u : path)
               cout << u << ' ';
          cout << '\n';
     }
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
