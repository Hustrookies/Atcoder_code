//ABC_302_C
//next_permutation
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
int n,m;
string G[10];
bool check(vector<int> p){

  for(int i=1;i<n;i++){

    int cnt=0;
    for(int j=0;j<m;j++){

      if(G[p[i-1]][j]!=G[p[i]][j])cnt++;
    }
    if(cnt!=1)return 0;
  }
  return 1;
}
void solve(){

 
  cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>G[i];
  vector<int> p;
  for(int i=1;i<=n;i++)p.push_back(i);
  do{

    if(check(p)){

      cout<<"Yes"<<endl;
      return;
    }

  }while(next_permutation(p.begin(),p.end()));
  cout<<"No"<<endl;
}

int main(){
   
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}