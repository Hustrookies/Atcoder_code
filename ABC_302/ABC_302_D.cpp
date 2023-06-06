//ABC_302_E
//set
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N=3e5+10;
set<int>s[N];
bool is_ctd[N];
int cnt;
void solve(){

    int n,q;cin>>n>>q;
    cnt=n;
    while(q--){

        int op;cin>>op;
        if(op==1){

            int u,v;cin>>u>>v;
            s[u].insert(v);s[v].insert(u);
            if(!is_ctd[u]){cnt--;is_ctd[u]=1;}
            if(!is_ctd[v]){cnt--;is_ctd[v]=1;}
            cout<<cnt<<endl;
        }else{

            int u;cin>>u;
            for(auto it = s[u].begin();it!=s[u].end();it++){

                s[*it].erase(u);
                if(s[*it].size()==0)if(is_ctd[*it]){cnt++;is_ctd[*it]=0;} 
            }
            s[u].clear();
            if(is_ctd[u]){cnt++;is_ctd[u]=0;}
            cout<<cnt<<endl;
        }
    }

  

 
}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}