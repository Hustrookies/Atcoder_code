//ABC_306_E
//DP simple
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=3e5+10;
const ll INF=1e18;
ll dp[2][N];

void solve(){

    int n;
    cin>>n;
   vector<int>f(n+1);
   vector<int>y(n+1);
   for(int i=1;i<=n;i++)cin>>f[i]>>y[i];
   for(int i=1;i<=n;i++){
    if(!f[i]){

        dp[0][i]=max(max(dp[0][i-1],dp[1][i-1])+y[i],dp[0][i-1]);
        dp[1][i]=dp[1][i-1];
    }else{//pois

        dp[1][i]=max(dp[1][i-1],dp[0][i-1]+y[i]);
        dp[0][i]=dp[0][i-1];
    }
   }
   cout<<max(dp[0][n],dp[1][n])<<endl;

}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}