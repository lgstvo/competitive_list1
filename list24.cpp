#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

const int MAX = 200;
vector<int> machine;
int n, k;
long long store[MAX][MAX][MAX];

long long eldorado(int p, int at, int tam){
	if(tam==0) return 1;
	if(p==n-1){
		if(tam!=1) return 0;
		if(at>=machine[p]) return 0;
		return 1;
	}

	long long &solution = store[p][at][tam];
	if(solution!=-1) return solution;

	solution = eldorado(p+1, at, tam);
	if(machine[p]>at) solution += eldorado(p+1,machine[p], tam-1);
	
	return solution;
}

int main(){ _
	while(true){
		cin >> n >> k;
		if(!n) break;
		
		machine.resize(n);
		for(auto& a:machine) cin >> a;
		
		vector<int> aux = machine;
		sort(aux.begin(), aux.end());
		map<int, int> mp;
		int ptr = 1;

		for(auto a : aux)
			if(!mp.count(a)) mp[a]=ptr++;
		
		for(auto& a:machine) a = mp[a];
		
		// init store
		for(int i=0;i <=n; i++)
			for(int j=0; j<=n; j++)
				for(int l=0; l<=n; l++)
					store[i][j][l]=-1;
	
		cout << eldorado(0, 0, k) << endl;
	}

	return 0;
}