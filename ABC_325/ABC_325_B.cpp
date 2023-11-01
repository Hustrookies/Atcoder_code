//ABC_325_B
//mod culculation
#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
   
   int n;
   cin>>n;
   vector<int>w(n),x(n);
   for(int i=0;i<n;i++)cin>>w[i]>>x[i];
   int ans=0;
   for(int i=0;i<24;i++){

    int tmp=0;
    for(int j=0;j<n;j++){

        int tm=(x[j]+i)%24;
        if(tm>=9&&tm<=17)tmp+=w[j];
    }
    ans=max(ans,tmp);
   }
   cout<<ans<<endl;

}
signed main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
/*
3
3 2 3 10
7 8 9
5 3 5 11
2 3 4 5 6
5 7 2 19
2 3 4 5 6

*/