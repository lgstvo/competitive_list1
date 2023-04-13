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


int main()
{	_

    double input;

    int notas[] = {100, 50, 20, 10, 5, 2};
    int cents[] = {100, 50, 25, 10, 5, 1};
    cin >> input;

    double reais;
    double moedas = modf(input, &reais) * 100;

    int r = (int)(reais);
    int m = (int)(moedas);

    int result;
    cout << "NOTAS:" << endl;
    for(int i =0; i<6; i++){
        result = r/notas[i];
        r -= notas[i]*result;
        cout << result <<  " nota(s) de R$ " << notas[i] << ".00" << endl;
    }

    m += r * 100;
    cout << "MOEDAS:" << endl;
    for(int i = 0; i<6; i++){
        result = m/cents[i];
        m -= cents[i]*result;
        cout << result <<  " moeda(s) de R$ " << fixed << setprecision(2) << (cents[i])/100.0 << endl;
    }
    return 0;
}
