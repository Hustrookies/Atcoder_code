//ABC_312_B
//simulation
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
const int N=2e6;
typedef long long ll;
string M[110];
bool check(int x,int y){

    for(int i=0;i<4;i++){

        for(int j=0;j<4;j++){

            if(i<3&&j<3){
                if(M[x+i][y+j]!='#'||M[x+i][y+j]!=M[8+x-i][8+y-j])return 0;
            }else if(M[x+i][y+j]!='.'||M[x+i][y+j]!=M[8+x-i][8+y-j])return 0;
        }
    }
    return 1;
}
void solve(){

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>M[i];
    for(int i=0;i<n-8;i++){

        for(int j=0;j<m-8;j++){

            if(check(i,j))cout<<i+1<<' '<<j+1<<endl;
        }
    }
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