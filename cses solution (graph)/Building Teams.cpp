// problem link : https://cses.fi/problemset/task/1668
// Hint : Bi coloring a graph
// can be done by DFS or BFS
//--------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 3e5;
vector<int> adj[inf];
bool vis[inf];
bool colr[inf]; // store coloring

bool bfs(int src, int c)
{ // bipartite checking by BFS
     queue<int> q;
     q.push(src);
     vis[src] = true;
     colr[src] = 1;

     while (!q.empty())
     {
          int at = q.front();
          q.pop();
          for (auto u : adj[at])
          {
               if (!vis[u])
               {
                    q.push(u);
                    colr[u] = (colr[at] ^ 1); // alternate color
                    vis[u] = true;
               }
               else if (colr[at] == colr[u]) // check color of parent
                    return false;
          }
     }
     return true;
}

void Solve()
{
     int n, e;
     cin >> n >> e;
     while (e--)
     {
          int u, v;
          cin >> u >> v;
          adj[u].push_back(v);
          adj[v].push_back(u);
     }
     for (int i = 1; i <= n; i++)
     {
          if (!vis[i])
          {
               bool f = bfs(i, 1);
               if (!f)
               {
                    cout << "IMPOSSIBLE\n";
                    return;
               }
          }
     }
     for (int i = 1; i <= n; i++)
     {
          if (!colr[i])
               cout << 1 << ' ';
          else
               cout << 2 << ' ';
     }
     cout << '\n';
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int tests = 1;
     // cin >> tests;
     while (tests--)
     {
          Solve();
     }
     return 0;
}

///////////////////////////////
///// by dfs //////////////////
///////////////////////////////

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 3e5;

int node, edge;
vector<int> adj[inf];
bool vis[inf];
bool colr[inf]; // store coloring

bool dfs(int src, int c)
{ // bicoloring
     vis[src] = true;
     colr[src] = c;
     for (auto u : adj[src])
     {
          if (!vis[u])
          {
               if (dfs(u, (c ^ 1)) == false) // xor toggles the value of c
                    return false;
          }
          else if (colr[u] == colr[src]) // check color of parent
               return false;
     }
     return true;
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
               bool f = dfs(i, 0);
               if (!f)
               {
                    cout << "IMPOSSIBLE\n";
                    return;
               }
          }
     }

     for (int i = 1; i <= node; i++)
     {
          if (!colr[i])
               cout << 1 << ' ';
          else
               cout << 2 << ' ';
     }
     cout << '\n';
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
