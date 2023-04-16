#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define REP(i,n) for(int i=0; i<n;i++)

#define MAXN 1010
#define MAXM (MAXN+MAXN)

const int MAXC=1000;

using namespace std;


void caminho(int v, vector<int>& visited, int (*adj)[30]){
    visited[v] = 1;
    for(int y = 0; y < v; y++){
        if(adj[v][y] == 1 && visited[y] == 0)
            caminho(y, visited, adj);
    }
}

int main()
{	_

    int n;
    int v, e;
    char a, b;
    int inta, intb;
    int comp;

    cin >> n;

    for(int i = 0; i < n; i++){
        vector<int> visited(30,0);
        
        cin >> v >> e;
        //vector<vector<int>> adj(30, vector<int>(30, 0));
        int adj[30][30] = {0};
        for(int j = 0; j < e; j++){
            cin >> a >> b;
            inta = a - 'a';
            intb = b - 'a';
            adj[inta][intb] = 1;
            adj[intb][inta] = 1;
        }
        comp = 0;
        cout << "Case " << i+1 << ":" << endl;

        for(int x = 0; x < v; x++){
            if(visited[x] == 0){
                comp++;
                caminho(x, visited, adj);
                for(int y = 0; y < v; y++){
                    if(visited[y] == 1){
                        cout << char(y+'a') << ",";
                        visited[y] = -1;
                    }
                }
            }
            cout << endl;
        }

        cout << comp << " connected components" << endl;
    }

    return 0;
}
