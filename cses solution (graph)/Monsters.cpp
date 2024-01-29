// Problem Link: https://cses.fi/problemset/task/1194
// Hint: Multi-Source BFS. Shortest Path Calculation in 2-D Grid.
// Shortest Path retrival in 2-D Grid. Path printing by direction array.
// Saving previous move
//-------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1100;

int row, col;
pair<int, int> posA;            // position of A
vector<pair<int, int>> posMons; // monsters' postions

char arr[inf][inf];
int levA[inf][inf], levM[inf][inf];  // store level
char dirA[inf][inf], dirM[inf][inf]; // moves from parent cell

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char dxy_char[] = {'D', 'U', 'R', 'L'}; // direction array with characters
string path = "";                       // shortest path (result)

void bfs_Monsters()
{
     memset(levM, -1, sizeof levM);

     queue<pair<int, int>> q;
     for (auto u : posMons)
     { // multi-source pushing into queue
          q.push({u.first, u.second});
          levM[u.first][u.second] = 0; // all source having level 0
     }

     while (!q.empty())
     {
          pair<int, int> at = q.front();
          q.pop();
          for (int i = 0; i < 4; i++)
          {
               int nx = at.first + dx[i];
               int ny = at.second + dy[i];
               if (nx >= 1 and nx <= row and ny >= 1 and ny <= col and arr[nx][ny] != '#' and levM[nx][ny] == -1) // conditions of validity to move in next cell
               {
                    levM[nx][ny] = levM[at.first][at.second] + 1;
                    q.push({nx, ny});
                    dirM[nx][ny] = dxy_char[i]; // for path retrival (not necessary in this problem)
               }
          }
     }
}

bool isBoundary(int x, int y)
{ // goal node for this problem
     if (x == 1 or x == row)
          return true;
     if (y == 1 or y == col)
          return true;
     return false;
}

bool bfs_A()
{ // simple BFS
     memset(levA, -1, sizeof levA);

     queue<pair<int, int>> q;
     q.push({posA.first, posA.second});
     levA[posA.first][posA.second] = 0;

     while (!q.empty())
     {
          pair<int, int> at = q.front();
          q.pop();
          if (isBoundary(at.first, at.second))
          { // goal node reached
               int x = at.first, y = at.second;
               while (1)
               {
                    if (x == posA.first and y == posA.second)
                         break; // starting node reached
                    path += dirA[x][y];

                    // backward moves
                    if (dirA[x][y] == 'R')
                         y--;
                    else if (dirA[x][y] == 'L')
                         y++;
                    else if (dirA[x][y] == 'U')
                         x++;
                    else if (dirA[x][y] == 'D')
                         x--;
               }
               reverse(path.begin(), path.end()); // gaining actual path
               return true;
          }
          for (int i = 0; i < 4; i++)
          {
               int nx = at.first + dx[i];
               int ny = at.second + dy[i];
               if (nx >= 1 and nx <= row and ny >= 1 and ny <= col and arr[nx][ny] != '#' and levA[nx][ny] == -1 and (levA[at.first][at.second] + 1 < levM[nx][ny] or levM[nx][ny] == -1)) // either level of 'A' is smaller or monster doesn't visit to the cell at all
               {
                    q.push({nx, ny});
                    levA[nx][ny] = levA[at.first][at.second] + 1;
                    dirA[nx][ny] = dxy_char[i]; // for path retrival (interesting idea)
               }
          }
     }
     return false;
}

void Solve()
{
     cin >> row >> col;
     for (int i = 1; i <= row; i++)
     {
          for (int j = 1; j <= col; j++)
          {
               cin >> arr[i][j];
               if (arr[i][j] == 'A')
                    posA = {i, j};
               if (arr[i][j] == 'M') // monster
                    posMons.push_back({i, j});
          }
     }

     bfs_Monsters();

     if (bfs_A())
     { // bfs returned true
          cout << "YES\n";
          cout << path.size() << '\n';
          cout << path << '\n';
     }
     else
          cout << "NO\n";
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
