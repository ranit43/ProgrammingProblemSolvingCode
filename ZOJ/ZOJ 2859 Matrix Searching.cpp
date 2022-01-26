
/**============================================================================
* Remember, Hope is a good thing... May be the best of things... And No Good thing ever Dies !!! *

 Author       : Ranit Debnath Akash
 Email        : ranitid12@gmail.com
 Varsity      : SUST - 2012 - 43
 Problem Name :
 Time Limit   : .000s
 Description  : Sparse Table RMQ ON Rectrangle query!!!

(i>0 )

dp[row][col][i][j] = min( [row,row+ 2^(i-1)-1] x [col,col+2^j-1] , [row+2^(i-1),row+2^i-1] x [col,col+2^j-1] )
                   = min( dp[row][col][i-1][j] , dp[row + (1<<(i-1))][col][i-1][j] )

if(i==0)

dp[row][col][i][j]=

= min( [row,row+ 2^i-1] x [col,col+2^(j-1)-1] , [row,row+2^i-1] x [col+2^(i-1),col+2^j-1] )

= min( dp[row][col][i][j-1] , dp[row][col + (1<<(i-1))][i][j-1] )
============================================================================*/
#include <bits/stdc++.h>
using namespace std;

/**--------------------------Define--------------------------------*/
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
#define FSF fscanf
#define RSRT(x) sort(x.rbegin(), x.rend())
#define SRT(x) sort(x.begin(), x.end())
#define mem(name, value) memset(name, value, sizeof(name))
#define oo 1000000050
#define oo2 2000000050
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
template<class T1> inline void deb(T1 e) { cout << e << endl; }
template<class T1, class T2> inline void deb(T1 e1, T2 e2) { cout << e1 << " " << e2 << endl; }
template<class T1, class T2, class T3> inline void deb(T1 e1, T2 e2, T3 e3) { cout << e1 << " " << e2 << " " << e3 << endl; }
/**--------------------------Define--------------------------------*/

struct data
{
    data(){}
};
int cases=1;
//typedef vector<type> vt;
//typedef vector<ii> vii;

FILE *fp, *fp2;
#define M 300+5
int arr[M], tn, tc, mat[M][M], sptable[M][M][9][9];

void ini()
{
    arr[0] = -1;
    REPE(i, 1, 301)
    {
        arr[i] = ( ( i & (i-1))==0 ) ? arr[i-1]+1 : arr[i-1] ;
//        PF("%d %d\n", i, arr[i]);
    }
}

void takeinput()
{
    SF("%d", &tn);
    REPE(i, 1, tn) REPE(j, 1, tn) SF("%d", &mat[i][j]);
}

void preprocess()
{
    REPE(r, 1, tn) REPE(c, 1, tn) sptable[r][c][0][0] = mat[r][c];

    int r, c, i, j;

    for(i=0; (1<<i) <= tn; i++)
    {
        for(j=0; (1<<j) <= tn; j++)
        {
            if(i+j == 0) continue;

            for( r=1; r+(1<<i)-1 <= tn ; r++) //cause we are taking we have (r, r+(1<<i)-1 ) (r+(1<<i), (1<<i)
            {
                for( c=1; c+(1<<j)-1 <= tn; c++)
                {
                    if(i==0)  //when taking linear columns
                    {
                        sptable[r][c][i][j] = min( sptable[r][c][i][j-1], sptable[r][c + (1<< (j-1)) ][i][j-1] );
                    }
                    else //taking rows 2^(i-1), columns of 2^(j-1)
                    {
                        sptable[r][c][i][j] = min( sptable[r][c][i-1][j], sptable[r + (1<<(i-1)) ][c][i-1][j] );
                    }

                }
            }

        }
    }


}

int give(int x)
{
    return log(double  (x) )  / log(2.0) ;
}

void takequery()
{
    int q, x1, x2, y1, y2;

    SF("%d", &q);

    while(q--) {

    SF("%d %d %d %d", &x1, &y1, &x2, &y2);

    int kx = arr [ x2 - x1 + 1 ];
    int ky = arr [ y2 - y1 + 1 ];
//    int kx =  give(x2-x1+1) ;
//    int ky = give (y2-y1+1);
    int nx = x2 - (1<<kx) + 1;
    int ny = y2 - (1<<ky) + 1;

    int res = min( min(sptable[x1][y1][kx][ky], sptable[x1][ny][kx][ky] ),
                   min(sptable[nx][y1][kx][ky], sptable[nx][ny][kx][ky] )  );

    PF("%d\n", res);

    }

}

int main()
{
    int tests, q;
    int a, b;
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ini();

    SF("%d", &tests);
    REPE(t, 1, tests)
    {
        takeinput();
        preprocess();
        takequery();
    }

    return 0;
}


/* Copyright (C) 2015, RanitDebnathAkash */
