#include <bits/stdc++.h>

using namespace std;


long long MOD = 1e9 + 7;

int main(){
	int n,m,q; cin >> n >> m >> q;



	bool bin[n];

	int chs[n+1];
	memset(chs, 0, sizeof chs);

	for(int i = 0; i < m; i++){
		int a,b; cin >> a >> b;
		a--;b--;
		chs[a]++;
		chs[b+1]--;
	}

	int cur = 0;

	for(int i = 0; i < n; i++){
		cur += chs[i];
		bin[i] = (cur % 2 == 1);
	}


	int pre[n+1];
	pre[0] = 0;

	for(int i = 1; i <= n; i++){
		pre[i] = pre[i-1] + bin[i-1];
	}

	while(q--){
		int l,r,k; cin >> l >> r >> k;
		l--; r--;
		int lo = l; int hi = r;

	  while(lo < hi){
			int mid = (lo+hi)/2;

			if(pre[mid+1] - pre[l] + r - mid > k) lo = mid+1;
			else hi = mid;
		}

		long long sum = 0;
		long long curm = 1;

		for(int i = r; i > lo; i--){
			sum = (sum + bin[i] * curm) % MOD;
			curm = (curm *2) % MOD;
		}
		for(int i = 0; i < min(pre[lo+1] - pre[l],k); i++){
		    sum = (sum + curm) % MOD;
			curm = (curm *2) % MOD;
		}

		cout << sum << "\n";



		
	}
}
