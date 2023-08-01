//ABC_310_B
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
const int N=2e6;
typedef long long ll;

void solve(){

    int n,m;
    cin>>n>>m;
    vector<int>P(n+1),C(n+1),F[n+1];
    set<int>S[m+1];
    for(int i=1;i<=n;i++){

        cin>>P[i]>>C[i];
        for(int j=1;j<=C[i];j++){

            int num;
            cin>>num;
            F[i].push_back(num);
            S[num].insert(i);
        }
    }
    bool flag=0;
    for(int i=1;i<=n;i++){

        for(int j=i+1;j<=n;j++){

            if(P[i]==P[j]&&C[i]!=C[j]){

                if(C[i]>C[j]) goto case1;
                else goto case2;

            }else if(P[i]>P[j]){

            case2:
                //all i in j
                int k=0;
                for(;k<C[i];k++){

                    if(S[F[i][k]].find(j)==S[F[i][k]].end())break;
                }
                if(k==C[i])flag=1;
            }else if(P[j]>P[i]){

            case1:
                //all j in i
                int k=0;
                for(;k<C[j];k++){

                    if(S[F[j][k]].find(i)==S[F[j][k]].end())break;
                }
                if(k==C[j])flag=1;
            }
        }
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

   
}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}