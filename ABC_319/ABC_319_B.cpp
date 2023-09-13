//ABC_319_B
//easy simulation
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){

    int n;
    cin>>n;
    string ans;
    for(int i=0;i<=n;i++){

        bool flag=0;
        for(int j=1;j<=9;j++){

            if(n%j==0&&i%(n/j)==0){

                flag=1;
                ans.push_back(char('0'+j));
                break;
            }
        }
        if(!flag)ans.push_back('-');
    }
    cout<<ans<<endl;
}