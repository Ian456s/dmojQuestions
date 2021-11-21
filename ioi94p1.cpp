#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f first
#define s second

const int INF = 0x3f3f3f3f;
const int MAX = 100 + 5;

int dp[MAX][MAX];
int arr[MAX][MAX];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n;i++){
    	for(int j = 1; j <= i; j++){
    		cin >> arr[i][j];
    	}
    }
    dp[1][1] = arr[1][1];
    for(int i = 2; i <= n; i++){
    	for(int j = 1; j <= i; j++){
    		dp[i][j] = arr[i][j] + max(dp[i-1][j],dp[i-1][j-1]); 
    	}
    }
    int greatest = INT_MIN;
    for(int i = 1; i <= n; i++){
    	if(dp[n][i] > greatest)greatest = dp[n][i];
    }
    cout << greatest << "\n";
    return 0;
}