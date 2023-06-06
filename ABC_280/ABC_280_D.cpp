//ABC_280_D
//math
//Decompose prime factors
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6;
int cnt[N+5];
bool is_even[N+5];
int get(int x,int n){

  int cnt=0;
  for(int i=x;;i+=x){

    int tmp=i;
    while(tmp%x==0){

      cnt++;
      tmp/=x;
    }
    if(cnt>=n){

      return i;
    }
  }
}
int main(){
  
   for(int i=2;i<=N;i++){

    if(!is_even[i]){//is prime

      int cnt=2;
      while(cnt*i<=N){
        is_even[cnt*i]=1;
        cnt++;
      }
    }
   }
   //for(int i=2;i<=100;i++)if(!is_even[i])cout<<i<<endl;
   ll n;
   cin>>n;
   ll MAX=pow(n,0.5);
   for(int i=2;i<=MAX;i++){

    if(n==1)break;
    if(!is_even[i]){

      while(n%i==0){


        n/=i;
        cnt[i]++;
      }
    }
   }
   if(n>1){

    cout<<n<<endl;
    return 0;
   }
   int ans=1;
   for(int i=2;i<=N;i++){

    if(cnt[i]){

      ans=max(ans,get(i,cnt[i]));
    }
   }
   cout<<ans<<endl;
}