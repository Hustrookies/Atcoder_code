
//ABC_278_C
//map + set
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=4e5+10;
unordered_map<int,int> id2num;
set<int>s[N];
void solve(){

  
  int n,q;
  cin>>n>>q;
  int cnt=0;
  while(q--){

    int op;
    cin>>op;
    int a,b;
    cin>>a>>b;
    int num_a,num_b;
    if(id2num.find(a)==id2num.end()){

        id2num[a]=cnt++;
      }
      if(id2num.find(b)==id2num.end()){

        id2num[b]=cnt++;
      }
      num_a=id2num[a],num_b=id2num[b];
    if(op==1)s[num_a].insert(num_b);
    else if(op==2)s[num_a].erase(num_b);
    else{
      if(s[num_a].find(num_b)==s[num_a].end()||s[num_b].find(num_a)==s[num_b].end())
        cout<<"No"<<endl;
      else cout<<"Yes"<<endl;
    }
  }

 
}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}