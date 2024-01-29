// problem link :
// Hint : Shortest Path in 2-D Grid. Apply BFS. Store Parent Cell
// Path Retrival in 2-D Grid (Important concept)
//--------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1050;
int n, m;
char arr[inf][inf];   // input
char moves[inf][inf]; // storing moves from parent cell (important concept)
int lev[inf][inf];    // for shortest path

int dx[] = {1, -1, 0, 0}; // direction array
int dy[] = {0, 0, 1, -1};
char dxy_char[] = {'D', 'U', 'R', 'L'}; // direction by character

pair<int, int> st, goal;
string path = ""; // path retrival

bool valid(int x, int y)
{ // conditions may vary
     if (x >= 1 and x <= n and y >= 1 and y <= m and lev[x][y] == -1 and arr[x][y] != '#')
          return true;
     return false;
}

void bfs(int sx, int sy)
{
     memset(lev, -1, sizeof(lev)); // initially
     queue<pair<int, int>> q;
     q.push({sx, sy});
     lev[sx][sy] = 0; // level of sorce is 0

     while (!q.empty())
     {
          pair<int, int> at = q.front();
          if (at.first == goal.first and at.second == goal.second)
          {                                     // reached at goal.so there must be a path
               int x = at.first, y = at.second; // current cell
               while (1)
               { // going backwards
                    path += moves[x][y];
                    if (moves[x][y] == 'R')
                         y--;
                    else if (moves[x][y] == 'L')
                         y++;
                    else if (moves[x][y] == 'U')
                         x++;
                    else if (moves[x][y] == 'D')
                         x--;
                    if (x == st.first and y == st.second) // reached at start
                         break;
               }
               reverse(path.begin(), path.end()); // actual path
               return;
          }
          q.pop();
          for (int i = 0; i < 4; i++)
          {
               int nx = at.first + dx[i];
               int ny = at.second + dy[i];
               if (valid(nx, ny))
               {
                    q.push({nx, ny});
                    lev[nx][ny] = lev[at.first][at.second] + 1;
                    moves[nx][ny] = dxy_char[i]; // saving current direction move
               }
          }
     }
}

void Solve()
{
     cin >> n >> m;

     for (int i = 1; i <= n; i++)
     {
          for (int j = 1; j <= m; j++)
          {
               cin >> arr[i][j];
               if (arr[i][j] == 'A')
                    st = {i, j};
               if (arr[i][j] == 'B')
                    goal = {i, j};
          }
     }
     bfs(st.first, st.second);
     if (lev[goal.first][goal.second] == -1)
          cout << "NO\n";
     else
     {
          cout << "YES\n";
          cout << lev[goal.first][goal.second] << '\n';
          cout << path << '\n'; // actual path
     }
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
