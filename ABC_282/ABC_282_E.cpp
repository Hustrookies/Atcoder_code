//ABC 282 E
//拿两个，只放回一个，其实就相当于拓扑排序
//划归成最大生成树问题，加一个快速幂
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,MOD;
//直接存边
struct node{

  ll u,v,w;
  bool operator <(const node &a)const{

    return w>a.w;
  }
  //node(ll a,ll b,ll c){u=a,v=b,w=c;}
};

ll fast_pow(ll a,ll n){

  ll ans=1;
  while(n){

    if(n&1) ans=(ans*a)%MOD;
    a=(a*a)%MOD;
    n>>=1;
  }
  return ans;
}
int fa[510];
int find(int x){

  if(x!=fa[x])fa[x]=find(fa[x]);
  return fa[x];
}
vector<node>e;
//priority_queue<node>q;
void prim(){

  int cnt=0;
  ll ans=0;
  for(int i=0;i<n*(n-1)/2;i++){

    int f1=find(e[i].u);
    int f2=find(e[i].v);
    if(f1==f2)continue;
    ans+=e[i].w;
    //cout<<e[i].u<<' '<<e[i].v<<' '<<ans<<endl;
    //注意这个join函数的写法
    fa[f1]=f2;
    if(++cnt==n-1)break;
  }
  cout<<ans<<endl;
}
void solve(){

   cin>>n>>MOD;
   //完全图
   e.resize(n*(n-1)/2);
   vector<ll>a(n+1);
   for(int i=1;i<=n;i++){
    cin>>a[i];
    fa[i]=i;
   }
   int cnt=0;
   for(int i=1;i<=n;i++){

    for(int j=i+1;j<=n;j++){

      ll tmp=(fast_pow(a[i],a[j])+fast_pow(a[j],a[i]))%MOD;
      e[cnt].u=i,e[cnt].v=j,e[cnt].w=tmp;
      cnt++;
    }
   }
   //边不多，直接prim
   sort(e.begin(),e.end());
   prim();
   
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1;
  //cin>>t;
  while(t--)solve();
  
}