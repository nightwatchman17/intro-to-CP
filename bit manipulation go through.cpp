#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define LSB_set(x) __builtin_ffs(x)
#define leading_zero(x) __builtin_clz(x) // for integer [*add ll for long long*]
#define trailing_zero(x) __builtin_ctz(x)
#define count_set_bits(x) __builtin_popcount(x) // count set bits

inline bool check_Bit(ll n, int i) { return (n & (1LL << i)); }
inline ll set_Bit(ll n, int i) { return (n | (1LL << i)); }
inline ll reset_Bit(ll n, int i) { return (n & (~(1LL << i))); }
inline ll flip_Bit(ll n, int i) { return (n ^ (1LL << i)); }

bool isPowerOfTwo(ll n) { return n && !(n & (n - 1)); }

// if((n&1)==0) then n is even [*last bit 0*]
// if((n&1)==1) then n is odd [*last bit 1*]

// (n>>k) is equal (n/(2^k))
// (n<<k) is equal (n*(2^k))
// (n MOD 2^k) equals to (n&((1<<k)-1)) (*keeps last k bits as usual*)

int countSetBits(int n)
{ // Brian Kernighan's algorithm
     int count = 0;
     while (n)
     {
          n = n & (n - 1);
          count++;
     }
     return count;
}

// cp algo : https://cp-algorithms.com/algebra/bit-manipulation.html

int computeXOR(int n)
{ // xor from 1 to n
     if (n % 4 == 0)
          return n;
     if (n % 4 == 1)
          return 1;
     if (n % 4 == 2)
          return n + 1;
     else
          return 0;
}

//  Equal Sum and XOR
// Problem: Given a positive integer n, find count of positive integers i such that 0 <=
// i <= n and (n+i = n⊕i) (⊕ is the XOR operation)
// Instead of Brute force method, we can directly find it by a mathematical trick
// Let x be the number of unset bits in the number n.
// Answer = 2^x

// leetcode : https://leetcode.com/problems/hamming-distance/description/
// hamming distance(a,b) : Number of set bits in (a^b)

int clear_last_i_bit(int n, int i)
{ // Clear last i Bit
     int mask = (-1 << i);
     n = (n & mask);
     return n;
}

int clear_bits_in_range(int n, int i, int j)
{ // Clear Bits In Range
     int a = (-1 << j + 1);
     int b = (i << i - 1);
     int mask = (a | b);
     n = (n & mask);
     return n;
}

void all_Subsets(vector<int> v, int N)
{ // bit masking
     for (int mask = 0; mask < (1 << N); ++mask)
     {
          for (int i = 0; i < N; ++i)
               if (mask & (1 << i))
                    cout << v[i] << ' ';
          cout << endl;
     }
}

long largest_power(long N)
{ // largets power of 2 less or equal N
     // changing all right side bits to 1.
     N = N | (N >> 1);
     N = N | (N >> 2);
     N = N | (N >> 4);
     N = N | (N >> 8);
     // here for 16 bit number

     // as now the number is 2 * x-1, where x is required answer, so adding 1 and dividing it by2.
     return (N + 1) >> 1;
}

// a|b = a⊕b + a&b

// a⊕(a&b) = (a|b)⊕b

// (a&b)⊕(a|b) = a⊕b

// a+b = a|b + a&b

// a+b = a⊕b + 2(a&b)

// all pair xor
// problem link: https://www.hackerrank.com/contests/algobangla29/challenges/dazzling-array

void all_pair_xor()
{
     cin >> n;
     vector<ll> v(n);
     for (int i = 0; i < n; i++)
          cin >> v[i];
     ll sum = 0;
     for (ll i = 0; i < 25; i++)
     {
          ll zc = 0, oc = 0;
          ll idsum = 0;
          for (int j = 0; j < n; j++)
          {
               if (v[j] % 2 == 0)
                    zc++;
               else
                    oc++;
               v[j] /= 2;
          }

          idsum = 1LL * oc * zc * (1LL << i);
          sum += idsum;
     }
     cout << sum << '\n';
}

void Solve()
{
     cout << largest_power(8) << '\n';
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
