//ABC_306_B
//multiset+simulation
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=2e5+10;
const ll INF=1e18;


void solve(){

    unsigned long long tmp=1;
    unsigned long long ans=0;
   for(int i=0;i<64;i++){

    int a;
    cin>>a;
    if(a)ans+=tmp;
    tmp<<=1;
   }
   cout<<ans<<endl;

}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}