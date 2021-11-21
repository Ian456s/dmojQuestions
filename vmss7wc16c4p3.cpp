#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f first
#define s second
#define FILL memset(a, b, sizeof(a))
const int INF = 0x3f3f3f3f;
const int MAX = 1e3 + 5;

int dp[MAX][MAX];
string x, y;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int del, ins, rep;
	cin >> del >> ins >> rep; 
	cin >> x >> y;   
    for(int i = 0; i <= x.size(); i++){
    	for(int j = 0; j <= y.size(); j++){
    		if(i == 0 && j == 0)dp[i][j] = 0;
    		else if(i == 0)dp[i][j] = j*ins;
    		else if(j == 0) dp[i][j] = i*del;
    		else if(x[i-1] == y[j-1])dp[i][j] = dp[i-1][j-1];
    		else{
    			dp[i][j] = min({(dp[i-1][j]+del), (dp[i][j-1]+ins), (dp[i-1][j-1]+rep)});
    		}
    	}
    }
    cout << dp[x.size()][y.size()] << "\n";
    return 0;
}