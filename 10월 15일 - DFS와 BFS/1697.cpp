//
// 1697번 - 숨바꼭질
// "가장 빠른 시간" -> BFS

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<pair<int, int>> q;
bool visited[200001] = {false};

int bfs(int k) {
    int move[3] = {-1, 1, 2};


    while (!q.empty()) {
        int loc = q.front().first;
        int time = q.front().second;


        if (loc == k) return time;

        for (int i = 0; i < 3; i++) {
            if (i == 0) loc++;
            if (i == 1) loc--;
            if (i == 2) loc *= 2;

            if (!visited[loc] && loc < k * 2 + 1 && loc >= 0) {
                q.push(pair<int, int>(loc, time + 1));
                visited[loc] = true;
            }

            loc = q.front().first;

        }
        q.pop();


    }

}


int main() {


    int n, k;//수빈의 위치, 동생의 위치
    cin >> n >> k;

    q.push(pair<int, int>(n, 0));
    visited[n] = true;

    cout << bfs(k);

}
