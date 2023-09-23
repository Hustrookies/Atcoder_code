//ABC_320_D
//build graph & DFS
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define int long long 
signed main(){

    
   map<pair<int,int>,pair<int ,int>>mp;
   int n,m;
   cin>>n>>m;
   vector<int>G[n+1];
   while(m--){

    int a,b,x,y;
    cin>>a>>b>>x>>y;
    mp[{a,b}]={x,y};
    mp[{b,a}]={-x,-y};
    G[a].push_back(b);
    G[b].push_back(a);
   }
   vector<bool>vis(n+1,0);
   vector<int>X(n+1,0),Y(n+1,0);
   function<void(int)> dfs=[&](int x){

    vis[x]=1;
    for(int i=0;i<G[x].size();i++){

        int nxt=G[x][i];
        if(!vis[nxt]){

            pair<int,int>tmp;
            tmp=mp[{x,nxt}];
            X[nxt]=X[x]+tmp.first;
            Y[nxt]=Y[x]+tmp.second;
            dfs(nxt);
        }
    }
   };
   dfs(1);
   for(int i=1;i<=n;i++){

    if(vis[i])cout<<X[i]<<' '<<Y[i]<<endl;
    else cout<<"undecidable"<<endl;
   }



}