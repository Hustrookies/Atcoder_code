//ABC 297 D
//module 取模运算 模拟
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){

  ll a,b;
  cin>>a>>b;
  ll ans=0;
  while(a!=b){

    if(a%b==0){

    ans+=a/b-1;
    break;
  }
  if(b%a==0){

     ans+=b/a-1;
    break;
  }
    if(abs(a-b)==1){

      ans+=min(a,b);
      break;
    }
    else if(a>b){

      ans+=a/b;
      a=a%b;
    }else {
     
      ans+=b/a;
      b=b%a;
    }
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