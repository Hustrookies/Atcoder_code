//ABC_306_C
//sort
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=2e5+10;
const ll INF=1e18;
void solve(){

   int n;
   cin>>n;
   //vector<int>p(3*n);
   vector<int>f(n+1);
   vector<int>vis(n+1);
   for(int i=1;i<=3*n;i++){
    int p;
    cin>>p;
    vis[p]++;
    if(vis[p]==2)f[p]=i;
   }
   map<int,int>p2n;
   for(int i=1;i<=n;i++){
    p2n[f[i]]=i;
   }
   sort(f.begin(),f.end());
   for(int i=1;i<=n;i++)cout<<p2n[f[i]]<<' ';


}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}