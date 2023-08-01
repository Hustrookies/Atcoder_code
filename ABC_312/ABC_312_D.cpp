//ABC_312_D
//DP

#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=1e5+10;
ll dp[3030][1550];
const ll MOD=998244353;
void solve(){

    int n;
    string s;
    cin>>s;
    n=s.length();
    if(n%2==1){

        cout<<0<<endl;
        return;
    }
    if(s[0]==')'){

        cout<<0<<endl;
        return;
    }
    dp[1][1]=1;
    int l=1,r=0;
    for(int i=2;i<=n;i++){

        if(s[i-1]=='('){
            l++;
            for(int j=max(l,(i+1)/2);j<=min(i-r,n/2);j++)if(i/2<=(j-1))dp[i][j]=(dp[i-1][j-1])%MOD;
        }else if(s[i-1]==')'){
            r++;
            for(int j=max(l,(i+1)/2);j<=min(i-r,n/2);j++)dp[i][j]=dp[i-1][j];
        }else{

            for(int j=max(l,(i+1)/2);j<=min(i-r,n/2);j++){
            
                if(i/2<=(j-1))dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%MOD;
                else dp[i][j]=dp[i-1][j];
            }
        }
        
    }
    cout<<dp[n][n/2]<<endl;
    
}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}