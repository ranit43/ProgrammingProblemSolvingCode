/*============================================================================
* A Hope is a very good thing. And No Good thing ever Dies !!! *

 Author       : Ranit Debnath Akash
 Email        : ranitid12@gmail.com
 Varsity      : SUST - 2012 - 43
 Problem Name : IITK2P05 - Factorial
 Time Limit   : .000s
 Description  : Number Theory Sieve + Observation
                Thanks : Enam vai + kazi nayeem
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
    type() {}
    };

//typedef vector<type> vt;
//typedef vector<ii> vii;
#define MAX 1000010
#define LMT 1001
#define LEN 78502
#define chkC(x, n) ( x[n>>6] & (1<<((n>>1)&31)))
#define setC(x, n) ( x[n>>6] |= (1<<((n>>1)&31)))

LL base[MAX/64], primes[LEN], tPrimes;
vector <LL> pList;


void BitmaskSieve()
    {
    LL i, j, k;
    for(i=3; i<LMT; i+=2)
        if(!chkC(base, i))
            for(j=i*i, k=i<<1; j<MAX; j+=k)
                setC(base, j);

    primes[0]=2LL;
    for(i=3, j=1; i<MAX; i+=2)
        if(!chkC(base, i))
            primes[j++]=i;

    tPrimes=j;
    }


int main()
    {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    LL i, j, k, tests, q, num, phiN, f, sz;
    BitmaskSieve();
    sf("%lld", &tests);

    while(tests--)
        {
        sf("%lld %lld", &num, &phiN);
        for(i=0; i<tPrimes && sqr(primes[i])<=num; i++) //finding the numbers prime factors less than 10^6
            {
//            cout << primes[i] << endl;
//            getchar();

            if(num%primes[i]==0)
                {
                f=1;
                while(num%primes[i]==0)
                    {
                    f *= primes[i];
                    num /= primes[i];
                    pList.pb(primes[i]);
                    }
                phiN /= ((f/primes[i])*(primes[i]-1));
                }
            }

        if(num>1)
            {
            if(num-1==phiN) pList.pb(num);   //n is a prime
            else if((num-phiN)*(num-phiN)==num)   //n is a square of a prime
                {
                pList.pb((num-phiN));
                pList.pb(num-phiN);
                }
            else  //phiN = (p1-1)*(p2-1) means num = p1*p2
                {
                LL rr = (num-phiN+1);
                long double val = (num-phiN+1); //a+b = n-phi(n)-1
                //val = (val*val) - 4*num;
                rr = val - sqrtl((val*val) - 4*num);   //2*b
                rr >>= 1;
                pList.pb(rr);
                pList.pb(num/rr);

                }
            }

        sz = pList.size();
        pf("%lld", pList[0]);
        for(i=1; i<sz; i++) pf(" %lld", pList[i]);
        puts("");
        pList.clear();
        }
    return 0;
    }


//enam vai blog spot
/**
* H:\Dropbox\Code\CodeChef\Practice\IITK2P05 Factorization.cpp
* Created on: 2015-03-06-01.40.58, Friday
* Verdict: Solved
* Author: Enamul Hassan
* Problem Link: http://www.codechef.com/problems/IITK2P05

* Concept: This is a very interesting number theory problem. Let’s think the problem if
           n ranges to 10^12. What would we do? we would generate all the primes up to
           10^6 and would apply them on n. at last if n>1 then that value would be added
           in answer. Before going to the original constraint, we have to know some basic
           number theory formulas. They are

 ---phi( n * m) = phi(n) * phi(m)
---phi( n ) =  n * ( 1 - (1/p1) )* ( 1 - (1/p2) ) * ... * ( 1 (1/pk))
-phi( n ) =  ( p1^(e1-1) )*(p2^(e2-1))* ... * ( pk^(ek-1) ) *(p1 - 1)
                                                        *(p2-1)* ... *(pk-1)

  where pi is i-th prime factor of n and ei is the corresponding power of that prime factor. Another thing is to know that, phi(x) = x - 1 satisfies only when x is prime.
  Now, let’s face the main problem. At first, we have to find all prime factors of n less than 10^6. The corresponding phi calculation should be deducted from m.
   How the corresponding phi would be deducted from m? 3rd formula would help. For a prime factor pi, we know its corresponding power in n which is ei. So, the new m would be

			m /(( pi^(ei-1))*(pi - 1 )).

Now, only primes greater than 10^6 are remaining in n. This part of the calculation would be needed if n remains greater than one after the above calculation. It is guaranteed that there could exists at most two primes. Because, if any number below or equal to 10^18 have more than two prime factor, one of them must remain in range10^6. Because, 10^6 *10^6 * 10^6  = 10^18.

There are 3 possibilities which would be described below:

 1. n could be a prime if n = m + 1. So, n itself a prime, no calculation needed.

 2. n could be square number of a prime. In this case phi would be (p-1) * (p-1).
  Because, prime number p has phi, m = p - 1 and phi(p * p) = (p-1) * (p -1).

3. n could be the resultant of two different primes multiplication. suppose, these
          two primes are a and b. So,
                                a * b = n ............................(1) and
                                m = (a - 1) * (b - 1)
                                m = a*b - a - b + 1
                                m = n - (a + b) + 1
                                a + b = n - m + 1 ....................(2)
         We know, (a - b)^2 = (a + b)^2 - 4 * a * b
                  a - b = square_root( (n - m + 1)^2 - 4 * n ) .......(3)
         (2) - (3) =>
                    b = ( (n - m + 1) - square_root( (n - m + 1)^2 - 4 * n ) )/2
         From (1),
                    a = n/b

* Special thanks to: Sudipta Chandra Dipu and Kazi Nayeem
**/


//kazi nayeem
/**
    This problem is simple.
    You will be given an integer N and you need to factorize that number.
    To help you with factorization of N , you will also be given phi(N) .
*/


/**
    if the number is greater than 10^6 and it has no prime factor below 10^6
       than it will be a prime number or can be write as a*b = n where a && b is prime number greater than 10^6
    but
    one number can have one or more prime factor less than 10^6.

    those prime factors can be calculate normal way.... then here is a problem with phi(n) value
    we know,
            if n = p1^e1 * p2^e2 * p3^e3 *.......
            then phi(n) = p1^(e1-1) * (p1-1) * p2^(e2-1) * (p2-1) * p3^(e3-1) * (p3-1) ...........
    when a prime number(p) found that it divide n and the prime number less than 10^6
    than calculate if power(e).... divide n by p^e.... and phi(n)/(p^(e-1)*(p-1))
    because phi(n) has (p^(e-1)*(p-1)) for this prime..... calculate this for all prime less than 10^6
    after this phi(n) has value for one or two prime factor... and n has two prime factor
    if n has one prime factor, it can be p or p^2
        if n == p+1 then n is a prime number
        else n == p^2
            {
                here phi(n) = p(p-1)
                    => phi(n) = p^2-p
                    => phi(n) = n-p
                    => p = n - phi(n)
                if (n-phi(n))^2 == n then n-phi(n) is the two prime factor of n
            }
     if n has two distinct prime factor we can write as a*b = n
        phi(n) = (a-1)(b-1)
        => phi(n) = ab - a - b + 1
        => phi(n) = n-a-b+1
        => a+b = n-phi(n)+1 let x = n-phi(n)+1
        => a+b = x
        => n/b + b = x
        => b^2 + n = xb
        => b^2 - xb + n = 0
        here b has two root and this two root is the two prime factor of n
*/
