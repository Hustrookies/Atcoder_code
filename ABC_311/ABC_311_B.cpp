//ABC_311_B
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
const int N=2e6;
typedef long long ll;

void solve(){

    int n,len;
    cin>>n>>len;
    vector<bool>is_free(len+1,1);
    for(int i=1;i<=n;i++){

        string S;
        cin>>S;
        for(int j=0;j<len;j++){

            if(S[j]=='x')is_free[j]=0;
        }

    }
    int Max=0;
    int tmp=0;
    for(int i=0;i<len;i++){

        if(is_free[i]){
            tmp++;
            Max=max(Max,tmp);
        }
        else tmp=0;
    }
    cout<<Max<<endl;
   
}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}