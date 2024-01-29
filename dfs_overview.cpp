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
// cycle findinding and print cycle (any one e cycle only)
// problem link -https://cses.fi/problemset/result/8290525/
const int inf = 2e5;
int node, edge;
vector<int> adj[inf];
vector<int> _cycle;
bool vis[inf];
bool dfs(int src, int par)
{
     vis[src] = 1;
     _cycle.push_back(src);
     for (auto u : adj[src])
     {
          if (!vis[u])
          {
               if (dfs(u, src) == true)
                    return true;
          }
          else if (u != par)
          {
               _cycle.push_back(u);
               return true;
          }
     }
     _cycle.pop_back();
     return false;
}

// if this function return true then the _cycle vector should be printed from the last ,until it finds the last node again

//------------------------------------
//---------------------------------------------------
// cycle detection in directed graph by DFS

//------------------------------------------------------

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
// "Given N(1e5) nodes and Q queries. In each Query, given 2 nodes, find whether one node lies in the subree of another node."

//     "FACT - if node X is in the Subtree of node Y" -

//     IN TIME of X > IN TIME of Y
//     and
//     OUT TIME of X < OUT TIME of Y
//-------------------------------------------------------

//--------------------------
// store Subtree size of all nodes using DFS

// subtree size of Root node = 1 + Subtree size of it's Childs

bool vis[inf];
int subtree_size[inf];
int dfs_SubtreeSize(int src)
{
     vis[src] = 1;
     int cur_sz = 1;
     for (auto u : adj[src])
          if (!vis[u])
               cur_sz += dfs_SubtreeSize(u);
     return subtree_size[src] = cur_sz;
}

//---------------------------------------------
//-------------------------------------------------

// ## a sequence is valid in DFS Traversal or not

// If a node X is visited before a node Y, then it's safe to assume X appears before Y in every adjacency list.
// So initially we can sort each list, using as comparator the positions in the Given Sequence.
// Then we can just run a BFS and check if we visit the nodes in the given order.

using ll = long long;
const int inf = 1e5 + 100;
int node, edge;
vector<int> adj[inf];
bool vis[inf];
vector<int> dfs_path, given;
int pos[inf];

void dfs(int src)
{
     vis[src] = 1;
     dfs_path.push_back(src); // dfs path visited
     for (auto u : adj[src])
          if (!vis[u])
               dfs(u);
}
bool cmp(int a, int b)
{
     if (pos[a] < pos[b])
          return true;
     return false;
}
void Solve()
{
     cin >> node >> edge;
     for (int i = 1; i <= node; i++)
     {
          int x;
          cin >> x;
          given.push_back(x);
          pos[x] = i; // storing the node order of input (positions)
     }
     while (edge--)
     {
          int u, v;
          cin >> u >> v;
          adj[u].push_back(v);
          adj[v].push_back(u);
     }
     for (int i = 1; i <= node; i++) // sort adjacency list according to input order
          sort(adj[i].begin(), adj[i].end(), cmp);
     dfs(1);
     if (given == dfs_path)
          cout << 1 << '\n';
     else
          cout << 0 << '\n';
}

//---------------------------------------------------
