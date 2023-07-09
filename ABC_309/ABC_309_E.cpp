//ABC_309_E
//DP on tree easy
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=3e5+10;
int f[N],ins[N];
void solve(){

  int n,m;
  cin>>n>>m;
  for(int i=2;i<=n;i++)cin>>f[i];
  while(m--){

    int x,y;
    cin>>x>>y;
    ins[x]=max(ins[x],y+1);
  }
  for(int i=2;i<=n;i++){

    ins[i]=max(ins[i],ins[f[i]]-1);
  }
  int cnt=0;
  for(int i=1;i<=n;i++){

    if(ins[i])cnt++;
  }
  cout<<cnt<<endl;

}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}