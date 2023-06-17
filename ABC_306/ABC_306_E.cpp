//ABC_306_E
//multiset+simulation
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=5e5+10;
const ll INF=1e18;
int p[N];

void solve(){

   int n,k,q;
   //cin>>n>>k>>q;
   scanf("%d%d%d",&n,&k,&q);
   //s1:n-k,s1:k
   multiset<int>s1,s2;
   for(int i=1;i<=n;i++){

    if(i<=n-k)s1.insert(0);
    else s2.insert(0);
   }
   ll ans=0;
   if(s1.empty())s1.insert(-100);
   //O(n)
   while(q--){

    int x,y;
    //cin>>x>>y;
    scanf("%d%d",&x,&y);
    //O(logn)
    auto it=s2.lower_bound(p[x]); 
    if(it!=s2.end()&&*it==p[x]){ //p[x] in s2
        
        ans-=p[x];
        //O(logn)
        s2.erase(it);
        if(y>=*(--s1.end())){

            ans+=y;
            s2.insert(y);
        }else{

            auto s1_b=prev(s1.end());
            ans+=*s1_b;
            s1.insert(y);
            s2.insert(*s1_b);
            s1.erase(s1_b);
        }
    }else{ //p[x] in s1

        s1.erase(s1.lower_bound(p[x]));
        if(y<=*s2.begin())s1.insert(y);
        else{

            auto s2_begin=s2.begin();
            ans-=*s2_begin;
            ans+=y;
            s1.insert(*s2_begin);
            //s2.erase(s2.lower_bound(*s2_begin));
            s2.erase(s2_begin);
            s2.insert(y);
        }
    }
    p[x]=y;
    //cout<<ans<<endl;
    printf("%lld\n",ans);
   }
}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}