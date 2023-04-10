//ABC 297 E
//set 模拟
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){

  int n,k;
  cin>>n>>k;
  vector<ll>a(n);
  for(auto &v:a) cin>>v;
  sort(a.begin(),a.end());
  int cnt=0;
  set<ll>s;
  s.insert(0);
  ll ans=0;
  while(1){

    if(cnt==k+1) break;
    ll top=*s.begin();
    s.erase(s.begin());
    ans=top;
    cnt++;
    for(int i=0;i<n;i++)s.insert(top+a[i]);
  }
  cout<<ans<<endl;




}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1;
  //cin>>t;
  while(t--)solve();
  
}