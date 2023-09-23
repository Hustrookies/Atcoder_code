//ABC_319_B
//simulation & permutaion
#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){

    
  int n;
  cin>>n;
  string S[3];
  for(int i=0;i<3;i++){

    cin>>S[i];
    string tmp=S[i];
    for(int j=1;j<=2;j++)tmp+=S[i];
    S[i]=tmp;
  }
  int pos[10];
  for(int i=0;i<10;i++){

    int cnt=0;
    vector<int>pos_t[3];
    for(int j=0;j<3*n;j++){

      if(S[0][j]-'0'==i)pos_t[0].push_back(j);
      if(S[1][j]-'0'==i)pos_t[1].push_back(j);
      if(S[2][j]-'0'==i)pos_t[2].push_back(j);
      bool flag=0;
      if(!pos_t[0].empty()&&!pos_t[1].empty()&&!pos_t[2].empty()){

        for(int a=0;a<pos_t[0].size();a++){

          for(int b=0;b<pos_t[1].size();b++){

            for(int c=0;c<pos_t[2].size();c++){

              if(pos_t[0][a]!=pos_t[1][b]&&pos_t[0][a]!=pos_t[2][c]&&pos_t[1][b]!=pos_t[2][c])flag=1;
            }
          }
        }
        
      }
      if(flag){

        pos[i]=j;
        break;
      }

    }
      
  }
  int ans=3*n+1;
  for(int i=0;i<10;i++){

    if(pos[i])ans=min(ans,pos[i]);
  }
  if(ans<3*n+1)cout<<ans<<endl;
  else cout<<-1<<endl;

  
}