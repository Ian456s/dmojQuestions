#include <bits/stdc++.h>

using namespace std;
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N; cin >> N;
	for(int i = 0; i <= 50000; i++){
		if(int(i*1.08)==N){
			cout << i << "\n";
			return 0;
		}
	}
	cout << ":(" << "\n";
	return 0;
}