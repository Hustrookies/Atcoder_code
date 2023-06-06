#include<bits/stdc++.h>
using namespace std;
#define ll long long 
string G1[40],G2[40];
void solve(){

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>G1[i];
    for(int i=1;i<=n;i++)cin>>G2[i];
    map<string,int>mp;
    for(int i=1;i<=n;i++)mp[G1[i]]++;
    for(int k=0;k<m;k++){

        //shift G2

        for(int i=1;i<=n;i++){

            char last=G2[i][m-1];
            for(int j=m-1;j>0;j--){

                G2[i][j]=G2[i][j-1];
            }
            G2[i][0]=last;
        }
        bool flag=1;
        for(int i=1;i<=n;i++){

            if(mp.find(G2[i])==mp.end()||mp[G2[i]]==0){
                flag=0;
                break;
            }
            mp[G2[i]]--;
        }
        if(flag){

            cout<<"Yes"<<endl;
            return;
        }
        mp.clear();
        for(int i=1;i<=n;i++)mp[G1[i]]++;
    }
    cout<<"No"<<endl;

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--)solve();
}