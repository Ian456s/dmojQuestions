#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f first
#define s second
#define pb push_back
#define FILL memset(a, b, sizeof(a))
const int INF = 0x3f3f3f3f;
const int MAX = 1e5 + 5;
int dp[MAX]; //max number of friends that can share the chocolate with length i = dp[i]
int N;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dp, -0x3f, sizeof dp);
    cin >> N;
    dp[0] = 0;
    for(int k = 0, x; k < 3; k++){
        cin >> x;
        for(int i = x; i <= N; i++){
            dp[i] = max(dp[i], dp[i-x] + 1);
        }
    }
    cout << dp[N] << "\n";
    
    return 0;
}