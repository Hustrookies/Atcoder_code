//ABC_325_D
//greedy,priority_queue
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct pdt
{
  int be,ed;
  bool operator >(const pdt a)const{

      return ed>a.ed;
  }
  pdt(int a,int b){be=a,ed=b;}
};

void solve(){
   
  int n;
  cin>>n;
  vector<pair<int,int>>v;
  for(int i=0;i<n;i++){

    int t,d;
    cin>>t>>d;
    v.emplace_back(t,t+d);
  }
  sort(v.begin(),v.end());
  //for(int i=0;i<n;i++)cout<<v[i].first<<' '<<v[i].second<<endl;
  priority_queue<pdt,vector<pdt>,greater<>>p;
  bool flag=1;
  int tmp_no=0,ti=0,cnt=0;
  while(flag){

    if(tmp_no<n&&p.empty()){

      ti=v[tmp_no].first;
      p.push(pdt(v[tmp_no].first,v[tmp_no].second));
      tmp_no++;
    }
    while(tmp_no<n&&v[tmp_no].first<=ti){
      p.push(pdt(v[tmp_no].first,v[tmp_no].second));
      tmp_no++;
    }
    ti++;
    cnt++;
    p.pop();
    while(!p.empty()&&p.top().ed<ti)p.pop();
    if(tmp_no==n&&p.empty())flag=0;
  }
  cout<<cnt<<endl;
}
signed main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
/*
3
3 2 3 10
7 8 9
5 3 5 11
2 3 4 5 6
5 7 2 19
2 3 4 5 6

*/