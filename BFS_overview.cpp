// Breadth First Search

const int inf = 3e5;
vector<int> adj[inf];
vector<bool> vis(inf);
vector<int> lev(inf);

void bfs(int src)
{ // lev vector stores the distance from source
     queue<int> q;
     q.push(src);
     vis[src] = true;
     lev[src] = 0;
     while (!q.empty())
     {
          int at = q.front();
          q.pop();
          for (auto u : adj[at])
          {
               if (!vis[u])
               {
                    q.push(u);
                    vis[u] = true;
                    lev[u] = lev[at] + 1;
               }
          }
     }
}

//--------------------------------------------

//"Path Sequenc"

const int inf = 3e5;
vector<int> adj[inf];
vector<bool> vis(inf);
vector<int> lev(inf), par(inf);

void bfs(int src)
{ // par vector stores parent of a node
     queue<int> q;
     q.push(src);
     vis[src] = true;
     lev[src] = 0;
     par[src] = -1;
     while (!q.empty())
     {
          int at = q.front();
          q.pop();
          for (auto u : adj[at])
          {
               if (!vis[u])
               {
                    q.push(u);
                    vis[u] = true;
                    lev[u] = lev[at] + 1;
                    par[u] = at;
               }
          }
     }
}

int src = 1, target;
cin >> target;
bfs(src);
vector<int> s_path;
s_path.push_back(target);
while (par[target] != -1)
{
     s_path.push_back(par[target]);
     target = par[target];
}
reverse(s_path.begin(), s_path.end());
for (auto u : s_path)
     cout << u << ' ';
cout << '\n';

//-----------------------------------------------------------

// Bi partite coloring by BFS

const int inf = 3e5;
vector<int> adj[inf];
vector<bool> vis(inf);
vector<int> colr(inf);

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
                    colr[u] = (colr[at] ^ 1);
                    vis[u] = true;
               }
               else if (colr[at] == colr[u])
                    return false;
          }
     }
     return true;
}

//-----------------------------------------

// MULTIPLE source BFS
//** push all sources into the queue at first

// BFS on 2-D Grid

// Direction arrays

// first four is for 4 directions
int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
// knights move
int kdx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int kdy[] = {2, -2, 2, -2, 1, -1, 1, -1};
