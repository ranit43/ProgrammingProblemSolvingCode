#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define ll long long
#define MX 100000
#define inf 1000000

using namespace std;

char str1[100];
char str2[100];
int len1, ty;

int dp[20][2][2][20][20];

int func(int pos, int hi, int lw, int fo, int se)
{
    if(pos == len1) return fo*se;
    int & res = dp[pos][hi][lw][fo][se];
    if(res != -1) return res;
    int mx = (hi)? str1[pos]:'9';
    res = 0;
    for(int i = (lw)? str2[pos]:'0'; i <= mx; i++)
    {
        int tem = func(pos+1,(hi == 1) && (str1[pos] == i), (lw == 1) && (str2[pos] == i), fo+(i == '4'),se + (i == '7'));
        res = max(res,tem);
    }
    //printf("%d %d %d %d\n", pos,hi,lw,res);
    return res;
}

int main()
{
    int te;
    ll a, b;
    scanf("%d", &te);
    while(te--)
    {
        scanf("%lld %lld", &a, &b);
        sprintf(str1,"%lld", b);
        len1 = strlen(str1);
        ll x = a;
        for(int i = len1-1; i >= 0; i--)
        {
            str2[i] = x%10;
            x /= 10;
            str2[i] += '0';
        }
        //puts(str1);
        //puts(str2);
        memset(dp,-1,sizeof dp);
        ty = '4';
        int fo = func(0,1,1,0,0);
        printf("%d\n", fo);
    }

    return 0;
}
