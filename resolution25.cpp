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

int binary_search(int aux, int x, int mi, int n, int c, vector<int> s, int t){
    int resultadoBusca = 0;
    while(aux != 0){
        int contador = 0, soma = 0;
        bool condition = false;
        for (int z = 0; z < n; z++){
            if(ceil(s[z]*1.0/t) > x || contador == c){
                contador = c + 1;
                break;
            }
            if(ceil((double)(soma+s[z])/(t*1.0)) <= x){
                soma += s[z];
            }
            else{
                soma = s[z];
                contador++;
            }

        }
        contador++;
        aux = (x-mi)/2;
        if (contador <= c){
            resultadoBusca = x;
            condition = true;
            x -= aux;
        } else if (condition){
            mi = x;
            x += aux;
        } else {
            aux = 1;
            mi = x;
            x = x*2;
        }


    }
    return resultadoBusca;

}


int main(){	_
    int quantPipoca, quantPartEquipes, quantPipocaSec, m, resultadoBusca = 0, x;
    vector<int> sacosPipoca;
    cin >> quantPipoca >> quantPartEquipes >> quantPipocaSec;
    sacosPipoca.resize(quantPipoca);
    for (int i = 0; i < quantPipoca; i++){
        cin >> sacosPipoca[i];
        m = max(m,sacosPipoca[i]);
    }
    x = pow(2, int(ceil(log2(m/quantPipocaSec))));
    resultadoBusca = binary_search(1, x, x/2, quantPipoca, quantPartEquipes, sacosPipoca, quantPipocaSec);
    cout << resultadoBusca << endl;
	return 0;
}


