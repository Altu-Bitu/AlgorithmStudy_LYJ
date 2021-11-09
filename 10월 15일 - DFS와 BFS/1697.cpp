//
// 1697번 - 숨바꼭질
// "가장 빠른 시간" -> BFS

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<pair<int, int>> q;
bool visited[100001] = {false};

int bfs(int k, int n) {
    visited[n] = true;
    q.push(pair<int, int>(n, 0));
    int move[3] = {-1, 1, 0};

    int loc, time;

    while (!q.empty()) {
        loc = q.front().first;
        time = q.front().second;
        q.pop();

        if (loc == k) break;
        move[2] = loc;

        for (int i = 0; i < 3; i++) {

            int next_loc = loc + move[i];

            if (next_loc <= 100000 && next_loc >= 0 &&
                !visited[next_loc]) { //visited[next_loc]를 마지막에 써주지 않아서 OutOfBound였음
                q.push(pair<int, int>(next_loc, time + 1));
                visited[next_loc] = true;
            }


        }


    }
    return time;

}


int main() {


    int n, k;//수빈의 위치, 동생의 위치
    cin >> n >> k;

    cout << bfs(k, n);

}
