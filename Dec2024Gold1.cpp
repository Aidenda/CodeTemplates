#include <bits/stdc++.h>

using namespace std;

vector<int> cows[100001];
long long cur[100001];
int a[100001];
int n;
long long change[100001];

void bigAdd(int id){
  int nxt[n+1];
  int curLast = 1000000;
  for(int i = n; i >= 1; i--){
    if(a[i] == id){
      curLast = i;
    }
      nxt[i] = curLast;
  }
  for(int i = 1; i <= n; i++){
    int pt = cows[id][0];
    while(pt <= n){
		  cur[i]++;
		  if(pt + i+1 > n) break;
		    pt = nxt[pt+i+1];
	    }
    }
    
  
}

int check(int id, int x ){
	int ct =  0;
	int l = 0; int r = 0;
	while(l < cows[id].size()){
		while(r < cows[id].size() and cows[id][r] - cows[id][l] <= x) r++;
		ct++;
		l = r;
	}
	return ct;
}

void smallAdd(int id){

	for(int i = 1; i <= cows[id].size(); i++){
		int l = 0; int r = n+1;

		while(l < r-1){
			int mid = (l+r)/2;
			if(check(id,mid) < i) r = mid;
			else l = mid;
		}
		change[1]++;
		if(r <= n) change[r]--;
	}

}

int main(){
  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> a[i];
    cows[a[i]].push_back(i);
  }
  for(int i = 1; i <= n; i++){
	cur[i] = 0;
	change[i] = 0;
  }

  int sq = (int)sqrt(n);
  
  for(int i = 1; i <= n; i++){
    if(cows[i].size() >= sq){
      bigAdd(i);
    }
	else{
		smallAdd(i);
	}
  }

  long long curCh = 0;

  for(int i = 1; i <= n; i++){
	curCh += change[i];
	cout << curCh + cur[i] << "\n";
  }
}
