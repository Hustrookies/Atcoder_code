//ABC_279_C
//map
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;

void solve(){

  int n,m;
  cin>>n>>m;
  vector<string>S,T;
  unordered_map<string,int>mp_S,mp_T;
  for(int i=0;i<n;i++){

    string tmp;
    cin>>tmp;
    S.push_back(tmp);
  }
  for(int i=0;i<n;i++){

    string tmp;
    cin>>tmp;
    T.push_back(tmp);
  }
  for(int i=0;i<m;i++){

    string tmp1,tmp2;
    for(int j=0;j<n;j++){

      tmp1.push_back(S[j][i]);
      tmp2.push_back(T[j][i]);
    }
    mp_S[tmp1]++;
    mp_T[tmp2]++;
  }
  bool flag=1;
  for(auto it=mp_S.begin();it!=mp_S.end();it++){

    if(mp_T.find(it->first)==mp_T.end()||it->second!=mp_T[it->first]){

      flag=0;
      break;
    }
  }
  if(flag) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  
 
}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}