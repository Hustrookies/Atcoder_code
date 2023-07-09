//ABC_309_A
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N=1e6+10;
const ll INF=1e18;
void solve(){

  int a,b;
  cin>>a>>b;
  if(b-a==1&&a%3!=0)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}