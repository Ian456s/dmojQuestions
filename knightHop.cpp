#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
int X1, Y1, X2, Y2;
int dist[10][10];
bool vs[10][10];
pair<int,int> moves[8] = { {1,2}, {1, -2}, {2, 1}, {-2, -1},{-1,2}, {-2,1}, {-1,-2}, {2, -1} };
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	cin >> X1 >> Y1 >> X2 >> Y2;
	X1--; Y1--; X2--; Y2--;
	queue<pair<int,int>> q;
	vs[X1][Y1] = true;
	dist[X1][Y1] = 0;
	q.push({X1, Y1});
	while(!q.empty()) {
		int x = q.front().f;
		int y = q.front().s;
		q.pop();
		for(auto &move : moves) {
			int nextX = x + move.f;
			int nextY = y + move.s;
			if(nextX >= 0 and nextX < 8 and nextY >= 0 and nextY < 8 and !vs[nextX][nextY]) {
				q.push({nextX, nextY});
				vs[nextX][nextY] = true;
				dist[nextX][nextY] = dist[x][y] + 1;
			}
		}
	}
	cout << dist[X2][Y2] << "\n";
	return 0;
}