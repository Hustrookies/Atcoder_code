//ABC_305_D
//binary search + prefix sum
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
int n,m;

void solve(){

  int n;
  cin>>n;
  vector<int>slp(n),fall,awake;
  fall.push_back(0),awake.push_back(0);
  for(int i=0;i<n;i++){
    cin>>slp[i];
    if(i&&i%2==1)fall.push_back(slp[i]);
    if(i&&i%2==0)awake.push_back(slp[i]);
  }
  vector<ll>sum;
  for(int i=0;i<fall.size();i++){

    sum.push_back(awake[i]-fall[i]);
    if(i>0)sum[i]+=sum[i-1];
  }
  // for(int i=0;i<fall.size();i++){

  //   cout<<fall[i]<<' '<<awake[i]<<' ';
  //   if(i>0) cout<<sum[i]-sum[i-1]<<endl;
  //   else cout<<sum[0]<<endl;
  // }
  int Q;
  cin>>Q;
  while(Q--){

    int l,r;
    cin>>l>>r;
    int pl=upper_bound(fall.begin(),fall.end(),l)-fall.begin();
    int pr=lower_bound(awake.begin(),awake.end(),r)-awake.begin();
    ll ans=0;
    if(awake[pl-1]>l)ans+=awake[pl-1]-l;
    //cout<<pl<<' '<<ans<<endl;
    if(r>fall[pr])ans+=r-fall[pr];
    //cout<<pr<<' '<<ans<<endl;
    ans+=sum[pr-1]-sum[pl-1];
    cout<<ans<<endl;

  }
  
}
  

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}