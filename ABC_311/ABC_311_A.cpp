//ABC_311_A
#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;

const int maxn = 2e5 + 10;


void solve(){
   
   int len;
   cin>>len;
   string S;
   cin>>S;
   int A=0,B=0,C=0;
   for(int i=0;i<len;i++){

    if(S[i]=='A')A=1;
    else if(S[i]=='B')B=1;
    else C=1;

    if(A&&B&&C){

        cout<<i+1<<endl;
        break;
    }
   
   }
}

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  
    int test_case=1;
    //std::cin>>test_case;
    while(test_case--)solve();
    return 0;
}