#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f first
#define s second
#define pb push_back
int N, M, A, B, last, start, dest; vector<pair<int,int>> ops;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M >> A >> B;
    for(int i = 0, u, v; i < M; i++){
    	cin >> u;
    	if(u != -1) {
    		cin >> v; 
    		ops.pb({u,v});
    	}
    	else{
    		ops.pb({-1,-1});
    		last = i;
    	}
    }
    start = A; dest = B;
    for(int i = M-1; i > last; i--){
    	if(ops[i].f == dest) dest = ops[i].s;
    	else if(ops[i].s == dest) dest = ops[i].f;
    }
    for(int i = 0; i < last; i++){
    	if(ops[i].first == -1)ops[i] = {1,2};
    	if(ops[i].first == start) 
    		start = ops[i].s;
    	else if(ops[i].s == start) 
    		start = ops[i].f;
    }
    if(start == dest){
    	int u = (start==1? 2:1), v = (dest == N? N-1: N);
    	ops[last] = {u,v};
    } else {
    	ops[last] = {start, dest};
    }
    for(auto [u,v] : ops) cout << u << " " << v << "\n";
}

