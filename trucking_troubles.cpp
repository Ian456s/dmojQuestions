#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int n, m, d;
vector<pair<int, int>> adj[MAX];
int dist[MAX];
bool dest[MAX];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> d;
    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for(int i = 0; i < d; i++) {
        int u; cin >> u;
        dest[u] = true;
    }
    priority_queue<pair<int, int>> q;
    dist[1] = INF;
    q.push({INF, 1});
    while(!q.empty()) {
        auto cur = q.top(); q.pop();
        int u = cur.second;
        int d = cur.first;
        if(d < dist[u]) {
            continue;
        }
        for(auto &e : adj[u]) {
            int v = e.first;
            int w = e.second;
            if(w > dist[v]) {
                dist[v] = w;
                q.push({w, v});
            }
        }
    }
    int ans = INF;
    for(int i = 1; i <= n; i++) {
        if(dest[i]) {
            ans = min(ans, dist[i]);
        }
    }
    cout << ans << "\n";
    return 0;
}