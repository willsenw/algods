#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define LL long long

int n,a,b,c,m,tc;
int cnt[10000005];
int d[100000005];

int main(){
	
	scanf("%d",&tc);
	for ( int t = 1; t <= tc; t++ ){
		scanf("%d%d%d%d%d",&n,&a,&b,&c,&m);
		for ( int i = 0; i < m; i++ ) cnt[i] = 0;
		int x = 0;
		for ( int i = 1; i <= n; i++ ){
			x = ( x	* 1LL * a + b ) % m;
			cnt[x]++;
		}
		int pos = 0;
		for ( int i = m-1; i >= 0 && pos < n ; i-- ){
			while ( cnt[i] > 0 ){
				cnt[i]--;
				d[pos++] = i;
			}
		}
		
		int l = 0, r = n-1;
		LL L = 0, R = 0;
		
		bool havel = true;
		for ( int i = 0; i < n && havel; i++ ){
			L += d[i];
			while ( i <= r && d[r] <= i + 1 ){
				R += d[r];
				r--;
			}
			while ( i > r ){
				R -= d[r+1];
				r++;
			}
			
//			printf("%lld %lld\n",L,R);
			if ( L > (i) * 1LL * (i+1) + R + (r-i) * 1LL * (i+1)){
				havel = false;
			}
		}
		
		if ( havel ) printf("HAPPY\n");
		else printf("SAD\n");
	}
	return 0;
}