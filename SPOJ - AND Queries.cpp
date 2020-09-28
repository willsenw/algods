#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back

int smod = 2117566807;

int tc;
int seed, N,Q, mod_A, mod_V, mod_K;
int A[250005], V[250005], K[250005];
LL sa[530000], sv[530000];
vector < int > Ki[25];
int n = (1<<19);
vector < int > S;

LL rdm(){
	seed = ( seed * 1LL * 997 + 29) % 2117566807;
	return seed;
}

int Count( int mask ){
	int ans = 0;
	for ( int i = 0; i < 20; i++ ){
		if ( (mask>>i) & 1 ) ans++;
	}
	return ans;
}

void fwht( LL a[] ){
	for ( int h = 1; h < n; h *= 2){
		for ( int l = 0; l < n; l += h * 2 ){
			for ( int j = l; j < l + h; j++ ){
				LL x = a[j];
				LL y = a[j+h];
				a[j] = y;
				a[j+h] = x + y;
			}
		}
	}
}

void ifwht( LL a[] ){
	for ( int h = 1; h < n; h *= 2){
		for ( int l = 0; l < n; l += h * 2 ){
			for ( int j = l; j < l + h; j++ ){
				LL x = a[j];
				LL y = a[j+h];
				a[j] = -x + y;
				a[j+h] = x;
			}
		}
	}
}

int main(){
	
	scanf("%d",&tc);
	for ( int t = 1; t <= tc; t++ ){
		scanf("%d%d%d%d%d%d",&seed,&N,&Q,&mod_A,&mod_V,&mod_K);
		for ( int i = 0; i < N; i++ ) A[i] = rdm() % mod_A;
		for ( int i = 0; i < Q; i++ ){
			V[i] = rdm() % mod_V;
			K[i] = rdm() % mod_K;
		}
		memset(sa,0,sizeof(sa));
		for ( int i = 0; i < N; i++ ) sa[A[i]]++;
		for ( int i = 0; i < mod_K; i++ ) Ki[i].clear();
		for ( int i = 0; i < Q; i++ ){
			Ki[K[i]].push_back(V[i]);
		}
		
		fwht(sa);
		LL ans = 0;
		
		for ( int k = 0; k < mod_K; k++ ){
			memset(sv,0,sizeof(sv));
			for ( auto v : Ki[k] ){
				sv[v]++;
			}

			fwht(sv);
			for ( int i = (1<<19)-1; i >= 0; i-- ){
				sv[i] = sv[i] * 1LL * sa[i];
			}

			ifwht(sv);
			
			S.clear();
			for ( int i = (1<<19)-1; i >= 0; i-- ){
				if ( sv[i] > 0 ){
					S.push_back(i);
					if ( Count(i) == k ) ans += sv[i];
				}
			}
			for ( auto it : S ){
				sv[it] = 0;
			}
		}
		
		printf("Case %d: %lld\n",t,ans);
	}
	return 0;
}