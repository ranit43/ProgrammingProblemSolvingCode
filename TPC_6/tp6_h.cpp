/*============================================================================
* Remember, Hope is a good thing... May be the best of things... And No Good thing ever Dies !!! *

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
#define REP(I,A,B) for(int I = (A); I < (B); ++I)
#define RREP(I,A,B) for(int I = (A); I > (B); --I)
#define REPE(I,A,B) for(int I = (A); I <= (B); ++I)
#define RREPE(I,A,B) for(int I = (A); I >=(B); --I)
#define SZ(x) (int)x.size()
#define PP() pop_back()
#define PB(x) push_back(x)
#define SF scanf
#define PF printf
#define SSF sscanf
#define RSRT(x) sort(x.rbegin(), x.rend())
#define SRT(x) sort(x.begin(), x.end())
#define mem(name, value) memset(name, value, sizeof(name))
#define oo 1000000050
#define oo2 2000000050

using namespace std;

int cases=1;

typedef pair<int, int> PII;
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
#define CSPRINT printf("Case %d:", t);
#define NL puts("");
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
template<class T1> inline void deb(T1 e) { cout << e << endl; }
template<class T1, class T2> inline void deb(T1 e1, T2 e2) { cout << e1 << " " << e2 << endl; }
template<class T1, class T2, class T3> inline void deb(T1 e1, T2 e2, T3 e3) { cout << e1 << " " << e2 << " " << e3 << endl; }

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


struct data
{
    char pkgname[25], methodname[25];
    int invokedby;
//    data(){}
};

//typedef vector<type> vt;
//typedef vector<ii> vii;

FILE *fp, *fp2;
#define M 200000+50
#define MX 400+50

int arr[M], tn, tc, id=1 , nw ;

char st1[ 25 ];
string st2;
data darr[ 440 ];
MSTI gval;
bool isProgram[ MX ];
int vis[MX];
VI grid[MX];


int fuid( string stnw ) {
    if( gval.find( stnw ) == gval.end() ) {
        gval[ stnw ] = id++;
        isProgram[ gval[stnw] ] = ( stnw.find("::PROGRAM")==stnw.length()-9 ) && stnw.length() >=10 ;
    }
    return gval[ stnw ];
}

int main()
{
    int tests;
    int a, b, u, v;
    queue < int > q;
    nw=0;

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    SF("%d", &tests);
//    REPE(t, 1, tests)
    while( SF("%d", &tn) ==1 ) {

        id = 1;
        nw++;
        REP(i, 0, tn) {
            cin >> st2;
            v = fuid(st2) ;
            if( isProgram[v] ) q.push( v ), vis[v]=nw;
            SF("%d", &a );
            REP( j, 0, a) {
                cin >> st2 ;
                u = fuid( st2 );
                grid[u].PB( v );
            }
        }

        while( !q.empty() ) {

            u = q.front();
            q.pop();
            for(int i : grid[u] ) {
                v = i;

                if( vis[i]== nw ) continue;
                vis[ i ] = nw;
                q.push( i );
            }

        }

        b=0;
        REP(i, 0, id ) if( vis[i] )  b++;
//        PF("%d %d\n", tn, b);
        PF("%d\n", tn-b);

        gval.clear();
        q = queue <int >();
        REP(i, 0, id ) grid[u].clear();
        REP(i, 0, id ) vis[i] = 0;

    }


    return 0;
}


/* Copyright (C) 2016, RanitDebnathAkash */


/*
2
SuperGame::PROGRAM 0
HelpPackage::HelpFunction 2
HelpPackage::HelpFunction SuperGame::PROGRAM

2
Loop::CallA 1
Loop::CallB
Loop::CallB 1
Loop::CallA

2
SuperGame::PROGRAM 1
SuperServer42::PROGRAM
SuperServer42::PROGRAM 1
SuperServer42::PROGRAM

*/
