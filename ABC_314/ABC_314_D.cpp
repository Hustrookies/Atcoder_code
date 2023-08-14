//ABC_314_D
//simu

#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
void to_upper(char &c){

    if(c>='a'&&c<='z')c+='A'-'a';
}
void to_lower(char &c){

    if(c>='A'&&c<='Z')c+='a'-'A';
}

void solve(){

    int n;
    cin>>n;
    string s;
    cin>>s;
    int Q;
    cin>>Q;
    int upp=0,low=0;
    vector<int>pos(n,0);
    for(int i=1;i<=Q;i++){

        int t,x;
        char c;
        cin>>t>>x>>c;
        if(t==1){
            s[x-1]=c;
            pos[x-1]=i;
        }
        else if(t==2)low=i;
        else upp=i;
    }
    bool flag=0;
    if(upp>low)flag=1;
    for(int i=0;i<n;i++){

        if(flag){

            if(upp>pos[i])to_upper(s[i]);
        }else{

            if(low>pos[i])to_lower(s[i]);
        }
    }
    cout<<s<<endl;
    
}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}