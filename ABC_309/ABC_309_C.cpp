//ABC_309_C
//sort
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=2e5+10;
struct mdn
{
    ll day,num;
    bool operator <(const mdn A)const{

        return day<A.day;
    }
};

void solve(){


    ll n,k;
    cin>>n>>k;
    vector<mdn>m(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>m[i].day>>m[i].num;
        sum+=m[i].num;
    }
    sort(m.begin(),m.end());
    if(sum<=k){

        cout<<1<<endl;
        return;
    }
    for(int i=0;i<n;i++){

        sum-=m[i].num;
        if(sum<=k){

            cout<<m[i].day+1<<endl;
            return;
        }
    }

}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}