#include <bits/stdc++.h>

using namespace std;

long long cost[200001], parent[200001], child[200001], numc[200001];
bool vis[200001];
long long res;

void dfs(int x){
	vis[x] = true;
	if(cost[x] <= child[x]){
		res += cost[x];
		numc[parent[x]]--;
		if(!vis[parent[x]] and numc[parent[x]] == 0) dfs(parent[x]);
	}
	else{
		cost[x] - child[x];
		res += child[x];
		numc[parent[x]]--;
		child[parent[x]] += cost[x];
		if(!vis[parent[x]] and numc[parent[x]] == 0) dfs(parent[x]);
	}
}

void search(int x){
	int cur = parent[parent[x]];
	int pv = parent[x];
	int mxi = parent[x];
	int mxpv = x;
	long long mxv = cost[mxi] - child[mxi];

	while(cur != parent[x]){
		if(cost[cur] - child[cur] > mxv){
			mxv = cost[cur] - child[cur];
			mxi = cur;
			mxpv = pv;
		}
		pv = cur;
		cur = parent[cur];
	}
	vis[mxpv] = true;
  res += cost[mxpv];
	if(!vis[mxi]) dfs(mxi);
	
}

int main(){
	int n; cin >> n;


	memset(child,0,sizeof child);
	memset(numc, 0, sizeof numc);
	memset(vis,false, sizeof vis);
	for(int i = 1; i <= n; i++){
		cin >> parent[i];
		numc[parent[i]]++;
	}
	for(int i = 1; i <= n; i++){
		cin >> cost[i];
	}

	res = 0;

	for(int i = 1; i <= n; i++){
		if(parent[i] == i) vis[i] = true;
	}

	for(int i = 1; i <= n; i++){
		if(numc[i] == 0 and !vis[i]){
			dfs(i);
		}
	}

	for(int i = 1; i <= n; i++){
		if(numc[i] == 1 and !vis[i]){
			search(i);
		}
	}

	cout << res << "\n";

}
