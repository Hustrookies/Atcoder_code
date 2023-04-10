//ABC 281 C
//前缀和+模运算+二分
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){

    ll n;
    cin>>n;
    ll T;
    cin>>T;
    vector<ll>S(n);
    for(int i=0;i<n;i++){

      cin>>S[i];
      if(i>0)S[i]+=S[i-1];
    }
    ll sum=S[n-1];
    T%=sum;
    int p=upper_bound(S.begin(),S.end(),T)-S.begin();
    if(p==0)cout<<p+1<<' '<<T<<endl;
    else cout<<p+1<<' '<<T-S[p-1]<<endl;
  
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1;
  //cin>>t;
  while(t--)solve();
}