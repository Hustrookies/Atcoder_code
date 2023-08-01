//ABC_310_C
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=2e5+10;

void solve(){


    int n;
    cin>>n;
    set<string>S;
    while(n--){

        string s;
        cin>>s;
        if(S.find(s)==S.end()){
            reverse(s.begin(),s.end());
            if(S.find(s)==S.end()){

                S.insert(s);
            }
        }
    }
    cout<<S.size()<<endl;
    
}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}