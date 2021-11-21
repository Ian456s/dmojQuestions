#include <bits/stdc++.h>

using namespace std;
const int MAX = 105;
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T, C; cin >> T >> C;
	int tasks[C];
	int tasksDone = 0;
	for(int i = 0; i < C; i++){
		cin >> tasks[i];
	}
	sort(tasks, tasks+C);
	for(int i = 0; i < C; i++){
		if(T - tasks[i] >= 0){
			tasksDone ++;
			T-=tasks[i];
		} else {
			cout << tasksDone << "\n";
			break;
		}
	}

	return 0;
}