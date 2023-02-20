/*============================================================================
* A Hope is a very good thing. And No Good thing ever Dies !!! *

 Author       : Ranit Debnath Akash
 Email        : ranitid12@gmail.com
 Varsity      : SUST - 2012 - 43
 Problem Name :  IITK2P05
 Time Limit   : .000s
 Description  :  Help--> Evan vai code
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
typedef unsigned long long ull;
typedef unsigned int ui;
typedef double db;
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
TEMPLATE T power(T n, int p) { if(!p) return 1; else { T res = sqr(power(n, p>>1)); if(p&1) res*=n; return res; } }
TEMPLATE T bigmod(T n, int p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p>>1, m))%m; if(p&1) r = (r*n)%m; return r; } }
TEMPLATE T exgcd(T a,T b,T& x,T& y) { if(!b) { x=1; y=0; return a; } else { T g = exgcd(b, a%b, y, x); y -= (a/b)*x; return g; } }
TEMPLATE T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }

int dx[4] = {+0,-1,+0,+1}, dy[4] = {-1,+0,+1,+0}; /*row and column moves*/
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
#define M 1010
int grid[M][M], vis1[M][M], vis2[M][M], dist1[M][M], dist2[M][M], frec[1000000+20], rT, cT, fr, fc, curMax, totMax;


void bfs1(int x, int y)
{
    queue<int> q;
    q.push(x);
    q.push(y);
    q.push(-1);
    q.push(-1);
    dist1[x][y]=1;
    vis1[x][y]=1;
    curMax=1;
    fr = x, fc=y;

    while(!q.empty())
    {
        x = q.front(); q.pop();
        y = q.front(); q.pop();
        int pr = q.front(); q.pop();
        int pc = q.front(); q.pop();

        if(dist1[x][y] > curMax)
        {
            curMax = dist1[x][y];
            fr = x, fc = y;
        }

        totMax =  max(totMax, dist1[x][y]);

        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if( nx<1 || nx>rT || ny<1 || ny>cT || (nx==pr && ny==pc) || (grid[nx][ny] != grid[x][y]) ) continue;

            if(vis1[nx][ny])
            {
                totMax = max(totMax, frec[grid[nx][ny]]);
                continue;
            }

            vis1[nx][ny] = 1;
            dist1[nx][ny] = dist1[x][y] + 1;
            q.push(nx);
            q.push(ny);
            q.push(x);
            q.push(y);
        }
    }
    return;
}



void bfs2(int x, int y)
{
    queue <int> q;
    q.push(x);
    q.push(y);
    q.push(-1);
    q.push(-1);
    dist2[x][y]=1;
    vis2[x][y]=1;

    while(!q.empty())
    {
        x = q.front(); q.pop();
        y = q.front(); q.pop();
        int pr = q.front(); q.pop();
        int pc = q.front(); q.pop();

        totMax = max(totMax, dist2[x][y]);

        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<1 || nx>rT || ny<1 || ny>cT || (nx==pr && ny==pc) || grid[nx][ny] != grid[x][y]) continue;

            if(vis2[nx][ny])
            {
                totMax = max(totMax, dist2[nx][ny]);
                continue;
            }
            vis2[nx][ny]=1;
            dist2[nx][ny] = dist2[x][y] + 1;
            q.push(nx);
            q.push(ny);
            q.push(x);
            q.push(y);
        }
    }
}


int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int i, j, k, tests, q;
    mem(vis1, 0);
    mem(vis2, 0);
    mem(dist1, 0);
    mem(dist2, 0);
    mem(frec, 0);
    totMax=0;
    sf("%d %d", &rT, &cT);

    for(i=1; i<=rT; i++)
    {
        for(j=1; j<=cT; j++)
        {
            sf("%d", &grid[i][j]);
            frec[grid[i][j]]++;
        }
    }


    for(i=1; i<=rT; i++)
        for(j=1; j<=cT; j++)
        {
            if(vis1[i][j]) continue;
            bfs1(i, j);
            bfs2(fr, fc);
        }

    pf("%d\n", totMax);

    return 0;
}

/*
5 6
1 6 3 6 6 6
5 4 3 6 1 6
7 6 2 6 6 6
4 2 2 1 4 6
6 6 6 2 6 1
-------------------------------- 15
6 6
1 2 1 3 4 5
5 4 1 4 1 6
5 1 5 1 2 5
4 1 1 3 1 1
2 3 1 5 2 5
5 1 1 1 2 2
------------------------------------6
2 3
1 2 1
1 1 1
-----------------------------------5
*/
