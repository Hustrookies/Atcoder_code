#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
int dst[]={0,3,1,4,1,5,9};
void solve(){
 
  for(int i=1;i<=6;i++)dst[i]+=dst[i-1];
  char a,b;
  cin>>a>>b;
  if(b<a)swap(a,b);
  a-='A',b-='A';
  cout<<dst[b]-dst[a]<<endl;
}
 
int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}