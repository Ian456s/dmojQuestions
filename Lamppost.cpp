#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e6 + 5;
int arr[MAX];
int N, C;
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> C;
	for(int i = 0; i < C; i++){
		int a, b; cin >> a >> b;
		arr[a]++;
		arr[b]++;
	}
	int greatest = -1, idx = -1;
	for(int i = 0; i <= N; i++){
		if(arr[i] >= greatest){
			greatest = arr[i];
			idx = i;
		}
	}
	cout << idx << "\n";
}