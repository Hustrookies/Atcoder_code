//ABC 281 E
//set simulation
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){


  int n,m,k;
  cin>>n>>m>>k;
  vector<int>a(n);
  for(auto &v:a) cin>>v;
  ll sum_k=0;
  vector<ll> ans;
  //初始化set
  multiset<ll>first_k;
  multiset<ll>last_m;
  vector<int>tmp(m);
  for(int i=0;i<m;i++)tmp[i]=a[i];
  sort(tmp.begin(),tmp.end());
  //for(int i=0;i<m;i++)cout<<tmp[i]<<endl;
  for(int i=0;i<m;i++){

    if(i<k){
      first_k.insert(tmp[i]);
      sum_k+=tmp[i];
    }
    else last_m.insert(tmp[i]);
  }
  ans.push_back(sum_k);
  //保证集合不为空，否则查找可能会有问题
  //last_m.insert(1e16);
  //模拟更新的过程
  for(int i=m;i<n;i++){

    //删去前一个区间的最前面元素
    auto itf=first_k.find(a[i-m]);
    auto itl=last_m.find(a[i-m]);
    if(itf!=first_k.end()) {
      first_k.erase(itf);
      sum_k-=a[i-m];
    }
    else if(last_m.size()>0)last_m.erase(itl);
    else {cout<<"ERROR"<<endl;}
    //加入后一个区间的最后元素
    last_m.insert(a[i]);
    //调整两个集合
    if(first_k.size()<k){

      auto tmp=last_m.begin();
      first_k.insert(*tmp);
      sum_k+=*tmp;
      last_m.erase(tmp);
    }
    auto loff=--first_k.end();
    auto fofl=last_m.begin();
    if(fofl==last_m.end()) {
      ans.push_back(sum_k);
      continue;
    }
    //前一个区间的最大值大于后一个区间最小值
    if(*(loff)>*fofl){
      sum_k+=(*fofl-*loff);
      first_k.insert(*fofl);
      last_m.erase(fofl);
      last_m.insert(*loff);
      first_k.erase(loff);
      
    }
    ans.push_back(sum_k);

  }
  for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
  cout<<endl;
  
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1;
  //cin>>t;
  while(t--)solve();
  
}
