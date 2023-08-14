//ABC_314_B
//sort
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
const int N=2e6;
typedef long long ll;
struct node{

    int num;
    int bets;
    bool operator <(node a){

        if(bets==a.bets)return num<a.num;
        return bets<a.bets;
    }
};
vector<node>v[37];
void solve(){

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){

        int k;
        cin>>k;
        for(int j=1;j<=k;j++){

            int q;
            cin>>q;
            node tmp;
            tmp.num=i;
            tmp.bets=k;
            v[q].push_back(tmp);
        }
    }
    int Q;
    cin>>Q;
    sort(v[Q].begin(),v[Q].end());
    int cnt=0;
    for(int i=0;i<v[Q].size();i++){

        if(v[Q][i].bets==v[Q][0].bets)cnt++;
        else break;
    }
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)cout<<v[Q][i].num<<' ';
    //for(int i=0;i<cnt;i++)cout<<v[Q][i].num<<' '<<v[Q][i].bets<<endl;
    //cout<<endl;
   
}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}