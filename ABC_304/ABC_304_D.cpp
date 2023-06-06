//ABC_304_C
//binary search + map
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=2e5+10;


int x[N],y[N],A[N],B[N];

void solve(){

    int W,H,n,a,b;
    //W->x,H->Y
    cin>>W>>H>>n;
    for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
    cin>>a;
    for(int i=1;i<=a;i++)cin>>A[i];
    cin>>b;
    for(int i=1;i<=b;i++)cin>>B[i];
    map<pair<int,int>,int>mp;
    for(int i=1;i<=n;i++){

        int tmp_x=lower_bound(A,A+a+1,x[i])-A;
        int tmp_y=lower_bound(B,B+b+1,y[i])-B;
        mp[{tmp_x,tmp_y}]++;
    }
    int Max=0,Min=n+1;
    ll cnt=0;
    for(auto it=mp.begin();it!=mp.end();it++){

        Max=max(Max,it->second);
        Min=min(Min,it->second);
        cnt++;
    }
    if(cnt<(ll)(a+1)*(b+1)){

        cout<<0<<' '<<Max<<endl;
    }else cout<<Min<<' '<<Max<<endl;

}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}