#include <bits/stdc++.h>

using namespace std;


long long MOD = 1e9 + 7;




int main(){
	int n,m,q; cin >> n >> m >> q;
	
	
    bool modbin[32];
	int cpy = MOD - 2;
	for(int i = 0; i < 32; i++){
	    modbin[i] = cpy % 2;
	    cpy/= 2; 
	}
	
	long long pows[32];
	pows[0] = 2;
	for(int i = 1; i <= 32; i++){
	    pows[i] = (pows[i-1] * pows[i-1]) % MOD;
	}
	long long inv = 1;
	
	for(int i = 0; i < 32; i++){
	    if(modbin[i]) inv = (inv * pows[i]) % MOD;
	}
	long long invlist[n+1];
	invlist[0] = 1;
	invlist[1] = inv;
	for(int i = 2; i <= n; i++){
	    invlist[i] = (inv * invlist[i-1]) % MOD;
	}
	
	
	
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
	
	long long power[n+1];
	power[0] = 1;
	for(int i = 1; i <= n; i++){
	    power[i] = (power[i-1] * 2) % MOD;
	}
	
	long long prefix[n+1];
	
	prefix[n] = 0;
	
	for(int i = n-1; i >= 0; i--){
	    prefix[i] = (prefix[i+1] + power[n-i-1] * bin[i]) % MOD;
	}
	for(int i = 0; i < n; i++) cout << prefix[i] << " ";
	
	cout << "\n";
	
	while(q--){
		int l,r,k; cin >> l >> r >> k;
		l--; r--;
		int lo = l; int hi = r;

	    while(lo < hi){
			int mid = (lo+hi)/2;

			if(pre[mid+1] - pre[l] + r - mid >= k) lo = mid+1;
			else hi = mid;
		}

		long long sum = 0;
		long long curm = 1;
		
		cout << lo << " ";
		sum += ((prefix[lo] - prefix[r+1])* invlist[n-r-1]) % MOD;
		
		if(lo != l) sum = (sum + power[k] - power[r-lo]) % MOD;

		cout << sum << "\n";



		
	}
}
