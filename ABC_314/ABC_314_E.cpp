//ABC_314_E
//beibao like DP
//probability theory

#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;

void solve(){

  int n,m;
  cin>>n>>m;
  vector<double>dp(m+1,1e18), c(n+1);
  vector<int>wheel[n+1];
  vector<int>whl_num(n+1);
  for(int i=1;i<=n;i++){

    cin>>c[i]>>whl_num[i];
    for(int j=1;j<=whl_num[i];j++){

        int tmp;
        cin>>tmp;
        wheel[i].push_back(tmp);
    }
  }
  dp[0]=0;
  for(int i=1;i<=m;i++){

    for(int j=1;j<=n;j++){

        double tmp=0;
        int cnt=0;
        int zero=0;
        for(int k=0;k<whl_num[j];k++){

            if(wheel[j][k]){
                
               
                if(wheel[j][k]>=i)cnt++;
                else tmp+=dp[i-wheel[j][k]];
            }else  zero++;
            
        }
        dp[i]=min(dp[i],1.0*c[j]*whl_num[j]/cnt);
        tmp/=(whl_num[j]-zero);
        //if(cnt)dp[i]=max(dp[i],(double)((tmp+c[j])*1.0*whl_num[j]/cnt));
        dp[i]=min(dp[i],tmp+c[j]*whl_num[j]/(whl_num[j]-zero));
        
    }
  }
  
  if(dp[m]<1e18)printf("%.10lf\n",dp[m]);
  else cout<<-1<<endl;
  //for(int i=1;i<=m;i++)cout<<i<<':'<<dp[i]<<endl;
}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}