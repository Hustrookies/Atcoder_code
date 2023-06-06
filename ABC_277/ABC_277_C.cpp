
//ABC_277_C
//map + BFS

#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=4e5+10;
vector<int>G[N];
bool vis[N];
unordered_map<int,int>id2h,h2id;
void solve(){

  
  int n;
  cin>>n;
  int cnt=1;
  id2h[1]=cnt;
  h2id[1]=cnt++;
  while(n--){

    int u,v;
    cin>>u>>v;
    if(h2id.find(u)==h2id.end()){
      id2h[cnt]=u;
      h2id[u]=cnt++;
      
      }
    if(h2id.find(v)==h2id.end()){
      id2h[cnt]=v;
      h2id[v]=cnt++;
    }
    u=h2id[u],v=h2id[v];
    G[u].push_back(v);
    G[v].push_back(u);
  }
  queue<int>q;
  q.push(1);
  vis[1]=1;
  int ans=1;
  while(!q.empty()){

    int fro=q.front();
    q.pop();
    ans=max(ans,id2h[fro]);
    for(int i=0;i<G[fro].size();i++){

      int tmp=G[fro][i];
      if(!vis[tmp]){

        vis[tmp]=1;
        q.push(tmp);

      }
    }
  }
  cout<<ans<<endl;

 
}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}