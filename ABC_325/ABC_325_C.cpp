//ABC_325_C
//DFS
#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
   
   int n,m;
   cin>>n>>m;
   string G[n];
   for(int i=0;i<n;i++)cin>>G[i];
   vector<bool>vis[n];
   for(int i=0;i<n;i++)vis[i].resize(m,0);
   int cnt=0;
   vector<int>dx={1,1,1,-1,-1,-1,0,0};
   vector<int>dy={1,0,-1,1,0,-1,1,-1};
  function<void(int,int)> dfs=[&](int x,int y){

    vis[x][y]=1;
    for(int i=0;i<8;i++)
      if(x+dx[i]>=0&&x+dx[i]<n&&y+dy[i]>=0&&y+dy[i]<m&&!vis[x+dx[i]][y+dy[i]]&&G[x+dx[i]][y+dy[i]]=='#')dfs(x+dx[i],y+dy[i]);
  };
  for(int i=0;i<n;i++){

    for(int j=0;j<m;j++){

      if(G[i][j]=='#'&&!vis[i][j]){

        cnt++;
        dfs(i,j);
      }
    }
  }
  cout<<cnt<<endl;
}
signed main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
/*
3
3 2 3 10
7 8 9
5 3 5 11
2 3 4 5 6
5 7 2 19
2 3 4 5 6

*/