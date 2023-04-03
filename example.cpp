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

vector<int> v;

map<string,int> nomes;
//set

vector<vector <pair<int, int> > > adj;

//rio 0
//bh 1
//sp 2
//almenara 3

int main()
{	//_

	int n,m;

	cin >> n >> m;

	adj.resize(n);

	int nc = 0;
	for (int i=0; i<m; i++)
	{
		string c1, c2;
		int dist;
		cin >> c1 >> c2 >> dist;

		if (nomes.find(c1)==nomes.end())
		{
			nomes[c1] = nc;
			nc++;
		}
		if (nomes.find(c2)==nomes.end())
		{
			nomes[c2] = nc;
			nc++;
		}

		adj[nomes[c1]].pb(mp(nomes[c2],dist));
		adj[nomes[c2]].pb(mp(nomes[c1],dist));
	}

	for (auto it: nomes)
	{
		cout << it.first << " " << it.second << endl;
	}
	//for (map<string,int>::iterator )


/*
	int n = 200000;
	//cin >> n;
	//string s(n,'0');

	string s;

	for (int i=0; i<n; i++)
	{
		s += '0';
	}


		//cout << s << endl;
	int n, m, d,a;

	while (scanf("%d%*[a-z/ ]%d%*[^0-9]%d",&d,&m,&a)==3)
	//while (cin >> n >> m)
	{
		printf("%d/% 4d/% 4d\n",a,m,d);
		//cout << a << '/' << m << '/' << d << endl;
	}



//	assert(n <= 1000);
// strtok ou buffer de string

	REP(i, 7)
		v.push_back(n);	

	cout << v.size() << endl;
*/
	return 0;
}




