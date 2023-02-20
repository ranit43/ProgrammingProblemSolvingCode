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
#include <utility>
#include <cstdio>
//#include<sstream>
//#include<cstdlib>
//#include<cctype>
//#include<cmath>
//#include<set>
//#include<queue>
//#include<stack>
//#include<list>
#include <iostream>
//#include<fstream>
//#include<numeric>
//#include<string>
//#include<vector>
#include <cstring>
//#include<cassert>
//#include<map>
//#include<iterator>
//#include<deque>
//#include<climits>

using namespace std;

//typedef vector<type> vt;
//typedef vector<ii> vii;

FILE *fp, *fp2;
#define M 200000 + 50
#define M2 500 + 50
int arr[M], tn, tc, ttop;
char sklist[M2][M2];

int main()
{
    int tests;

        freopen("in.txt", "r", stdin);
    //    freopen("out.txt", "w", stdout);
    //    scanf(" %[^\n]", st1)
        scanf("%d", &tests);
        for(int t=0; t<tests; t++)
        {			
           // takeinput
           int n, a;
           string inpString;
           cin >> n;
           int cntOdd=0, cntEven=0;
			for(int i=0; i<n; i++) {
				cin >> a;
				 a % 2 ? cntOdd++ : cntEven++;
			}
			
			int cnt = min( n/2, cntOdd) +  min( n/2 + (n%2), cntEven);
			
			
			cout << cnt << endl;
           
       }

    return 0;
}

/* Copyright (C) 2020, Ranit Debnath Akash */

