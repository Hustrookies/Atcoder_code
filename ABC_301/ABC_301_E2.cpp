//ABC_301_E_2
//bit DP+DFS
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
struct node {

  int x,y,z;
  node(int a,int b,int c):x(a),y(b),z(c){}
};
int dist[20][20];
int get_dist(node a,node b){

  return abs(a.x-b.x)+abs(a.y-b.y)+max(0,b.z-a.z);
}
int dp[1<<18][19];
void solve(){

  int n;
  cin>>n;
  vector<node> p;
  for(int i=0;i<n;i++){

    int x,y,z;
    cin>>x>>y>>z;
    p.push_back(node(x,y,z));
  }
  //back to the start
  p.push_back(p[0]);
  for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++){

      dist[i][j]=get_dist(p[i],p[j]);
    }
  memset(dp,0x3f,sizeof(dp));
  dp[1][0]=0;
  for(int S=1;S<(1<<(n+1));S++){

    for(int j=0;j<=n;j++){

      if(S&(1<<j)){

        for(int k=0;k<=n;k++){

          dp[S][j]=min(dp[S][j],dp[S^(1<<j)][k]+dist[k][j]);
        }
      }
    }
  }
  cout<<dp[(1<<(n+1))-1][n]<<endl;
 
 
}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}