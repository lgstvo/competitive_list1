#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define pb push_back
#define mp make_pair
#define REP(i,n) for(int i=0; i<n;i++)
//#define max(i,j) (i<j?j:i)

//int v[MAXN];

using namespace std;
bool primo(long long n){
    if(n == 1) return false;
    bool primo = true;
    for(long long i = 2; i <= sqrt(n); i++){
        if(n % (i*i) == 0) return false;
        if(n % i == 0) primo = false;
    }
    return !primo;
}

int main(){
    long long n, i;
    int count = 0;
    cin >> n;
    for(i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            count += primo(i);
            if(i != n/i) count += primo(n/i);
        }
    }
    cout << count << endl;
}