// problem : https://cses.fi/problemset/task/1683

const int inf = 2e5 + 123;

int node, edge, cnt;
vector<int> adj[inf], adjT[inf];
bool vis[inf];
vector<int> ordering, scc;
vector<int> res;

void dfs1(int src)
{ // first dfs for ordering nodes according to their out time
     vis[src] = 1;
     for (auto u : adj[src])
          if (!vis[u])
               dfs1(u);
     ordering.push_back(src);
}

void dfs2(int src)
{ // dfs2 in transpose graph
     vis[src] = 1;
     for (auto u : adjT[src])
          if (!vis[u])
               dfs2(u);
     scc.push_back(src);
}

void Solve()
{
     cin >> node >> edge;
     res.resize(node + 123);
     while (edge--)
     {
          int u, v;
          cin >> u >> v;
          adj[u].push_back(v);
          adjT[v].push_back(u);
     }
     for (int i = 1; i <= node; i++)
     {
          if (!vis[i])
               dfs1(i);
     }
     memset(vis, 0, sizeof vis);
     for (int i = node - 1; i >= 0; i--)
     {
          if (!vis[ordering[i]])
          {
               scc.clear();
               cnt++;
               dfs2(ordering[i]);
               for (auto u : scc)
                    res[u] = cnt;
          }
     }
     cout << cnt << '\n';
     for (int i = 1; i <= node; i++)
          cout << res[i] << ' ';
     cout << '\n';
}

//////////////////////