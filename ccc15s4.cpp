#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX = 1e5 + 5;
struct Edge {
	int v, t, h;
	friend bool operator<(const Edge &a, const Edge &b){
		return a.t > b.t;
	}
};
int k, n, m, s, t;
int dist[MAX][205];
vector<Edge> adj[MAX];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> k >> n >> m;
    for(int i = 0; i < m; i++) {
    	int a, b, t, h; cin >> a >> b >> t >> h;
    	adj[a].push_back((Edge){b,t,h});
    	adj[b].push_back((Edge){a,t,h});
    }
    cin >> s >> t;
    for(int i = 0; i < MAX; i++){
    	fill(dist[i], dist[i]+205, INT_MAX);
    }
    priority_queue<Edge> q;
    q.push((Edge){s,0,0});
    dist[s][0] = 0;
    while(!q.empty()) {
    	auto cur = q.top(); q.pop();
    	int u = cur.v, h0 = cur.h;
    	for(auto &e : adj[u]) {
    		int v = e.v;
    		int t = e.t;
    		int h = e.h;
    		int d = dist[u][h0] + t;
    		if(d < dist[v][h+h0] and h + h0 < k){
    			dist[v][h+h0] = d;
    			q.push((Edge){v,d,h+h0});
    		}
    	}
    }
    int ans = INT_MAX;
    for(int i = 0; i < k; i++){
    	ans = min(ans, dist[t][i]);
    }
    cout << (ans == INT_MAX ? -1 : ans) << "\n";
    return 0;
}