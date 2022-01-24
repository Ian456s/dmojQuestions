#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f first
#define s second
#define FILL memset(a, b, sizeof(a))
const int INF = 0x3f3f3f3f;
const int MAX = 400 + 5;
int psa[MAX];
bool dp[MAX][MAX]; //dp[i][j] is whether or not a range from indices i to j is combinable
int sum(int l, int r){
	return psa[r] - psa[l-1];
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++){
    	cin >> psa[i]; 
    	ans = max(ans, psa[i]);
    	psa[i] += psa[i-1];
    	dp[i][i] = true;
    }
    for(int size = 1; size < n; size++){
    	for(int l = 1; l + size <= n; l++){
    		int r = l + size;
    		for(int p = l, q = r; p < q; ){
    			int sumL = sum(l,p), sumR = sum(q,r);
    			if(dp[l][p] and dp[q][r] and p + 1 == q and sumL == sumR) {//both sides are combinable, they're adjacent, and the sums are equal
    				dp[l][r] = true; //whole range is combinable
    			}
    			else if (dp[l][p] and dp[q][r] and dp[p+1][q-1] and sumL == sumR) {
    				dp[l][r] = true;
    			}
    			if(dp[l][r])ans = max(ans, sum(l,r));
    			if(sumL < sumR)p++;
    			else
    				q--;
    		}
    	}
    }
    cout << ans << "\n";
    return 0;
}