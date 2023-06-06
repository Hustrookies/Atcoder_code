//ABC 298 C
//multiset set
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=2e5+5;
const long long  INF=0x3f3f3f3f3f3f3f3fLL;

void solve(){

  int n,q;
  cin>>n>>q;
  multiset<int> muls[N+1];
  set<int> s[N+1];
  while(q--){

	int op;
	cin>>op;
	if(op==1){

		int i,j;
		cin>>i>>j;
		muls[j].insert(i);
		s[i].insert(j);
	}else if(op==2){

		int num;
		cin>>num;
		if(!muls[num].empty())
		for(auto it=muls[num].begin();it!=muls[num].end();it++){

			if(it!=--(muls[num].end()))cout<<*it<<' ';
			else cout<<*it;
		}
		cout<<endl;
	}else{

		int num;
		cin>>num;
		if(!s[num].empty())
		for(auto it=s[num].begin();it!=s[num].end();it++){

			if(it!=--(s[num].end()))cout<<*it<<' ';
			else cout<<*it;
		}
		cout<<endl;
	}

  }
 	
 }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1;
  //cin>>t;
  while(t--)solve();
  
}