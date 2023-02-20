/**============================================================================
* Remember, Hope is a good thing... May be the best of things... And No Good thing ever Dies !!! *

 Author       : Ranit Debnath Akash
 Email        : ranitid12@gmail.com
 Varsity      : SUST - 2012 - 43
 Problem Name :
 Time Limit   : .000s
 Description  :
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
#define M 200000+50
LL arr[M], tn, tc;
LL ht, fpieces, wd, mn;



int main()
{
    int tests, q;
    int a, b, res;

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    SF(" %[^\n]", st1)
    SF("%d", &tests);
    REPE(t, 1, tests)
    {
        SF("%lld %lld %lld", &fpieces, &ht, &wd);
        arr[0] = 0, arr[fpieces+1] = wd;
        REPE(i, 1, fpieces) {
            SF("%lld", &arr[i]);
        }

        sort(arr, arr+fpieces+2);
        mn = oo;
//        REP(i, 0, fpieces+2) PF(" %lld", arr[i]); NL

        REP(i, 1, fpieces+2) {
            mn = min( mn, arr[i]-arr[i-1] );
        }
        PF("%lld\n", mn*ht);
    }


    return 0;
}


/* Copyright (C) 2015, RanitDebnathAkash */


