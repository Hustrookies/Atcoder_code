//ABC_301_E
//bit DP+DFS
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=2e5+10;
int n,m,MAX;
int dp[1<<20][25];
int dist[25][25];
string G[340];
const int dir[4][2]={1,0,-1,0,0,1,0,-1};
bool vis[340][340];
int get(int s){

  int ans=0;
  while(s){

    if(s&1)ans++;
    s>>=1;
  }
  return ans;
}
struct node{

  int x,y,dep;
};
// check whether pos is leagel
bool check(int x,int y){

  if(vis[x][y]) return 0;
  if(G[x][y]=='#') return 0;
  if(x<1||x>n||y<0||y>=m) return 0;
  return 1;
}
void solve(){

  
  memset(dp,0x3f,sizeof(dp));
  memset(dist,0x3f,sizeof(dist));
  cin>>n>>m>>MAX;
  //row:1 to n clm:0 to m-1
  for(int i=1;i<=n;i++)cin>>G[i];
  // pos of cdy and S,G
  vector<pair<int,int>>pos;
  //map from pos to number
  map<pair<int,int>,int>pos2num;
  
  int ans=0;
  int cdy=0;
  for(int i=1;i<=n;i++)
    for(int j=0;j<m;j++)if(G[i][j]=='S'){cdy++;pos.push_back({i,j});pos2num[{i,j}]=cdy;}  
  for(int i=1;i<=n;i++)
    for(int j=0;j<m;j++)if(G[i][j]=='o'){cdy++;pos.push_back({i,j});pos2num[{i,j}]=cdy;}  
  for(int i=1;i<=n;i++)
    for(int j=0;j<m;j++)if(G[i][j]=='G'){cdy++;pos.push_back({i,j});pos2num[{i,j}]=cdy;}
  for(int i=0;i<cdy;i++){

    //bfs
    memset(vis,0,sizeof(vis));
    queue<node>q;
    node tmp;
    tmp.x=pos[i].first,tmp.y=pos[i].second,tmp.dep=0;
    q.push(tmp);
    vis[pos[i].first][pos[i].second]=1;
    while(!q.empty()){

      node fro=q.front();
      q.pop();
      if(pos2num.find({fro.x,fro.y})!=pos2num.end())dist[i+1][pos2num[{fro.x,fro.y}]]=fro.dep;
      for(int k=0;k<4;k++){

        if(check(fro.x+dir[k][0],fro.y+dir[k][1])){
          vis[fro.x+dir[k][0]][fro.y+dir[k][1]]=1;
          node tmp;
          tmp.x=fro.x+dir[k][0],tmp.y=fro.y+dir[k][1],tmp.dep=fro.dep+1;
          q.push(tmp);
        }
      }

    }

  }
  if(dist[1][cdy]>MAX){
    cout<<-1<<endl;
    return;
  }
  // for(int i=0;i<cdy;i++){

  //   cout<<pos[i].first<<' '<<pos[i].second<<':';
  //   for(int j=0;j<cdy;j++){

  //     cout<<dist[i+1][j+1]<<' ';

  //   }
  //   cout<<endl;
  // }
  //bit dp

  //???why
  dp[1][1]=0;
  for(int S=1;S<(1<<cdy);S++){
  
    for(int j=0;j<cdy;j++){

      if((S>>j)&1)
        for(int k=0;k<cdy;k++){

          if((S^(1<<j)>>k&1))
            dp[S][j+1]=min(dp[S][j+1],dp[S^(1<<j)][k+1]+dist[k+1][j+1]);
        }
    }
    if(dp[S][cdy]<=MAX)ans=max(ans,get(S)-2);
  }
  //cout<<dp[1][1]<<endl;
  //cout<<cdy<<endl;
  //cout<<dp[(1<<cdy)-1][cdy]<<endl;
  cout<<ans<<endl;
 
}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}