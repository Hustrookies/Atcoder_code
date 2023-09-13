//ABC_319_D
//binary search
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll p[200010];
int m,n;
bool check(ll wid){

    ll tmp=0,line=1;
    for(int i=1;i<=n;i++){

        if(tmp+p[i]<=wid)tmp+=p[i];
        else tmp=p[i],line++;
        if(i==n)break;
        //blank or shift
        if(tmp>=wid-1)tmp=0,line++;
        else tmp++;
    }
    if(line<=m)return 1;
    else return 0;
}
int main(){

    
    cin>>n>>m;
    ll Max=0;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        Max=max(Max,p[i]);
    }
    ll r=1e18,l=Max;
    while(l<r){

        ll mid=r+l>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;

}