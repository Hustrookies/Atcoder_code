//ABC_305_E
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=2e5+10;
int n,m,k;
vector<int>G[N];
bool vis[N];
int cnt=0;
struct node
{
  int p,h;
  bool operator <(const node a) const{

    return h<a.h;
  }
};

void solve(){

  cin>>n>>m>>k;
  for(int i=1;i<=m;i++){

    int u,v;
    cin>>u>>v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  priority_queue<node>q;
  while(k--){

    int p,h;
    cin>>p>>h;
    node tmp;
    tmp.h=h,tmp.p=p;
    q.push(tmp);
  }
  for(int i=1;i<=n;i++){

    while(!q.empty()&&vis[q.top().p])q.pop();
    if(q.empty())break;
    node top=q.top();
    q.pop();
    vis[top.p]=1;
    if(top.h)
    for(auto &a:G[top.p]){

      if(!vis[a]){

           node tmp;
          tmp.h=top.h-1,tmp.p=a;
          q.push(tmp);
      }
    }
  }
  vector<int>ans;
  for(int i=1;i<=n;i++)if(vis[i])cnt++,ans.push_back(i);
  cout<<cnt<<endl;
  for(auto a:ans)cout<<a<<' ';
}
int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}