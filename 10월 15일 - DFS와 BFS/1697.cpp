//
// 1697번 - 숨바꼭질
// "가장 빠른 시간" -> BFS

#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> q;

int bfs(int k) {
    int move[3] = {-1, 1, 2};


    while (!q.empty()) {
        int loc = q.front().first;
        int time = q.front().second;
        q.pop();
        if (loc == k)return time;

        for (int i = 0; i < 3; i++) {
            if (move[i] == 2) loc = loc * 2;
            else {
                loc += move[i];
            }

            q.push(pair<int, int>(loc, time + 1));

        }


    }

}


int main() {


    int n, k;//수빈의 위치, 동생의 위치
    cin >> n >> k;

    q.push(pair<int, int>(n, 0));

    cout << bfs(k);

}
