#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f first
#define s second
#define FILL memset(a, b, sizeof(a))
const int INF = 0x3f3f3f3f;
const int MAX = 1e5 + 5;
int scores[] = {0, 0, 0, 0, 0};
int ans = 0;
vector<vector<int>> game(5, vector<int>(5, 0)); //5x5 vector filled with 0s
int fav, n, remainingGames;
void simulate(){
	if(remainingGames == 0){							//no more games to simulate
		for(int i = 1; i <= 4; i++){					//go through scores of all temas
			if(i != fav && scores[i] >= scores[fav]){	//if current team has more points than our favourite then we can stop
				return;
			}
		}
		ans++;											//if this statement is reached then that means our favourite team has the most points,
		return;											//so we can increment the answer
	}
	vector<vector<int>> copyGame = game;
	for(int i = 1; i <= 4; i++){
		for(int j = i + 1; j <= 4; j++){
			if (game[i][j] == 0) {						//if current team didn't play, then play
				remainingGames--;						//remaining games decrements
				game[i][j] = game[j][i] = 1;			//teams i and j play each other

				scores[i] += 3;							//assuming team i wins
				simulate();								//simulating the rest
				scores[i] -= 3;

				scores[i]++;							//in the scenario team i and j tie
				scores[j]++;				
				simulate();
				scores[i]--;
				scores[j]--;

				scores[j] += 3;
				simulate();
				scores[j] -= 3;

				remainingGames++;						//unsimulate the occurrence of this game
			}
		}
	}
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> fav;
    cin >> n;
    for(int i = 0; i < n; i++){
    	int a, b, s1, s2; cin >> a >> b >> s1 >> s2;
    	if (s1 == s2){
    		scores[a]++;
    		scores[b]++;
    	} else if (s1 > s2){
    		scores[a] += 3;
    	} else {
    		scores[b] += 3;
    	}
    	game[a][b] = 1;
    }
    remainingGames = 6 - n;
    simulate();
    cout << ans << "\n";
    return 0;
}