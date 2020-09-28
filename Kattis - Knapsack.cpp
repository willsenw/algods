#include <bits/stdc++.h>
using namespace std;

int C,n;
int V[2005], W[2005];
int dp[2005][2005];
vector < int > ord;

int rek( int pos, int cap ){
    if ( pos == n ){
        return 0;
    }
    int &ans = dp[pos][cap];
    if ( ans != -1 ) return ans;
    ans = rek(pos+1,cap);
    if ( cap + W[pos] <= C ){
        ans = max( ans, rek(pos+1,cap+W[pos]) + V[pos] ); 
    }
    return ans;
}

void dfs( int pos, int cap ){
    if ( pos == n ) return;
    if ( cap + W[pos] <= C ) {
        if ( rek(pos+1,cap) > rek(pos+1,cap+W[pos]) + V[pos] ){
            dfs(pos+1,cap);
        } else {
            ord.push_back(pos);
            dfs(pos+1,cap+W[pos]);
        }
    } else {
        dfs(pos+1,cap);
    }
}

int main(){
    
    while ( scanf("%d%d",&C,&n) == 2 ){
        for ( int i = 0; i < n; i++ ) scanf("%d%d",&V[i],&W[i]);
        memset(dp,-1,sizeof(dp));
        ord.clear();
        dfs(0,0);
        printf("%d\n",ord.size());
        for ( int i = 0; i < ord.size(); i++ ){
            if ( i ) printf(" ");
            printf("%d",ord[i]);
        }
        printf("\n");
    }
    return 0;
}