//ABC_279_D
//math,float operation
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
double a,b;
double get(ll x){

  return b*x+a/pow(1+x,1.0/2.0);
}
void solve(){

  
  cin>>a>>b;
  if(b>=a/2){

    cout<<a<<endl;
  }else{

    double t=pow(a/(2*b),2.0/3.0)-1;
    double a1=get((ll) t),a2=get((ll)(t+1));
    if(a1<a2){

      printf("%.7lf\n",a1);
    }else printf("%.7lf\n",a2);
  }
  
 
}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
