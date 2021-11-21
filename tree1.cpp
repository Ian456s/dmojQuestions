#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

const int INF = 0x3f3f3f3f;
const int MAX = 1e5 + 5;
int arr[4][4];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int i = 0; i < 4; i++){
    	for(int j = 0; j < 4; j++){
    		cin >> arr[i][j];
    	}
    }
    int sum = 0;
    int row = 0;
    for(int i = 0; i < 4; i++){
    	row = 0;
    	for(int j = 0; j < 4; j++){
    		row += arr[i][j];
    		sum += arr[i][j];
    	}
    	if(row == 0){
    		cout << "No" << "\n";
    		return 0;
    	}
    }
    if(sum == 6){
    	cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
    return 0;
}
