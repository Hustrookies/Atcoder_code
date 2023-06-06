//ABC 298 D
//queue 模运算的性质加减乘
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=2e5+5;
const long long  INF=0x3f3f3f3f3f3f3f3fLL;
const int MOD=998244353;
const int MAX_SIZE=6e5+10;
ll POW10[MAX_SIZE];
void solve(){

  queue<int>q;
  int Q;
  cin>>Q;
  ll tmp=1;
  q.push(1);
  while(Q--){

    int op;
    cin>>op;
    
    if(op==1){

      int num;
      cin>>num;q.push(num);
      tmp=((tmp*10)%MOD+num)%MOD;
    }else if(op==2){

      int fro=q.front();
      int len=q.size();
      q.pop();
      tmp=(tmp+MOD-(fro*POW10[len-1])%MOD)%MOD;


    }else{

      cout<<tmp<<endl;
    }
  }
 	
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  POW10[0]=1;
    //初始化10^60000MOD的值
  for(int i=1;i<MAX_SIZE;i++){

    POW10[i]=(POW10[i-1]*10)%MOD;
  }
 int t=1;
  //cin>>t;
  while(t--)solve();
  
}