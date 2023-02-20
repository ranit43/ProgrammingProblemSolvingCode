/*============================================================================
* A Hope is a very good thing. And No Good thing ever Dies !!! *

 Author       : Ranit Debnath Akash
 Email        : ranitid12@gmail.com
 Varsity      : SUST - 2012 - 43
 Problem Name :
 Time Limit   : .000s
 Description  : help from Enam vai + Evan vai
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
LL arr1[22], arr2[22], dp[23][3][3][22][22], dpVis[23][3][3][22][22], tLen, st, en, tCase=1;

void digitMake(LL val)
{
    LL i , j=0;
    while(val)
    {
        i = val%10;
        arr1[j++]=i;
        val /= 10;
    }
    reverse(arr1, arr1+j);
    tLen=j;
}

void digitMake2(LL val)
{
    LL i , j=0;
    while(val)
    {
        i = val%10;
        arr2[j++]=i;
        val /= 10;
    }
    for(i=j; i<tLen; i++) arr2[i]=0;
    reverse(arr2, arr2+tLen);
}


LL DigitDp(int id, bool bounded, bool gt, int f, int s)
{
    if(id==tLen)
    {
        return f*s;
    }

    LL &r = dpVis[id][bounded][gt][f][s];
    LL &ret = dp[id][bounded][gt][f][s];

    if(r == tCase) return ret;
    r = tCase;
    ret=0LL;
    bool nbounded, ngt;
    LL lim = bounded ? arr1[id] : 9;
    LL bg = gt ? 0 : arr2[id];

    for(LL i=bg; i<=lim; i++)
    {
        nbounded = (bounded==1 &&  i==lim); //i==
        ngt = (gt|| i>arr2[id]) ? 1 : 0;
        if(i==4) ret = max(ret, DigitDp(id+1, nbounded, ngt,  f+1, s));
        else if(i==7) ret = max(ret, DigitDp(id+1, nbounded, ngt, f, s+1));
        else ret = max(ret, DigitDp(id+1, nbounded, ngt, f, s));
    }

    return ret;
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
//    ifstream input;
//    ofstream output;
//    input.open("crypt1_in.txt");
//    output.open("mersenePrime.txt");
    LL t, i, j, k, ans, tests, q;

    sf("%lld", &tests);
    while(tests--)
    {
        sf("%lld %lld", &st, &en);
        digitMake(en);
        digitMake2(st);
        LL ans1 = DigitDp(0, 1, 0, 0, 0);
       // cout << ans1 << endl;

        cout << ans1 << endl;
        tCase++;
    }

}


