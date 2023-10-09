#include <bits/stdc++.h>
using namespace std;
const int MAX = 10e4+5;
int n, m, b, q;
int dist[MAX];
vector<pair<int,int>> adj[MAX];
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int u, v, w;
	cin >> n >> m >> b >> q;

	for(int i  = 0; i < m; i++){
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	fill(dist, dist+MAX, INT_MAX);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
	pq.push({0, b});
	dist[b] = 0;
	while(!pq.empty()) { 
		int cur = pq.top().second; pq.pop();
		for(auto &e: adj[cur]) { 
			int v = e.first; 
			int w = e.second;
			int d = dist[cur] + w;
			if(d < dist[v]) { 
				dist[v] = d;
				pq.push({d, v});
			}
		}
	}
	for(int i = 1; i <= q; i++){
		int query; cin >> query;
		cout << ((dist[query]!=INT_MAX)?dist[query]:-1) << "\n";
	}
	return 0;

}