//ABC_319_B
//simulation & permutaion
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int a[10];

bool check(int a,int b){

  //col
  if(a%3==b%3)return 1;
  //row
  if((a-1)/3==(b-1)/3)return 1;
  //dia
  if(a+b==10)return 1;
  //dia
  if(a==5||b==5) return 1;
  return 0;
}
int getTheOther(int a,int b){

  if(a%3==b%3){

    int rst=a%3;
    if(rst==1)return 12-a-b;
    if(rst==2)return 15-a-b;
    else return 18-a-b;
  }
  if((a-1)/3==(b-1)/3){

    int div=(a-1)/3;
    if(div==0)return 6-a-b;
    if(div==1)return 15-a-b;
    else return 24-a-b;
  }
  if(a+b==10)return 5;
  if(a==5||b==5) return 15-a-b;
}
int main(){

    
  for(int i=1;i<=9;i++)cin>>a[i];
  int p[]={1,2,3,4,5,6,7,8,9};
  int cnt=0;
  do{

    vector<int>tmp;
    for(int i=0;i<9;i++)tmp.push_back(a[p[i]]);
    vector<int>pos[10];
    vector<bool>vis(10,0);
    bool flag=0;
    for(int i=0;i<9;i++){

      if(flag)break;
      if(pos[tmp[i]].empty())pos[tmp[i]].push_back(p[i]);
      else {

        int num=tmp[i];
        for(int j=0;j<pos[num].size();j++){

          if(check(pos[num][j],p[i])){

            int other=getTheOther(pos[num][j],p[i]);
            if(!vis[other]){
              flag=1;
              break;
            }
          }
        }
        pos[num].push_back(p[i]);
      }
      vis[p[i]]=1;
    }
    if(flag)cnt++;
  }while(next_permutation(p,p+9));
  //362880;
  double ans=(362880-cnt)*1.0/362880;
  printf("%.10lf\n",ans);

  
}