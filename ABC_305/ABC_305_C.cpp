//ABC_305_C
//search
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
int n,m;
string G[510];
void solve(){

  cin>>n>>m;
  int Max=0;
  bool fst=0;
  for(int i=1;i<=n;i++)cin>>G[i];
  for(int i=1;i<=n;i++){
    int cnt=0;
    for(int j=0;j<m;j++)if(G[i][j]=='#')cnt++;
    if(cnt==0)continue;
    if(!fst){

      Max=max(Max,cnt);
      fst=1;
      continue;
    }
    if(cnt+1==Max){
      
      cout<<i<<' ';
      for(int j=0;j<m;j++){

        if(G[i-1][j]!=G[i][j]){

          cout<<j+1<<endl;
          return;
        }
      }
    }
    if(cnt-1==Max){

      cout<<i-1<<' ';
      for(int j=0;j<m;j++){

        if(G[i-1][j]!=G[i][j]){

          cout<<j+1<<endl;
          return;
        }
      }
    }
    Max=max(Max,cnt);
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