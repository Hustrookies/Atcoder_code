//ABC_309_B
//simulation
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
const int N=2e6;
typedef long long ll;

string G[110];
string ans[110];
void solve(){

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>G[i];
        ans[i]=G[i];
    }
    for(int i=n-1;i>0;i--){

        ans[0][i]=G[0][i-1];
        ans[i][n-1]=G[i-1][n-1];
        ans[n-1][i]=G[n-1][i+1];
        ans[i][0]=G[i+1][0];
        
    }
    ans[0][0]=G[1][0];
    ans[0][n-1]=G[0][n-2];
    ans[n-1][n-1]=G[n-2][n-1];
    ans[n-1][0]=G[n-1][1];
    for(int i=0;i<n;i++)cout<<ans[i]<<endl;

}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}