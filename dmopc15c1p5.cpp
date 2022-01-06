#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f first
#define s second
const int INF = 0x3f3f3f3f;
const int MAX = 255;
int psa[MAX][MAX], arr[MAX][MAX];
int findArea(int x, int y, int x2, int y2){
	return psa[x2][y2] - psa[x-1][y2] - psa[x2][y-1] + psa[x-1][y-1];
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int w, h, n;
    cin >> w >> h >> n;
    for(int i = 1; i <= h; i++){
    	for(int j = 1; j <= w; j++){
    		cin >> arr[i][j];
    	}
    }
    vector<pair<int,int>> ways;
    for(int i = 1; i * i <= n; i++){
    	ways.push_back({i, n/i});
    	ways.push_back({n/i, i});
    }
    for(int i = 1; i <= h; i++){
    	for(int j = 1; j <= w; j++){
    		psa[i][j] = arr[i][j] + psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
    	}
    }
    int greatest = 0;
    for(int i = 1; i <= h; i++){
    	for(int j = 1; j <= w; j++){
    		for(auto &way : ways){
    			int x = i, y = j;
    			int x2 = min(h, i + way.f-1), y2 = min(w, j + way.s-1); 
    			int area = findArea(x,y,x2,y2);
    			greatest = max(greatest,area);
    		}
    	}
    }
    cout << greatest << "\n";
    return 0;
}