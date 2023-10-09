#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f first
#define s second
#define FILL memset(a, b, sizeof(a))
const int INF = 0x3f3f3f;
const int MAX = 1e6 + 5;


int seq1[MAX], seq2[MAX], pos[MAX], b[MAX], dp[MAX];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dp, 0x3f, sizeof(dp));
    memset(b, -1, sizeof(b));
    memset(pos, -1, sizeof(pos));
    dp[0] = -INF;
    int m, n;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> seq1[i];
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> seq2[i];
    }
    for(int i = 0; i < m; i++){
        pos[seq1[i]] = i;
    }
    for(int i = 0; i < n; i++){
        b[i] = pos[seq2[i]];
    }

    int k = 0;
    for(int i = 0; i < n; i++){
        if(b[i] == -1)continue;
        int it = lower_bound(dp, dp + k, b[i]) - dp;
        dp[it] = b[i];
        if(it == k){
            k++;
        }
    }
    cout << k << "\n"; 
    return 0;
}