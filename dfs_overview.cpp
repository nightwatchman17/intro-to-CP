// DFS
const int inf = 3e5;
vector<int> adj[inf];
vector<bool> vis(inf);

void dfs(int src)
{
     vis[src] = true;
     for (auto u : adj[src])
          if (!vis[u])
               dfs(u);
}
//--------------------------------------------------

// Connected Component size (component size is going to be stored in comp_sz)
const int inf = 3e5;
vector<int> adj[inf];
vector<bool> vis(inf);

int comp_sz = 0;
void dfs(int src)
{
     vis[src] = true;
     comp_sz++;
     for (auto u : adj[src])
          if (!vis[u])
               dfs(u);
}
//----------------------------------------------------

const int inf = 3e5;
vector<int> adj[inf];
vector<bool> vis(inf), colr(inf);

bool dfs(int src, int c)
{ // bi-coloring by DFS
     vis[src] = true;
     colr[src] = c;
     int tmp;
     if (c == 1)
          tmp = 0;
     else
          tmp = 1;
     for (auto u : adj[src])
     {
          if (!vis[u])
          {
               if (dfs(u, tmp) == false)
                    return false;
          }
          else if (colr[src] == colr[u])
               return false;
     }
     return true;
}

// better

const int inf = 3e5;
vector<int> adj[inf];
vector<bool> vis(inf), colr(inf);

bool dfs(int src, int c)
{ // bi-coloring by DFS (Better Version)
     vis[src] = true;
     colr[src] = c;
     for (auto u : adj[src])
     {
          if (!vis[u])
          {
               if (dfs(u, (c ^ 1)) == false) // xor alternates value
                    return false;
          }
          else if (colr[src] == colr[u])
               return false;
     }
     return true;
}
//------------------------------------------------

// Direction arrays

// first four is for 4 directions
int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
// knights move
int kdx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int kdy[] = {2, -2, 2, -2, 1, -1, 1, -1};

// DFS on 2-D Grid (By problem solving)