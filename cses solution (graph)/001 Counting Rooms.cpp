// problem link : https://cses.fi/problemset/task/1192
// Hint : Connected Compopnent in 2-D Grid. Apply DFS

//-----------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 1050;
int n, m;
char arr[inf][inf]; // for input
bool vis[inf][inf]; 
int dx[] = {1, -1, 0, 0}; // direction array
int dy[] = {0, 0, 1, -1};

bool valid(int x, int y)
{ // may vary per problem
   if (x >= 1 and x <= n and y >= 1 and y <= m and arr[x][y] != '#' and (!vis[x][y]))
      return true;
   return false;
}

void dfs(int sx, int sy)
{ // sx,sy is the coordinate of source
   vis[sx][sy] = 1;
   for (int i = 0; i < 4; i++)
   {
      int nx = sx + dx[i];
      int ny = sy + dy[i];
      if (valid(nx, ny))
         dfs(nx, ny);
   }
}

void Solve()
{
   cin >> n >> m;
   for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
         cin >> arr[i][j];

   int cnt = 0;
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= m; j++)
      {
         if (arr[i][j] == '.' and (!vis[i][j]))
         { // apply dfs if the cell is not visited
            dfs(i, j);
            cnt++; // counting connected components
         }
      }
   }
   cout << cnt << '\n';
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int tests = 1;
   // cin >> tests;
   while (tests--)
      Solve();
   return 0;
}

// in the end, it doesn't even matter
