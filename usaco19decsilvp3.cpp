#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f first
#define s second
#define pb push_back
#define FILL memset(a, b, sizeof(a))
const int INF = 0x3f3f3f3f;
const int MAX = 1e5 + 5;

int N, M, p[MAX]; string s; char c;

int fd(int d){
	if(d != p[d]) p[d] = fd(p[d]);
	return p[d];
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin >> N >> M >> s;
	for(int i = 1; i <= N; i++) p[i] = i;
	for(int i = 1, u, v; i < N; i++){
		cin >> u >> v;
		if(s[u-1] == s[v-1]) p[fd(u)] = fd(v);
	}
	for(int i = 1, a, b; i <= M; i++){
		cin >> a >> b >> c;
		if(s[a-1] == c || s[b-1] == c || fd(a) != fd(b)) cout << 1;
		else cout << 0;
	}
	cout << "\n";
    return 0;
}

