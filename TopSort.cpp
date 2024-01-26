// Theory

// Ordering Objects Based on Requirement
// U --> V (U has to be done before V)
// Graph Must be Directed Acyclic to have valid sorting
// In the sorted list of Topology Sorting, all edges appears from left to right. By this property we can determine, whethe a sequence is valid or not for a given graph
// Kahn's Algorithm - way of Topological Sorting

// 1) Each Node we choose with in degree 0
// 2) Remove all the edges of this Node

const int inf = 2e5;
int node, edge;
vector<int> adj[inf];
int inDeg[inf];
vector<int> seq;
bool TopSort()
{
     queue<int> q;
     for (int i = 1; i <= node; i++)
          if (inDeg[i] == 0)
               q.push(i);
     while (!q.empty())
     {
          int at = q.front();
          seq.push_back(at);
          q.pop();
          for (auto u : adj[at])
          {
               inDeg[u]--;
               if (inDeg[u] == 0)
                    q.push(u);
          }
     }
     if (seq.size() == node)
          return true;
     return false;
}
cin >> node >> edge;
while (edge--)
{
     int u, v;
     cin >> u >> v;
     adj[u].push_back(v);
     inDeg[v]++;
}

//============================================
