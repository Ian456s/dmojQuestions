#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f first
#define s second
#define pb push_back
#define FILL memset(a, b, sizeof(a))
const int INF = 0x3f3f3f3f;
const int MAX = 1e5 + 5;
string s;
long dp[4];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'l') dp[0]++;
		if(s[i] == 'o') dp[1] += dp[0];
		if(s[i] == 'v') dp[2] += dp[1];
		if(s[i] == 'e') dp[3] += dp[2];
	}    
	cout << dp[3] << "\n";
    return 0;
}

