#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

const int INF = 0x3f3f3f3f;
const int MAX = 1e4 + 5;
double arr[MAX];
int n;
double p, c;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 	cin >> n;
 	for(int i = 0; i < n; i++){
 		cin >> p >> c;
 		arr[i] = (p/((c/100)+1));
 	}
 	for(int i = 0 ; i < n; i++){
 		cout << arr[i] << "\n";
 	}
    return 0;
}