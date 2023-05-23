#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

using namespace std;

// ??
int dp[2][1002][1002]; 

vector<int> inputs; 
int solve(int i, int j, int count){
    if(i > j) return 0; 
    int p = count%2; 
    if(dp[p][i][j] != -1) return dp[p][i][j]; 
    int a = solve(i+1, j, count+1); 
    int b = solve(i, j-1, count+1);
    
    if(count%2 == 0){
        if(inputs[i]%2 == 0) a++; 
        if(inputs[j]%2 == 0) b++; 

        return dp[p][i][j] = max(a,b); 
    }
    else return dp[p][i][j] = min(a,b); 

}
int main(){_
    int n;
    while (cin >> n){
        if(!n) break;
        inputs.resize(2*n); 
        memset(dp, -1, sizeof(dp)); 
        for (int i = 0; i < 2 * n; i++) cin >> inputs[i];
 
        cout << solve(0, 2*n-1, 0) << endl; 
    }
    return 0;
}