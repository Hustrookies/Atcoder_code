//ABC_312_A
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 10;


void solve(){
   
   string S;
   map<string,int>mp;
   mp["ACE"]=1;
   mp["BDF"]=1;
   mp["CEG"]=1;
   mp["DFA"]=1;
   mp["EGB"]=1;
   mp["FAC"]=1;
   mp["GBD"]=1;
   cin>>S;
   if(mp.find(S)!=mp.end())cout<<"Yes"<<endl;
   else cout<<"No"<<endl;
   
}

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  
    int test_case=1;
    //std::cin>>test_case;
    while(test_case--)solve();
    return 0;
}