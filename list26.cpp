#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define REP(i,n) for(int i=0; i<n;i++)

#define MAXN 30
#define MAXM (MAXN+MAXN)

const int MAXC=1000;

using namespace std;

int main() { _

    int n, at, h;
    cin >> n;
	vector<int> alturas(n);
	for(auto& i: alturas) cin >> i;

	at = 0;
	for(int i=0;i <n; i++){
		alturas[i] = min(at+1, alturas[i]);
		at = alturas[i];
	}

	at = 0;
	for(int i=n-1;i+1 >0; i--){
		alturas[i] = min(at+1, alturas[i]);
		at = alturas[i];
	}

	h = 0;
	for(auto a : alturas) h = max(h, a);
	cout << h << endl;
    return 0;
}