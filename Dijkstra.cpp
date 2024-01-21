// Dijkstra Allgorithm (SSSP in weighted graph)

const int inf = 1e5 + 125;
int node, edge;
vector<pair<int, int>> adj[inf];
ll cost[inf]; // shortest distance will be stored here
void dijkstra(int src)
{
     for (int i = 1; i <= node; i++)
          cost[i] = 2e18;                                                             // initialization with INFINITY cost
     cost[src] = 0;                                                                   // distance of source is 0
     priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq; // {distance, node}
     pq.push({0, src});
     while (!pq.empty())
     {
          pair<ll, int> at = pq.top(); // current node
          int curNode = at.second;
          ll curDist = at.first;
          pq.pop();
          if (cost[curNode] < curDist)
               continue; // do not need relax operation
          for (auto u : adj[curNode])
          {
               int child = u.first, wt = u.second;
               if (curDist + wt < cost[child])
               {                                   // relax operation
                    cost[child] = curDist + wt;    // update
                    pq.push({cost[child], child}); // push into priority queue
               }
          }
     }
}

// practice problem (Classical)- https://cses.fi/problemset/task/1671/