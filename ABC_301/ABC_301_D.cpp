//ABC_301_D
//bit + gready
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=2e5+10;
string s;
ll n;
ll str2int(string a){

  ll ans=0;
  int len=a.size();
  for(int i=len-1;i>=0;i--){

    if(a[i]=='1')ans+=(1LL<<(len-1-i));
  }
  return ans;
}
void solve(){

  cin>>s>>n;
  int len=s.size();
  vector<int> pos;
  for(int i=len-1;i>=0;i--){

    if(s[i]=='?')pos.push_back(len-1-i);
  }
  string MIN;
  for(int i=0;i<len;i++){

    if(s[i]=='?')MIN.push_back('0');
    else MIN.push_back(s[i]);
  }
  ll tmp=str2int(MIN);
  if(tmp>n){

    cout<<-1<<endl;
    return;
  }
  for(int i=pos.size()-1;i>=0;i--){

    if(tmp+(1LL<<pos[i])<=n)tmp+=(1LL<<pos[i]);
  }
  cout<<tmp<<endl;

 
}

int main(){
   
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}