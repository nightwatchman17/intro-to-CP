// Depth First Search

const int inf = 3e5;
vector<int> adj[inf];
bool vis[inf];

void dfs(int src)
{
     vis[src] = true;
     for (auto u : adj[src])
          if (!vis[u])
               dfs(u);
}