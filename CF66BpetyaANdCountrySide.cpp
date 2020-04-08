/**============================================================================
* Remember, Hope is a good thing... May be the best of things... And No Good thing ever Dies !!! *

 Author       : Ranit Debnath Akash
 Email        : ranitid12@gmail.com
 Varsity      : SUST - 2012 - 43
 Problem Name :
 Time Limit   : .000s
 Description  :
============================================================================*/


//#include<algorithm>
#include<cstdio>
//#include<sstream>
//#include<cstdlib>
//#include<cctype>
//#include<cmath>
//#include<set>
//#include<queue>
//#include<stack>
//#include<list>
#include<iostream>
//#include<fstream>
//#include<numeric>
//#include<string>
//#include<vector>
#include<cstring>
//#include<cassert>
//#include<map>
//#include<iterator>
//#include<deque>
//#include<climits>

using namespace std;

//typedef vector<type> vt;
//typedef vector<ii> vii;

FILE *fp, *fp2;
#define M 1000+50
#define M2 500+50
int arr[M], asc[M], desc[M], tot[M], tn, tc, ttop;
char sklist[ M2 ][ M2 ] ;


int main()
{
    int tests, q;
    int a, b, res, mx, cnt;

//    freopen("Cf344Ain.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    scanf(" %[^\n]", st1)
//    scanf("%d", &tests);
//    for(int t=0; t<tests; t++)
//    {
//        takeinput();
//    }
    while( scanf("%d", &a) == 1) {
        for(int i=0; i<a; i++) {
            scanf("%d", &arr[i]);
        }

        asc[0] = 1;
        for(int i =1; i<a; i++) {
            if(arr[i] >= arr[i-1]) {
                asc[i] = asc[i-1] + 1;
            }
            else asc[i] = 1;
//            printf("as %d %d\n", i, asc[i]);
        }
//        puts("");

        desc[a-1] = 1;
        for(int i=a-2; i>=0; i--) {

            if(arr[i] >= arr[i+1]) {
                desc[i] = desc[i+1] + 1;
            }
            else desc[i] = 1;

//            printf("des %d %d\n", i, desc[i]);
        }
//        puts("");
        mx = 0;
        for(int i=0; i<a; i++) {
            res = asc[i] + desc[i] - 1;
            mx = res > mx ? res : mx;
//            printf("res %d %d\n", i, res);
        }
//        puts("");

        printf("%d\n", mx);
    }
    return 0;
}

/*
1
2
5
1 2 1 2 1
8
1 2 1 1 1 3 3 4

*/


/* Copyright (C) 2020, RanitDebnathAkash */
