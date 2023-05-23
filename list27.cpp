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
typedef pair<int, int> spell;

int main() { _

    int n, p;

    while(cin >> n){
        cin >> p;

        int maxvalue = 0;
        int cost = 0;
        vector<spell> cb(n);
        for(auto& i : cb){
            cin >> i.second;
            cin >> i.first;
            maxvalue += (int)i.second;
            cost     += (int)i.first;
        }
        maxvalue-=p;
        cout << maxvalue <<endl;

        vector<int> damage(maxvalue+1);
        for(int i=0; i<n; i++)
            for(int j=maxvalue; j > 0; j--)
                if(cb[i].second<= j)
                    damage[j] = max(damage[j], damage[j-cb[i].second]+cb[i].first);


        if(damage[maxvalue] >= p)
            cout << cost - damage[maxvalue] << endl;
        else
            cout << -1 << endl;
    }
    

    return 0;
}