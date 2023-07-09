//ABC_309_D
//BFS record the depth
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=150010;
const ll INF=1e18;

vector<int>G[2*N];
bool vis[2*N];
void solve(){

    int n1,n2,m;
    cin>>n1>>n2>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int dep1=0,dep2=0;
    queue<pair<int,int>>q;
    q.push({1,1});
    vis[1]=1;
    while(!q.empty()){

        auto fro=q.front();
        dep1=max(dep1,fro.second);
        q.pop();
        for(int i=0;i<G[fro.first].size();i++){

            int tmp=G[fro.first][i];
            if(!vis[tmp]){

                vis[tmp]=1;
                q.push({tmp,fro.second+1});
            }
        }
    }
    q.push({n1+n2,1});
    vis[n1+n2]=1;
    while(!q.empty()){

        auto fro=q.front();
        dep2=max(dep2,fro.second);
        q.pop();
        for(int i=0;i<G[fro.first].size();i++){

            int tmp=G[fro.first][i];
            if(!vis[tmp]){

                vis[tmp]=1;
                q.push({tmp,fro.second+1});
            }
        }
    }
    //cout<<dep1<<' '<<dep2<<endl;
    cout<<dep1+dep2-1<<endl;

}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}