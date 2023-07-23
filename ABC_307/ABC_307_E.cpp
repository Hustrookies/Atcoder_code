//ABC_307_E
//DP
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=1e6+10;
const ll INF=1e18;
const int MOD=998244353;
ll dp[5];
void solve(){

   ll n,m;
   cin>>n>>m;
   //deal with special case:n=2
   if(n==2){

    cout<<((m-1)*m)%MOD<<endl;
    return;
   }
   dp[1]=1;
   //dp
   for(int i=0;i<n-3;i++){

    dp[2]=dp[0];
    dp[0]=((m-1)*dp[1])%MOD;
    dp[1]=(dp[2]+(m-2)*dp[1])%MOD;
   }
   //ll ans=  (dp[0]*(m-1))%MOD   + ((  (dp[1]*(m-2))%MOD  )  *(m-1))%MOD;
   ll ans=(dp[1]*(m-2))%MOD;
   ans=(ans*(m-1))%MOD;
   ans=(ans+(dp[0]*(m-1)))%MOD;
   ans=(m*ans)%MOD;
   cout<<ans<<endl;
}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}