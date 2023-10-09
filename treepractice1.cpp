#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f first
#define s second
#define FILL memset(a, b, sizeof(a))
const int INF = 0x3f3f3f3f;
const int MAX = 5e5 + 5;
int N, dia, far, dist[MAX], pre[MAX];
vector<pair<int,int>> adj[MAX];

void dfs(int cur, int par, int d){
	pre[cur] = par; dist[cur] = d;
	if(d > dia) { 
		dia = d; far = cur;
	}
	for(auto &e : adj[cur]){
		if(e.f != par) dfs(e.f, cur, d + e.s);
	}
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++){
    	int u, v, w; cin >> u >> v >> w;
    	adj[u].push_back({v,w}); adj[v].push_back({u,w});
    }
    dfs(1, -1, 0); dia = 0; dfs(far, -1, 0);
    int rad = INT_MAX;
    for(int u = far; u != -1; u=pre[u]){
    	rad = min(rad, max(dist[u], dia-dist[u]));
    }
    cout << dia << "\n" << rad << "\n";

    return 0;
}

