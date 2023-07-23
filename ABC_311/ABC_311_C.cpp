//ABC_311_C
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=2e5+10;
int nxt[N];
int in_deg[N];
bool notInTheCycle[N];
void solve(){


    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>nxt[i];
        in_deg[nxt[i]]++;
    }
    queue<int>q;
    for(int i=1;i<=n;i++){

        if(in_deg[i]==0)q.push(i);
    }
    while(!q.empty()){

        int fro=q.front();
        q.pop();
        notInTheCycle[fro]=1;
        int tmp=nxt[fro];
        in_deg[tmp]--;
        if(in_deg[tmp]==0)q.push(tmp);
    }
    vector<int>ans;
    int cnt=0;
    for(int i=1;i<=n;i++){

        if(!notInTheCycle[i]){

            vector<bool>vis(n+1);
            int tmp=i;
            while(!vis[tmp]){

                vis[tmp]=1;
                ans.push_back(tmp);
                cnt++;
                tmp=nxt[tmp];
               
            }
            break;
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)cout<<ans[i]<<' ';
    
}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}