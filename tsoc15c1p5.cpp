#include<bits/stdc++.h>
using namespace std;
const int MAX = 105;

int dist[MAX], distAnts[MAX];
bool vis[MAX];
vector<int> adj[MAX];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, w; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin >> w;
    queue<int> q;
    fill(vis, vis+n+1, false);
    fill(distAnts, distAnts+n+1, -1);
    while(w--) {
        int x; cin >> x;
        vis[x] = 1;
        distAnts[x] = 0;
        q.push(x);
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto &x : adj[cur]) {
            if(!vis[x]) {
                vis[x] = true;
                distAnts[x] = distAnts[cur] + 4;
                q.push(x);
            }
        }
    }
    fill(vis, vis+n+1, false);
    fill(dist, dist+n+1, -1);
    dist[1] = 0;
    vis[1] = true;
    q.push(1);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto &x : adj[cur]) {
            if(!vis[x] and distAnts[x] > dist[cur] + 1) {
                vis[x] = true;
                dist[x] = dist[cur] + 1;
                q.push(x);
            }
        }
    }
    if(vis[n]) {
        cout << dist[n] << "\n";
    } else {
        cout << "sacrifice bobhob314" << "\n";
    }
    return 0;
}