//ABC_320_E
//priority_queue
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int time,no;
    bool operator <(const node a)const{

        return time>a.time;
    }
};

void solve(){
   

    int n,m;
    cin>>n>>m;
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i=1;i<=n;i++)q.push(i);
    //priority_queue<node,vector<node>,greater<node>>lst;
    priority_queue<node>lst;
    vector<long long>sum(n+1);
    while(m--){

        int t,w,s;
        cin>>t>>w>>s;
        while(!lst.empty()&&lst.top().time<=t){

            node tmp=lst.top();
            lst.pop();
            q.push(tmp.no);
        }
        
        if(q.empty())continue;
        int top=q.top();
        q.pop();
        node tmp;
        tmp.no=top,tmp.time=t+s;
        lst.push(tmp);
        sum[top]+=w;
    }
    for(int i=1;i<=n;i++)cout<<sum[i]<<endl;
}
int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
/*
3
3 2 3 10
7 8 9
5 3 5 11
2 3 4 5 6
5 7 2 19
2 3 4 5 6

*/