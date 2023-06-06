#include<bits/stdc++.h>
using namespace std;
#define ll long long 
string G[110];
const int N=1e6;
bool is_even[N+10];
vector<ll>prime;
vector<ll>prime2;
void solve(){

    
	ll n;
	cin>>n;
	ll sqrt_n=pow(n,0.5);
	int c=upper_bound(prime.begin(),prime.end(),sqrt_n)-prime.begin()-1;
	ll ans=0;
	if(prime2[c]==n)c--;
	//5<=c<sqrt_n
	for(ll i=c;i>=0&&prime[i]>=5;i--){

		ll tmp=n/(prime2[i]);
		int b=upper_bound(prime.begin(),prime.end(),min(tmp,prime[i]))-prime.begin()-1;
		//b<c
		if(b==i)b--;
		for(ll j=b;j>=0&&prime[j]>=3;j--){

			ll tmp2=tmp/prime[j];
			int a=upper_bound(prime2.begin(),prime2.end(),min(tmp2,prime2[j]))-prime2.begin()-1;
			if(a==j)a--;
			if(a>=0)ans+=a+1;
		}
	}
	cout<<ans<<endl;


}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
	for(int i=2;i<N;i++){

		if(!is_even[i]){

			int tmp=2;
			while(tmp*i<=N){

				is_even[tmp*i]=1;
				tmp++;
			}
		}
	}
	for(ll i=2;i<=N;i++){

		if(!is_even[i]){

			prime.push_back(i);
			prime2.push_back(i*i);
		}
	}
	//for(int i=0;i<20;i++)cout<<prime[i]<<' '<<prime2[i]<<endl;
    int t=1;
    while(t--)solve();
}