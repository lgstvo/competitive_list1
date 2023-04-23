#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define pb push_back
#define mp make_pair
#define REP(i,n) for(int i=0; i<n;i++)
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

#define MAXN 1000000
#define MAXM (MAXN+MAXN)

using namespace std;

int calculate_planks(int h, vector<int>& x, int remain){
    int start = 0;
    int end = x.size() -1;
    int planks = 0;
    int used = 0;
    int planksh;

    while(planks!=remain){
        if(start >= end) return 0; //impossivel

        if(x[end] < h){
            planksh = x[start] + x[end];
            while(planksh < h) start++;
            end--;
            planks++;
            used += 2;
            start++;
        }
        else if (x[end] == h){
            end--;
            planks++;
            used++;
        }
        else end--;
    }
    return used;
}

int main(){	_

    long int m,n; // dimensoes
    int l; // largura cm
    int k; // numero de tabuas
    int op1, op2;

    while(1){
        cin >> m >> n;
        if(m == 0 && n == 0) break;
        cin >> l;
        cin >> k;   

        vector<int> x(k); // comprimento das tabuas
        for(int i = 0 ; i < k; i++) cin >> x[i];
        sort(x.begin(), x.end()); // placas menores primeiro

        op1 = 0;
        op2 = 0;
        if((n*100) % l == 0) op1 = calculate_planks(m, x, n*100/l);
        if((m*100) % l == 0) op2 = calculate_planks(n, x, m*100/l);
        if(op1 == 0 && op2 == 0) cout << "impossivel" << endl;
        else{
            if((op1!=0) && (op2!=0))
                cout << min(op1,op2) << endl;
            else
                cout << max(op1,op2) << endl;
        }        
    }


	return 0;
}




