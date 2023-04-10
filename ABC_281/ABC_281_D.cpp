//ABC 281 D
//DP
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[110][110][110];

void solve(){

  int N,K,D;
  cin>>N>>K>>D;

  vector<int>a(N+1);
  for(int i=1;i<=N;i++) cin>>a[i];
  //初始化
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<=N;i++)dp[i][0][0]=0;
  //前i个数
  for(int i=1;i<=N;i++){
    //选j个
    for(int j=1;j<=min(i,K);j++){
      //模D剩余的情况
      for(int k=0;k<D;k++){

        //传递上一轮的结果
        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]);
        //如果至少选了一个数，那么最大值一定不为-1
        if(j>=1&&dp[i-1][j-1][k]==-1)continue;
        int rst=(k+a[i])%D;
        dp[i][j][rst]=max(dp[i-1][j][rst],dp[i-1][j-1][k]+a[i]);
      }
    }    
  }
  if(dp[N][K][0]==-1) cout<<-1<<endl;
  else cout<<dp[N][K][0]<<endl;

  
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1;
  //cin>>t;
  while(t--)solve();
  
}