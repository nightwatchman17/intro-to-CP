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

void bfs(pair<int, int> src)
{
     memset(vis, 0, sizeof vis);
     queue<pair<int, int>> q;
     q.push({src.first, src.second});
     vis[src.first][src.second] = 1;
     while (!q.empty())
     {
          pair<int, int> at = q.front();
          q.pop();
          for (int i = 0; i < 4; i++)
          {
               int nx = at.first + dx[i];
               int ny = at.second + dy[i];
               if (nx >= 1 and nx <= row and ny >= 1 and ny <= col and (!vis[nx][ny]) and (arr[nx][ny] != '#'))
               {
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
               }
          }
     }
}
//----------------------------------------------

// 0-1 BFS

// RElated Problem : https://codeforces.com/contest/1900/problem/C

const int inf = 3e5 + 100;
vector<pair<int, int>> adj[inf];
int cost[inf];
int node;
void bfs_01(int src)
{
     for (int i = 0; i < node + 10; i++)
          cost[i] = INT_MAX; // initializing with infinity
     deque<int> dq;
     dq.push_front(src);
     cost[src] = 0;
     while (!dq.empty())
     {
          int at = dq.front();
          dq.pop_front();
          for (auto u : adj[at])
          {
               int child = u.first;
               int wt = u.second;
               if (cost[at] + wt < cost[child])
               {
                    cost[child] = cost[at] + wt;
                    if (wt == 1)
                         dq.push_back(child);
                    else
                         dq.push_front(child);
               }
          }
     }
}

//-------------------------------------------

// Dijkstra Allgorithm (SSSP in weighted graph)

const int inf = 3e5;
int node, edge;
vector<pair<int, int>> adj[inf];
ll dist[inf];

void dijkstra(int src)
{
     for (int i = 0; i < inf; i++)
          dist[i] = 2e18;
     priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
     pq.push({0LL, src});
     dist[src] = 0;
     while (!pq.empty())
     {
          pair<ll, int> at = pq.top();
          ll curDis = at.first;
          int curNode = at.second;
          pq.pop();
          if (dist[curNode] < curDis)
               continue;
          for (auto u : adj[curNode])
          {
               int child = u.first;
               ll wt = u.second;
               if (curDis + wt < dist[child])
               {
                    dist[child] = curDis + wt;
                    pq.push({dist[child], child});
               }
          }
     }
}

// practice problem (Classical)- https://cses.fi/problemset/task/1671/

//-------------------------------------------------

// ## a sequence is valid in BFS Traversal or not

// If a node X is visited before a node Y, then it's safe to assume X appears before Y in every adjacency list.
// So initially we can sort each list, using as comparator the positions in the Given Sequence.
// Then we can just run a BFS and check if we visit the nodes in the given order.

int node;
vector<int> adj[inf];
bool vis[inf];
vector<int> bfs_path;
int pos[inf];
void bfs(int src)
{
     queue<int> q;
     q.push(src);
     vis[src] = 1;
     bfs_path.push_back(src);
     while (!q.empty())
     {
          int at = q.front();
          q.pop();
          for (auto u : adj[at])
          {
               if (!vis[u])
               {
                    q.push(u);
                    vis[u] = 1;
                    bfs_path.push_back(u);
               }
          }
     }
}
bool cmp(int a, int b)
{
     if (pos[a] < pos[b])
          return true;
     return false;
}

void Solve()
{
     cin >> node;
     for (int i = 1; i < node; i++)
     {
          int u, v;
          cin >> u >> v;
          adj[u].push_back(v);
          adj[v].push_back(u);
     }

     vector<int> given;
     for (int i = 1; i <= node; i++)
     {
          int x;
          cin >> x;
          given.push_back(x);
          pos[x] = i;
     }

     for (int i = 1; i <= node; i++) // sort adjacency list according to input order
          sort(adj[i].begin(), adj[i].end(), cmp);

     bfs(1);

     if (bfs_path == given)
          cout << "Yes\n";
     else
          cout << "No\n";
}

// codeforcce : Valid BFS problem
//-------------------------------------------------------