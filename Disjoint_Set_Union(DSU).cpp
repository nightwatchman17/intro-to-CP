// problem link : https://codeforces.com/contest/25/problem/D

// Theory:
// - to combine any two Sets
// - in which set an element exists
// - make_set()             --- initialize
// - _Find(int a)           --- determines representative of a
// - _Union(int a,int b)    --- merge the set that contains b, with the set that contains a. representattor of a will be the final representator
// - Some optimaization nedde [*path Compression *union by Size]

//------------------------------------------------------------
int arr[inf], par[inf];
void make_set()
{
     for (int i = 1; i <= node; i++)
          par[i] = i;
}

int _Find(int a)
{
     if (a == par[a])
          return a;
     return par[a] = _Find(par[a]); // path compression
}

void _Union(int a, int b)
{
     int x = _Find(a), y = _Find(b);
     if (x != y) // different set
          par[y] = x;
}

//////////////////////////////////////