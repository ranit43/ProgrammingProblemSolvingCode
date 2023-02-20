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
#define oo 1000000000
#define oo2 2000000000

using namespace std;

int cases=1;

typedef pair<int, int>ii;
typedef map<string, int> msti;
typedef map<int, string> mist;
typedef map<char, int> mci;
typedef map<int, char> mic;
typedef map<char, char> mcc;
typedef map<int, int> mii;
typedef map<string, string> mstst;
typedef map<vector<string>, int> mvsti;
typedef vector<int>vi;
typedef vector<string>vst;
typedef vector<char>vc;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef double db;
//typedef char C;
//typedef string S;
#define fr first
#define sc second
#define mp make_pair
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
TEMPLATE inline T lcm(T a, T b) { return a * (b / gcd(a, b)); }
TEMPLATE T power(T n, int p) { if(!p) return 1; else { T res = sqr(power(n, p>>1)); if(p&1) res*=n; return res; } }
TEMPLATE T bigmod(T n, int p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p>>1, m))%m; if(p&1) r = (r*n)%m; return r; } }
TEMPLATE T exgcd(T a,T b,T& x,T& y) { if(!b) { x=1; y=0; return a; } else { T g = exgcd(b, a%b, y, x); y -= (a/b)*x; return g; } }
TEMPLATE T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }

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

int m, n, VirS, RohS, tTime;
vi VirPoints, RohPoints;

void ViratSprint()
{
    int now=1, i, j, k;
    VirPoints.clear();
    for(i=1; i<=tTime; i++)
    {
        now += VirS;
        if(now>n)
        {
            now = (now-m+1)%(n-m+1);
            if(now==0) now=n;
            else now += (m-1);
        }
        //pf("vir now %d\n", now);
        VirPoints.pb(now);
    }
    return;
}

void RohSprint()
{
    int now=1, i, j, k;
    RohPoints.clear();
    for(i=1; i<=tTime; i++)
    {
        now += RohS;
        if(now>n)
        {
            now = (now-m+1)%(n-m+1);
            if(now==0) now=n;
            else now += (m-1);
        }
        RohPoints.pb(now);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int i, j, k, tests, q;
    sf("%d", &tests);
    while(tests--)
    {
        sf("%d %d %d %d %d", &n, &m, &tTime, &VirS, &RohS);
        ViratSprint();
        RohSprint();
        k=0;
        for(i=0; i<tTime; i++)
        {
//            pf("%d %d\n", VirPoints[i], RohPoints[i]);
            if(VirPoints[i]==RohPoints[i]) k++;
        }
        pf("%d\n", k);
    }
    return 0;
}


/*
Sample Input:
3
4 1 4 2 3
5 3 10 1 2
5 2 10 1 6
Sample Output:
1
3
2
*/
