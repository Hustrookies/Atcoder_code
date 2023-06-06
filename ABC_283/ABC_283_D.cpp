//ABC 283 D
//use a symbol stack and a char stack to simulate
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=1e9+5;

bool vis[26];
bool pos[300010];
void solve(){

	string a;
	cin>>a;
	int len=a.size();
	memset(vis,0,sizeof(vis));
	stack<int>st;
	stack<pair<int,int> >st_ch;
	for(int i=0;i<len;i++){
		
		if(a[i]=='('){
			
			st.push(i);
			pos[i]=1;
			continue;
		}
		if(a[i]==')'){
				
			int begin=st.top();
			st.pop();
			while(!st_ch.empty()){
				
				if(st_ch.top().second!=begin)break;
				vis[a[st_ch.top().first]-'a']=0;
				st_ch.pop();
			}
		
			continue;
		}
		if(vis[a[i]-'a']){
			
			cout<<"No"<<endl;
			return;
		}
		if(!st.empty())st_ch.push(make_pair(i,st.top()));
		vis[a[i]-'a']=1;
	}
	cout<<"Yes"<<endl;
	
 }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1;
  //cin>>t;
  while(t--)solve();
  
}
