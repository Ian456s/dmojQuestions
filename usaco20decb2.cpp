#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f first
#define s second
#define FILL memset(a, b, sizeof(a))
const int INF = 0x3f3f3f3f;
const int MAX = 1e2 + 5;
int arr[MAX];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }
    int num = 0;
    for(int i = 0; i < n; i++){
    	int sum = 0;
    	for(int j = i; j < n; j++){
    		sum+= arr[j];
    		for(int k = i; k<=j; k++){
    			if(arr[k] * (j-i+1) == sum){
    				num++; break;
    			}
    		}
    	}
    }
    cout << num << "\n";
    return 0;
}