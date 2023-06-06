//ABC_277_D
//cycle + map
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=4e5+10;

map<ll,ll>cnt;
map<ll,ll>id2num,num2id;
void solve(){

  
  int n,m;
  cin>>n>>m;
  ll ans=0,sum=0;
  vector<int>p;
  for(int i=0;i<n;i++){

    int tmp;
    cin>>tmp;
    p.push_back(tmp);
    cnt[tmp]++;
    sum+=tmp;
  }
  ans=sum;
  int t=1;
  for(auto it=cnt.begin();it!=cnt.end();it++){

    num2id[it->first]=t;
    id2num[t++]=it->first;
  }
  ll sum0=0;
  for(int i=1;i<t;i++){

    if(i>1&&id2num[i]==id2num[i-1]+1) continue;
    ll tmp_sum=0;
    for(int j=i;;j++){

      tmp_sum+=(cnt[id2num[j]]*id2num[j]);
      if(j==t-1){

          if(id2num[j]==m-1&&cnt.find(0)!=cnt.end())tmp_sum+=sum0;
          break;
      }
      if(id2num[j+1]!=id2num[j]+1)break;
      
    }
    if(id2num[i]==0)sum0=tmp_sum;
    ans=min(ans,sum-tmp_sum);

  }
 cout<<ans<<endl;
 
}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}