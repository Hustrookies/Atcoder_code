//ABC 282 D
//二分图问题
//两个不同component上的点是一定可连的
//删去每个连通分量内部颜色相同的对数即可
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
//记录一个连通分量内两个颜色的出现次数
ll black,white;
//黑色1，白色-1
int vis[200010];
vector<int>G[200010];
//只要有一个连通分量不可二分，答案就是0
bool flag;
void dfs(int u,int p_color){

  vis[u]=-p_color;
  if(vis[u]==1)black++;
  else white++;
  for(auto v:G[u]){

    if(vis[v]==-vis[u])continue;
    if(vis[v]==vis[u]) {
      //cout<<u<<':'<<v<<endl;
      flag=1;
      return;
    }
    dfs(v,vis[u]);
  }
}
void solve(){

   cin>>n>>m;
   ll ans=n*(n-1)/2-m;
   while(m--){

    int u,v;
    cin>>u>>v;
    //双向建图
    G[u].push_back(v);
    G[v].push_back(u);
   }
  
   for(int i=1;i<=n;i++){

    if(!vis[i]){

      flag=0;
      black=white=0;
      dfs(i,1);
      if(flag==1){

        cout<<0<<endl;
        return;
      }
      ans-=(black*(black-1)/2+white*(white-1)/2);
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