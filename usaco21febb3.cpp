#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f first
#define s second
#define pb push_back
#define FILL memset(a, b, sizeof(a))
const int INF = 0x3f3f3f3f;
const int MAX = 1e5 + 5;
int N; string s;
vector<string> right_turn = {"NE", "ES", "SW", "WN"};
char arr[MAX];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    while(N--){
    	cin >> s; strcpy(arr, s.c_str());
    	int cw = 0, ccw = 0;
    	for(int i = 1; i < s.length(); i++){
    		if(arr[i-1]==arr[i]) continue; //no turn
    		string tieurn = "" + arr[i-1] + arr[i]; cout << turn << "\n";
    		if(find(right_turn.begin(), right_turn.end(), turn) != right_turn.end())cw++;
    		else ccw++;
    	}
    	cout << cw << " " << ccw << "\n";
    	cout << ((cw > ccw)?"CW":"CCW") << "\n";
    }
    return 0;
}

