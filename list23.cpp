#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int store[110][110][110];
int cards[110][3];
int n;

bool solve(int a, int b, int c, int x) {
    if (x % 3 || a > n || b > n || c > n) return 0;
    if (a == n && b == n && c == n) return 1;

    int& solution = store[a][b][c];
    if (solution != -1) return solution;

    solution = false;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++) {
                if (!i && !j && !k) continue;
                int sumcards = 0;
                int ia = a, ib = b, ic = c;
                if (i){
                    sumcards += cards[a][0];
                    ia++;
                }
                if (j){
                    sumcards += cards[b][1];
                    ib++;
                }
                if (k){
                    sumcards += cards[c][2];
                    ic++;
                }

                solution |= solve(ia, ib, ic, (x - sumcards));
            }
    return solution;
}

int main() {
    _
    while (true) {
        cin >> n;
        if (!n) break;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < 3; j++)
                cin >> cards[i][j];

        memset(store, -1, sizeof(store));

        cout << solve(0, 0, 0, 0) << endl;
    }
}