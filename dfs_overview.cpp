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
int row, col;
char arr[row][col];
bool vis[row][col];
void dfs(pair<int, int> src)
{
     vis[src.first][src.second] = 1;
     for (int i = 0; i < 4; i++)
     {
          int nx = src.first + dx[i], ny = src.second + dy[i];
          if (nx >= 1 and nx <= row and ny >= 1 and ny <= col and (!vis[nx][ny]) and (arr[nx][ny] != '#'))
               dfs({nx, ny});
     }
}

// Cycle Detection by DFS

bool vis[inf];
bool isCycle(int src, int par)
{
     vis[src] = 1;
     for (auto u : adj[src])
     {
          if (!vis[u])
          {
               if (isCycle(u, src) == true)
                    return true;
          }
          else if (u != par)
               return true;
     }
     return false;
}
//----------------------------------------------------

bool vis[inf];
int IN[inf], OUT[inf];
int timer = 1;
void dfs(int src)
{ // IN TIME and OUT TIME
     vis[src] = 1;
     IN[src] = timer++;
     for (auto u : adj[src])
          if (!vis[u])
               dfs(u);
     OUT[src] = timer++;
}
//------------------------------------------------------

// ## problem
/*
"Given N(1e5) nodes and Q queries. In each Query, given 2 nodes, find whether one node lies in the subree of another node."

    "FACT - if node X is in the Subtree of node Y" -

    IN TIME of X > IN TIME of Y
    and
    OUT TIME of X < OUT TIME of Y
*/
//-------------------------------------------------------
