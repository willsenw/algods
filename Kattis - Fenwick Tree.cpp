#include <cstdio>
#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
#define LL long long

LL ft[5000005];
int n,q;
string s;
int t[5000005], x[5000005], v[5000005];

void upd( int x, int v ){
    while ( x <= n ){
        ft[x] += v;
        x += x & (-x);
    }
}

LL query( int x ){
    LL ans = 0;
    while ( x ){
        ans += ft[x];
        x -= x & (-x);
    }
    return ans;
}

int lb( int m ){
    return m;
}

int readint(){
    int num = 0;
    char c;
    int sign = 1;
    while ( true ){
        c = getchar();
        if ( c == '-' ) sign = -sign;
        else if ( c >= '0' && c <='9' ) num = ( num * 10 ) + c - '0';
        else break;
    }
    return num * sign;
}

char readchar(){
    char c;
    while ( true ){
        c = getchar();
        if ( c == '+' ) return c;
        if ( c == '?' ) return c;
    }
}

int main(){
    // init();

    // cin >> n >> q;
    n = readint();
    q = readint();
    for ( int i = 0; i < q; i++ ){
        char c = readchar();
        getchar();
        x[i] = readint();
        if ( c == '+' ){
            v[i] = readint();
            t[i] = 0;
        } else {
            t[i] = 1;
        }
    }

    for ( int i = 0; i < q; i++ ){
        if ( t[i] == 0 ){
            upd(lb(x[i]+1),v[i]);
        } else {
            if ( x[i] == 0 ) printf("0\n");
            else printf("%lld\n",query(lb(x[i])));
        }
    }
    return 0;
}