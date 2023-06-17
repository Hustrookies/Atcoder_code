//ABC_306_A
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=2e5+10;
const ll INF=1e18;


void solve(){

int c;
cin>>c;
    string a;
    cin>>a;
    string ans;
    for(int i=0;i<a.size();i++)ans.push_back(a[i]),ans.push_back(a[i]);
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