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