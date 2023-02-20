/*============================================================================
* A Hope is a very good thing. And No Good thing ever Dies !!! *

 Author       : Ranit Debnath Akash
 Email        : ranitid12@gmail.com
 Varsity      : SUST - 2012 - 43
 Problem Name : AMR14B Road Decoration
 Time Limit   : .000s
 Description  : Dijkstra + MST (Pain khaisi re vai)
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

#define M 20050

struct node              //for dijkstra
{
    int u;
    ll w;
    bool operator < (const node& p) const { return w>p.w; }
};

struct edges
{
    int u, v;
    ll w;
    bool operator < (const edges& p) const { return w<p.w; }
};
//typedef vector<type> vt;
//typedef vector<ii> vii;
vector <node> grid[M];
vector <edges> e;
ll cost[M];
int dist[M], par[M];
int tNodes, tPaths;

void dijkstra()
{
    int uu, vv, i, j, sz;
    ll ww, ct;
    node uNode, vNode;
    priority_queue <node> prtq;
    for(i=0; i<tNodes; i++) cost[i]=1LL<<60, dist[i]=oo;
    cost[0]=0LL, dist[0]=0, uNode.u=0, uNode.w=0LL;
    prtq.push(uNode);

    while(!prtq.empty())
    {
        uNode = prtq.top();
        prtq.pop();
        sz = grid[uNode.u].size();
        for(i=0; i<sz; i++)
        {
            vNode = grid[uNode.u][i];
            if(cost[uNode.u]+vNode.w < cost[vNode.u])
            {
                cost[vNode.u] = cost[uNode.u]+vNode.w;
                dist[vNode.u] = min(dist[vNode.u], (int)vNode.w);
                vNode.w=cost[vNode.u];
                prtq.push(vNode);
            }
            else if(uNode.w+vNode.w == cost[vNode.u]) dist[vNode.u] = min(dist[vNode.u], (int)vNode.w);
        }
    }

    return;
}

int findPar(int r)
{
    if(par[r]==r) return r;
    return par[r]=findPar(par[r]);
}

ll mst()
{
    sort(e.begin(), e.end());
    int uu, vv, sz=e.size(), i, j;
    ll ww=0, cnt=0;
    for(i=0; i<(int)tNodes; i++) par[i]=i;

    for(i=0; i<sz; i++)
    {
        uu = findPar(e[i].u);
        vv = findPar(e[i].v);
        if(uu!=vv)
        {
            par[uu]=vv;
            cnt++;
            ww += e[i].w;
            if(cnt==tNodes-1) break;
        }
    }
    if(cnt==tNodes-1) return ww;
    else return -1LL;
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int i, j, tests, q;
    ll valMst, k;
    node tAnode, tBnode;
    edges sAedge, sBedge;
    sf("%d", &tests);
    while(tests--)
    {
        sf("%d %d", &tNodes, &tPaths);
        for(i=0; i<tPaths; i++)
        {
            sf("%d %d %lld", &sAedge.u, &sAedge.v, &sAedge.w);
            tAnode.u=sAedge.v, tAnode.w=sAedge.w;
            grid[sAedge.u].pb(tAnode);
            tAnode.u=sAedge.u;
            grid[sAedge.v].pb(tAnode);
            e.pb(sAedge);
        }

        valMst = mst();
        if(valMst==-1)
        {
            pf("NO\n");
            for(i=0; i<=tNodes; i++) grid[i].clear();
            e.clear();
            continue;
        }
        dijkstra();
        k=0;
        for(i=0; i<tNodes; i++) k += dist[i];
//        pf("k = %lld   valMst = %lld\n", k, valMst);

        if(k==valMst) pf("YES\n");
        else pf("NO\n");
        for(i=0; i<=tNodes; i++) grid[i].clear();
        e.clear();
    }
    return 0;
}

/*
Sample Input:
4
3 3
0 1 1
0 2 2
1 2 2
3 1
0 1 1
4 5
2 1 9
3 2 5
0 3 9
0 1 2
3 1 9
4 4
1 2 2
0 3 2
0 1 2
0 2 2
Sample Output:
YES
NO
NO

*/
