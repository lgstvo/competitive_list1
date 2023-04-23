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

void defineStructure(bool condition1, bool condition2, bool condition3){
    if(!condition1 and !condition2 and !condition3){
        cout << "impossible" << endl;
    }else if(condition1 and condition2){
        cout << "not sure" << endl;
    }else if (condition2 and condition3){
        cout << "not sure" << endl;
    }else if(condition1 and condition3){
        cout << "not sure" << endl;
    }else if(condition1){
        cout << "priority queue" << endl;
    }else if(condition2){
        cout << "stack" << endl;
    }else if (condition3){
        cout << "queue" << endl;
    }
} 
 
 
int main() {
    int n;
    while(cin >> n){
        priority_queue<int> priorCheck;
        stack<int> stackCheck;
        queue<int> queueCheck;
        bool isPrior = true, isQueue = true, isStack = true;
        for (int y = 0; y < n; y++){
            int action, number;
            cin >> action >> number;
            if(action == 1){
                priorCheck.push(number);
                stackCheck.push(number);
                queueCheck.push(number);
            }else{
                if(priorCheck.top() != number){
                    isPrior = false;
                }else{
                    priorCheck.pop();
                }
                if(stackCheck.top() != number){
                    isStack = false;
                }else{
                    stackCheck.pop();
                }
                if(queueCheck.front() != number){
                    isQueue = false;
                }else{
                    queueCheck.pop();
                }
            }
        }
        defineStructure(isPrior, isStack, isQueue);         
    }

   return 0;

}
