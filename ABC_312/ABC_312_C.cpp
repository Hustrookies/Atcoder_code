//ABC_312_C
//binary search
//notice that up_bound and low_bound return the pos in array,which mean that the
//index of the element in array
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=2e5+10;

void solve(){


    int n,m;
    cin>>n>>m;
    vector<int>seller(n),buyer(m);
    for(auto &v:seller)cin>>v;
    for(auto &v:buyer)cin>>v;
    sort(seller.begin(),seller.end());
    sort(buyer.begin(),buyer.end());
    //why l=1e9 cant AC
    int l=1,r=max(seller[n-1],buyer[m-1])+1;
    while(l<r){

        int mid=l+r>>1;
        int a=upper_bound(seller.begin(),seller.end(),mid)-seller.begin();
        int b=m-(lower_bound(buyer.begin(),buyer.end(),mid)-buyer.begin());
        if(a>=b)r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;
}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}