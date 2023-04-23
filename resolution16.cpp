#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define pb push_back
#define mp make_pair
#define REP(i,n) for(int i=0; i<n;i++)
//#define max(i,j) (i<j?j:i)


#define MAXN 1010
#define MAXM (MAXN+MAXN)

const int MAXC=1000;

//int v[MAXN];

using namespace std;

int main(){	
    
    
    string joia;
    set<string> joias;

    while (getline(cin, joia)) {
        joias.insert(joia);
    }

    cout << joias.size() << endl;

    return 0;
    
}


