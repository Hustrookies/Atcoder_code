//ABC_307_D
//stack simulation
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=3e5+10;
const ll INF=1e18;


void solve(){

    int len;
    cin>>len;
    string s;
    cin>>s;
    stack<char>st;
    bool flag=0;
    int cnt=0;
    for(int i=0;i<len;i++){

        if(s[i]=='('){

            flag=1;
            cnt++;
            st.push(s[i]);
        }else if(s[i]==')'){

            if(flag){

                while(!st.empty()){

                    char top=st.top();
                    st.pop();
                    if(top=='(')break;
                }
                cnt--;
                if(!cnt)flag=0;
            }else {
                st.push(s[i]);
                flag=0;
            }
            
        }else st.push(s[i]);
    }
    if(st.size()==0){

        cout<<endl;
        return;
    }
    string ans;
    while(!st.empty()){

        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;

}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}