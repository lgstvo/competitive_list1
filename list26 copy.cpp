#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, at, h; cin >> n;
	vector<int> alturas(n); for(auto& i: alturas) cin >> i;

	at = 0;
	for(int i=0;i <n; i++) alturas[i] = min(at+1, alturas[i]), at = alturas[i];

	at = 0;
	for(int i=n-1;i+1 >0; i--) alturas[i] = min(at+1, alturas[i]), at = alturas[i];

	h = 0;
	for(auto a : alturas) h = max(h, a);
	cout << h << endl;
    return 0;
}