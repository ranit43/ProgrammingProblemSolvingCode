/*============================================================================
* A Hope is a very good thing. And No Good thing ever Dies !!! *

 Author       : Ranit Debnath Akash
 Email        : ranitid12@gmail.com
 Varsity      : SUST - 2012 - 43
 Problem Name :
 Time Limit   : .000s
 Description  :
============================================================================*/
#include<algorithm>
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<cassert>
#include<map>
#include<iterator>
#include<deque>
#include<climits>
#define fi(a, b) for(int i=a; i<b; i++)
#define fj(a, b) for(int j=a; j<b; j++)
#define fk(a, b) for(int k=a; k<b; k++)
#define SZ(x) (int)x.size()
#define pp() pop_back()
#define pb(x) push_back(x)
#define mp make_pair
#define sf scanf
#define pf printf
#define ssf sscanf
#define rsrt(x) sort(x.rbegin(), x.rend())
#define srt(x) sort(x.begin(), x.end())
#define mem(name, value) memset(name, value, sizeof(name))
#define oo 1000000050
#define oo2 2000000050

using namespace std;

int cases=1;

typedef pair<int, int> II;
typedef map<string, int> MSTI;
typedef map<int, string> MIST;
typedef map<char, int> MCI;
typedef map<int, char> MIC;
typedef map<char, char> MCC;
typedef map<int, int> MII;
typedef map<string, string> MSTST;
typedef map<vector<string>, int> MVSTI;
typedef vector<int>VI;
typedef vector<string>VST;
typedef vector<char>VC;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UI;
typedef double DB;
//typedef char C;
//typedef string S;
#define FR first
#define SC second
#define MP make_pair
#define ins insert
#define IT iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB lower_bound
#define UB upper_bound
#define POPC __builtin_popcount
#define loop(i, x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x).rbegin(); i!=(x).rend(); ++i)
#define TEMPLATE template<typename T>
//variables and functions
const double EPS = 1E-10;
const double PI = 2.0 * acos(0.0);
const int CHAR_INF = 0x7F;
const int INT_INF = 0x7F7F7F7F;
const long long LONG_INF = 0X7F7F7F7F7F7F7F7F;
TEMPLATE inline T sqr(T n) { return n * n; }
TEMPLATE inline T pmod(T n, T m) { return ((n % m) + m) % m; }
TEMPLATE inline T gcd(T a, T b) { while(b) b ^= a ^= b ^= a %= b; return a; }
TEMPLATE inline T lcm(T a, T b) { return a * (b / gcd(a, b)); }
TEMPLATE T power(T n, T p) { if(!p) return 1; else { T res = sqr(power(n, p>>1)); if(p&1) res*=n; return res; } }
TEMPLATE T bigmod(T n, T p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p>>1, m))%m; if(p&1) r = (r*n)%m; return r; } }
TEMPLATE T exgcd(T a,T b,T& x,T& y) { if(!b) { x=1; y=0; return a; } else { T g = exgcd(b, a%b, y, x); y -= (a/b)*x; return g; } }
TEMPLATE T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
inline DB distFind(int x1, int y1, int x2, int y2) { DB x = (DB) x1 - (DB) x2; DB y = (DB) y1 - (DB) y2; return sqrt((x*x)+(y*y)); }

//int dx[4] = {+0,-1,+0,+1}, dy[4] = {-1,+0,+1,+0}; /*row and column moves*/
//int dx[8] = {-1,-1,-1,+0,+1,+1,+1,+0}, dy[8] = {-1,0,+1,+1,+1,0,-1,-1};/*8-direction*/
/*
knight moves:
dx[8] = {-1,-2,-2,-1,+1,+2,+2,+1};
dy[8] = {-2,-1,+1,+2,+2,+1,-1,-2};
*/

/* Grid rotation: */
/*
(col-j, i), (row-i, col-j), (j, col-i);
*/

struct type
{
    type(){}
};

//typedef vector<type> vt;
//typedef vector<ii> vii;
#define NIL .000001
int cx1, cx2, cx3, cy1, cy2, cy3;
DB r1, r2, r3;

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
//    ifstream input;
//    ofstream output;
//    input.open("crypt1_in.txt");
//    output.open("mersenePrime.txt");
    int t, i, j, k, ans, tests, q;
    DB d12, d23, d13, lw, hi, md, tp2, tp3;

    while(sf("%d %d %d %d %d %d",&cx1, &cy1, &cx2, &cy2, &cx3, &cy3)==6)
    {
        d12 = distFind(cx1, cy1, cx2, cy2);
        d13 = distFind(cx1, cy1, cx3, cy3);
        d23 = distFind(cx2, cy2, cx3, cy3);

        lw=0.0, hi = d12;

        for(i=0; i<100; i++)
        {
            md = (hi+lw)/2.00;
            tp2 =d12 - md;
            tp3 = d23 - tp2;

            if(md+tp3 <= d13) lw=md;
            else hi = md;
        }

        pf("%0.5lf\n%0.5lf\n%0.5lf\n", md, d12-md, d13-md);

    }


    return 0;
}

/*
0 0
4 0
4 3
*/
