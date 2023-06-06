//ABC 287 C
//dfs to judge whether a graph is a path
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=2e5+5;
const long long  INF=0x3f3f3f3f3f3f3f3fLL;
const int MOD=998244353;
const int MAX_SIZE=6e5+10;
vector<int>G[N];
bool vis[N];
int ans=0;
void dfs(int p,int dep){
	
	vis[p]=1;
	ans=max(ans,dep);
	for(int i=0;i<G[p].size();i++){
		
		if(!vis[G[p][i]])dfs(G[p][i],dep+1);
	}
}
void solve(){

 	
 	int n,m;
 	cin>>n>>m;
 	for(int i=1;i<=m;i++){
 		
 		int u,v;
 		cin>>u>>v;
 		G[u].push_back(v);
 		G[v].push_back(u);
	 }
	 int cnt_1=0,cnt_2=0;
	 for(int i=1;i<=n;i++){
	 	
	 	if(G[i].size()==1){
	 		
	 		dfs(i,1);
		 }
	 
	 }
	 if(m==n-1&&ans==n){
	 	
	 	cout<<"Yes"<<endl;
	 }else{
	 	
	 	cout<<"No"<<endl;
	 }
 	
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 int t=1;
  //cin>>t;
  while(t--)solve();
  
}
