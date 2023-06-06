//ABC_302_B
//dfs+direction in array
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
string G[110];
int n,m;
char ch[]="snuke";
int dir[8][2]={-1,-1,0,-1,1,-1,-1,0,1,0,-1,1,0,1,1,1};
vector<pair<int,int>> ans;
void print(int x,int y,int op){

  for(int i=1;i<=5;i++){

    //cout<<x+1<<' '<<y+1<<endl;
    ans.push_back({x+1,y+1});
    x-=dir[op][0];
    y-=dir[op][1];
  }
}

void dfs(int x,int y,int op,int dep){

  if(x<0||x>=n||y<0||y>=m) return;
  if(dep==4&&G[x][y]=='e'){

    print(x,y,op);
  }
  if(G[x][y]!=ch[dep])return;
  dfs(x+dir[op][0],y+dir[op][1],op,dep+1);

}

void solve(){

  
  cin>>n>>m;
  for(int i=0;i<n;i++)cin>>G[i];
  for(int i=0;i<n;i++){

    for(int j=0;j<m;j++){

      for(int k=0;k<8;k++){

        dfs(i,j,k,0);
      }
    }
  }
  for(int i=4;i>=0;i--)cout<<ans[i].first<<' '<<ans[i].second<<endl;
}

int main(){
   
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}