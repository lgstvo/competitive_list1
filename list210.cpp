#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

int n;
int test;
int dp[10010][15];
vector<int> gifts;

bool solve(int p, int dif){
	if(dif < 0 || dif > 10) return 0;
	if(p==n) return 1;

	int& solution = dp[p][dif];
	if(solution != -1) return solution;

	solution = solve(p+1, dif-gifts[p]) | solve(p+1, dif+gifts[p]);
	return solution;
}

int main(){ _
    cin >> test;
	while(test--){
		cin >> n;
		gifts.resize(n);
		for(auto &i: gifts) cin >> i;
		
        for(int i=0;i <=n; i++)
            for(int j=0; j<=10; j++)
			    dp[i][j] = -1;
		
        if(solve(0, 5)) cout << "Feliz Natal!" << endl;
		else cout << "Ho Ho Ho!" << endl;
	
	}
	exit(0);
}