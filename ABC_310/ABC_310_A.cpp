//ABC_310_A
#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;

const int maxn = 2e5 + 10;


void solve(){
   
   int n,p,q;
   cin>>n>>p>>q;
   vector<int>dsh(n);
   for(auto &v:dsh)cin>>v;
   sort(dsh.begin(),dsh.end());
   cout<<min(p,q+dsh[0])<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  
    int test_case=1;
    //std::cin>>test_case;
    while(test_case--)solve();
    return 0;
}