//
// 1697번 - 숨바꼭질
// "가장 빠른 시간" -> BFS

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<pair<int, int>> q;
bool visited[100002] = {false};

int bfs(int k) {
//    int move[3] = {-1, 1, 2};


    while (!q.empty()) {
        int loc = q.front().first;
        int time = q.front().second;
        q.pop();
        if (loc == k) return time;

        for (int i = 0; i < 3; i++) {
            int next_loc;
            if (i == 0) next_loc = loc + 1;
            if (i == 1) next_loc = loc - 1;
            if (i == 2) next_loc = loc * 2;

            if (!visited[next_loc] && next_loc <= k + 1 && next_loc >= 0) { //k+1 이면 -1로 k가 될 수 있지만, 그 이상은 가망이 없음
                q.push(pair<int, int>(next_loc, time + 1));
                visited[next_loc] = true;
            }


        }


    }
    return 0;

}


int main() {


    int n, k;//수빈의 위치, 동생의 위치
    cin >> n >> k;

    q.push(pair<int, int>(n, 0));
    visited[n] = true;

    cout << bfs(k);

}
