//ABC_312_E
//set

#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r)for(int i=(l);i<(r);i++)

int a[110][110][110];
int main(){
	int n;
	cin >> n;
	rep(i,0,n){
		int x1,y1,z1,x2,y2,z2;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		rep(x,x1,x2)rep(y,y1,y2)rep(z,z1,z2)a[x][y][z]=i+1;
	}
	
	vector<set<int>>ans(n+1);
	auto add=[&](int i,int j){
		ans[i].insert(j);
		ans[j].insert(i);
	};
	
	rep(x,0,100)rep(y,0,100)rep(z,0,100)if(a[x][y][z]){
		if(a[x+1][y][z]&&a[x+1][y][z]!=a[x][y][z])add(a[x][y][z],a[x+1][y][z]);
		if(a[x][y+1][z]&&a[x][y+1][z]!=a[x][y][z])add(a[x][y][z],a[x][y+1][z]);
		if(a[x][y][z+1]&&a[x][y][z+1]!=a[x][y][z])add(a[x][y][z],a[x][y][z+1]);
	}
	
	rep(i,1,n+1)cout << ans[i].size() << endl;
}

