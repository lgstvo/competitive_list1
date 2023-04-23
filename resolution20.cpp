#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define pb push_back
#define mp make_pair
#define REP(i,n) for(int i=0; i<n;i++)

#define MAXN 1010
#define MAXM (MAXN+MAXN)

const int MAXC=1000;

using namespace std;

struct ilha{
    int numIlha;
    vector<pair<int, int>> conexoes;
};

vector<ilha> ilhas;

void dijkstra(int s, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist.assign(ilhas.size(), INF);
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int v = pq.top().second;
        int d_v = pq.top().first;
        pq.pop();
        if (d_v != dist[v])
            continue;
        for (auto edge : ilhas[v].conexoes) {
            int to = edge.first;
            int len = edge.second;
            if (dist[v] + len < dist[to]) {
                dist[to] = dist[v] + len;
                pq.push({dist[to], to});
            }
        }
    }
}

int main(){    _
    int n, m;
    cin >> n >> m;
    ilhas.resize(n);
    for (int i = 0; i < m; i++){
        int conexao1, conexao2, ping;
        cin >> conexao1 >> conexao2 >> ping;
        ilhas[conexao1-1].conexoes.pb(mp(conexao2-1, ping)); 
        ilhas[conexao2-1].conexoes.pb(mp(conexao1-1, ping)); 
    }
    int s;
    cin >> s;
    s--;

    vector<int> dist;
    dijkstra(s, dist);

    int maiorPing = -1, menorPing = INF;
    for (int i = 0; i < ilhas.size(); i++) {
        if (i != s) {
            maiorPing = max(maiorPing, dist[i]);
            menorPing = min(menorPing, dist[i]);
        }
    }
    cout << maiorPing - menorPing << endl;
    return 0;
}