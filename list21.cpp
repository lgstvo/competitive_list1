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

typedef pair<int, int> cannonball;

int main() { _

    int test_cases, n, k, r;
    cin >> test_cases;

    while(test_cases--){
        cin >> n;
        vector<cannonball> cb(n);
        for(auto& i : cb){
            cin >> i.first;
            cin >> i.second;
        }       
        cin >> k;
        cin >> r;

        vector<int> damage(k+1);
        for(int i=0; i<n; i++){
            for(int j=k; j > 0; j--){
                if(cb[i].second<= j){
                    damage[j] = max(damage[j], damage[j-cb[i].second]+cb[i].first);
                }
            }
        }

        if(damage[k] >= r)
            cout << "Missao completada com sucesso" << endl;
        else
            cout << "Falha na missao" << endl;
    }
    
    return 0;
}