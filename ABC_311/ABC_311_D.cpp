//ABC_311_D
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=150010;
const ll INF=1e18;

vector<string>G(300);
bool vis[300][300];
bool start[300][300];
int cnt=0;
//0,1,2,3
//right,up,left,down
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void dfs(int x,int y,int dir){

    if(!vis[x][y])cnt++;
    vis[x][y]=1;
    //ice
    if(G[x+dx[dir]][y+dy[dir]]=='.')dfs(x+dx[dir],y+dy[dir],dir);
    //rock
    else{

        if(!start[x][y]){

            start[x][y]=1;
            for(int i=0;i<4;i++){

                //dont go back!
                if(abs(dir-i)!=2)if(G[x+dx[i]][y+dy[i]]=='.')dfs(x+dx[i],y+dy[i],i);
                
            }
        }
    }
}
void solve(){

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>G[i];
    for(int i=0;i<4;i++)dfs(1,1,i);
    cout<<cnt<<endl;
}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}