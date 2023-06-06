#include<bits/stdc++.h>
using namespace std;
#define ll long long 
string G[110];
int n,m;
int dfs(int x,int y){

	int cnt=0;
	for(int i=1;;i++){

		if(x-i<=0||y-i<0||G[x-i][y-i]=='.')break;
		if(x-i<=0||y+i>=m||G[x-i][y+i]=='.')break;
		if(x+i>n||y-i<0||G[x+i][y-i]=='.')break;
		if(x+i>n||y+i>=m||G[x+i][y+i]=='.')break;
		cnt++;
	}
	return cnt;
}
void solve(){

    
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>G[i];
	vector<int>cnt(min(n,m)+1,0);
	for(int i=1;i<=n;i++){

		for(int j=0;j<m;j++){

			if(G[i][j]=='#')cnt[dfs(i,j)]++;
		}
	}
	for(int i=1;i<=min(n,m);i++)cout<<cnt[i]<<' ';
    

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--)solve();
}