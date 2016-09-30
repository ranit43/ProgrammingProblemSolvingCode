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
#define ool (1<<28)

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

#define mx 10000 + 100
vector <int> g[mx];
vector <LL> cost[mx];
int arr[mx], tn;


struct node
{
	int u;
	LL w;
	node(int a,LL b){u=a; w=b;}
	bool operator < ( const node& p ) const {      return w > p.w;   }
};

LL da[mx], db[ mx ] ;
int par[mx];
map < LL , int > tval;

int dijkstra(int sc, LL (&d) [mx] )
{

//    memset(d,63,sizeof(d));
//	memset(par,-1,sizeof(par));
    REPE(i, 1, tn) d [ i ] = ( 1<< 28 ) ;
	priority_queue<node>q;
	q.push(node(sc,0));
	d[sc]=0;

	while(!q.empty())
	{
		node top=q.top(); q.pop();
		int u=top.u;
		if( d[u] < top.w ) continue;
//        PF("%d --> ", u);
//		if(u==n) continue;
		for(int i=0;i<(int)g[u].size();i++)
		{
//		    PF(" %d", g[u][i] );
			int v=g[u][i];
			LL nw = cost[u][i] + top.w;

			if( nw >= d[ v ] ) continue;
            d[ v ] = nw;
            q.push( node(v,d[v]) );
//			if( d[u]+cost[u][i] <= d[v])
//			{
//				d[v]=d[u] + cost[u][i];
////				par[v]=u;
//				if( v == n ) {
//                        tval[ d[v] ] =  tval[ d[v] ] + 1;
//				}
//
//                if(v ==n) continue;
//				q.push(node(v,d[v]));
//			}
		}
//		NL
	}
//    cout << d[n] << " " <<tval[ d[n] ] << endl;

	return 0;
}


int main(){
	int n,e, tnodes, prv;

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout


	while( SF("%d %d %d", &tn , &e, &tnodes) ==3 )  {

    prv = -1;
    REPE(i, 1, tnodes) {
        SF( "%d", &arr[i] );
        par[ arr[i] ] = prv;
        prv = arr[i];
    }

    for(int i=0;i<e;i++)
	{
		int u,v;
		LL w;
		SF("%d %d %I64d", &u, &v, &w);
		g[u].push_back(v);
		g[v].push_back(u);
		cost[u].push_back(w);
		cost[v].push_back(w);
	}

//    int ret = dijkstra( 1, tn );
    int ret = dijkstra( 1, da );
    int re1 = dijkstra( tn, db );
//    PF("da %lld\n", da[tn]);


    bool ok = false;

    REPE(i, 2, tn)  {
        int u = i;
        bool ntfndpar = true;

        REP(i, 0, g[u].size() ) {
            int v = g[u ] [ i ];
            int w = cost[ u ][ i ];

            // tg->u + u->v + v-> src  != src->tg
            if( db [ u ] + cost[u][i] + da[v]  != da[ tn ]  ) continue;
            if( par[u]==v && ntfndpar ) {
                ntfndpar = false;
                continue;
            }
//            PF("%d %d %d %lld %lld %lld\n", u, par[u], v, db[ u], cost[u][i], da[v]);
            ok = true;
            break;
        }

        if( ok ) break;
    }


    if( ok ) PF("yes\n");
    else PF("no\n");

    REPE( i, 0, tn ) {
        g[i].clear() ;
        cost[ i ].clear();
    }
    tval.clear();

	}

}

/*
3 3 3
1 2 3
1 2 1
2 3 2
1 3 3

4 5 2
1 4
1 2 2
2 4 1
1 3 1
3 4 2
1 4 2
5 5 4
1 2 3 4
1 2 1
2 3 1
2 4 1
3 5 1
4 5 1
6 6 5
1 2 3 4 6
1 2 1
2 3 1
2 5 1
3 4 1
5 4 1
4 6 1
*/
