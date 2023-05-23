#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

const int MAXC=330;

using namespace std;
typedef pair<int,int> pos;
char seats[MAXC][MAXC];
int avS[MAXC][MAXC];

int seatsBetween(pos a, pos b){
    a.first++;
	a.second++;
	return avS[a.first][a.second] - avS[a.first][b.second] - avS[b.first][a.second]+ avS[b.first][b.second];
}

int main() { _
    while(true){
		int r, c, k;
		cin >> r >> c >> k;
		int group = r*c;
		if(!r) break;
		for(int i=0;i <r; i++) for(int j=0; j<c; j++) cin >> seats[i][j];
		
		
		
		for(int i=1; i<=r; i++) for(int j=1; j<=c; j++)
			avS[i][j] = avS[i][j-1] + avS[i-1][j] - avS[i-1][j-1] + (seats[i-1][j-1]=='.');

		for(int i=0;i <r; i++) for(int j=0; j<c; j++){
			for(int left=0; left<=j; left++){
				if(seatsBetween({i, j}, {0, left}) < k) break;
				
                int top = 0, bot = i;
				while(top<bot){
					int mid = (top+bot+1)/2;
					if(seatsBetween({i, j}, {mid, left}) >= k) top = mid;
					else bot = mid-1;
				}

				group = min(group, (i-top+1)*(j-left+1));
			}
		}
	
		cout << group << endl;
	}
    return 0;
}