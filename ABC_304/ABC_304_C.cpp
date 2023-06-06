//ABC_304_C
//build graph then dfs
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=3e5+10;

int G[2010][2010];
int x[2010],y[2010];
bool vis[2010];
int n;
void dfs(int k){

    vis[k]=1;
    for(int i=1;i<=n;i++){

        if(G[k][i]&&!vis[i])dfs(i);
    }
}
void solve(){

 

  double dst;
  cin>>n>>dst;
  for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
  for(int i=1;i<=n;i++){

    for(int j=i+1;j<=n;j++){

        if(sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2))<=dst){
            G[i][j]=1;
            G[j][i]=1;
        }
    }
  }
  dfs(1);
  for(int i=1;i<=n;i++){

    if(vis[i])cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
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