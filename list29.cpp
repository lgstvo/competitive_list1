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

typedef pair<int, int> roomstats;

int n, k, v;
double store[1010][110];
vector<roomstats> floors;

double solve(int a, int b){
	if(a==n) return 0.0;

	double& solution = store[a][b];
	if(solution > -1.0) return solution;
	
	solution = (double)floors[a].first/v + solve(a+1, b);
	
    if(b>0){
        solution = min(solution, \
            floors[a].first/double(v+floors[a].second) \
                + solve(a+1, b-1));
    }
	return solution;
}

int main(){ _
	while(cin >> n >> k >> v){
		floors.resize(n);
		
        for(auto& i:floors)
            cin >> i.first >> i.second;
		
        for(int i=0;i <=n; i++)
            for(int j=0; j<=k; j++)
                store[i][j] = -2;

		cout << setprecision(4) << fixed << solve(0, k) << endl;
	}
	return 0;
}