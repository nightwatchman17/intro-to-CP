// problem link : https://cses.fi/problemset/task/1679
// Hint : Topological sorting in DAG(Directed Acyclic Graph)
// sorting on requirements.
// all sources must have inDegree 0
//---------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 3e5;

int node, edge;
vector<int> adj[inf];
bool vis[inf];
int inDeg[inf];
vector<int> seq;

bool bfs()
{
     queue<int> q;
     for (int i = 1; i <= node; i++)
          if (!inDeg[i]) // any node having indegree 0 is source node in this case
               q.push(i);
     while (!q.empty())
     {
          int at = q.front();
          q.pop();
          seq.push_back(at);
          for (auto u : adj[at])
          {
               inDeg[u]--; // removing edges
               if (!inDeg[u])
                    q.push(u); // next added node
          }
     }
     if (seq.size() == node)
          return true; // all node will be visited if topological sorting possible
     return false;     // graph contains cycle
}

void Solve()
{
     cin >> node >> edge;
     while (edge--)
     {
          int u, v;
          cin >> u >> v;
          adj[u].push_back(v);
          inDeg[v]++;
     }
     if (bfs())
     {
          for (auto u : seq)
               cout << u << ' ';
          cout << '\n';
     }
     else
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
