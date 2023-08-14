//ABC_314_C
//simu
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=2e5+10;

void solve(){


    int len,m;
    cin>>len>>m;
    string s;
    cin>>s;
    vector<int>clr(len);
    vector<int>v[m+1];
    for(int i=0;i<len;i++){
        cin>>clr[i];
        v[clr[i]].push_back(i);
    }
    for(int i=1;i<=m;i++){

        char tail=s[v[i].back()];
        for(int j=v[i].size()-1;j>0;j--)s[v[i][j]]=s[v[i][j-1]];
        s[v[i][0]]=tail;
    }
    cout<<s<<endl;

}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}