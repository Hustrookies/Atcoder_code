//ABC_320_B
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl '\n'
int main(){

   string s;
   cin>>s;
   int ans=1;
   int len=s.size();
   for(int i=0;i<len;i++){

    int tmp=1;
    for(int j=1;;j++){

        if(i-j<0||i+j>=len)break;
        else if(s[i-j]!=s[i+j])break;
        else tmp+=2;
    }
    ans=max(ans,tmp);
   }
   for(int i=0;i<len-1;i++){

    if(s[i]!=s[i+1])continue;
    int tmp=2;
    for(int j=1;;j++){

        if(i-j<0||i+j+1>=len)break;
        else if(s[i-j]!=s[i+j+1])break;
        else tmp+=2;
    }
    ans=max(ans,tmp);
   }
   cout<<ans<<endl;

}