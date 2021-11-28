//
// 16236번 - 아기 상어
//

#include <iostream>
#include <vector>
#include <queue>

#define MAX 100

using namespace std;

typedef pair<int, int> ii;


vector<vector<int>> map;
vector<vector<int>> visited;

//상 하 좌 우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int pos_x, pos_y;//상어의 위치

int bfs(int x, int y, int size, int n) {//상어의 위치

    //방문 배열 초기화
    visited.assign(n + 2, vector<int>(n + 2, 0));
    //큐 초기
    queue<ii> q;

//    int cnt = 0;//먹은 물고기의 수

    visited[x][y] = 1;//지금 위치
    q.push({x, y});

    cout << "최초 size : " << size << "\n";

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();
        cout << "===================새로운 pop=================\n";
        cout << " x : " << x << " y : " << y << "\n";

        for (int i = 0; i < 4; i++) {
            cout << "===================방향 전환============\n";
            cout << "============================================\n";
            int nx = x + dx[i];
            int ny = y + dy[i];


            cout << " nx : " << nx << " ny : " << ny << "\n";

            //이동 가능한 칸의 조건
            //범위 내에 있음 && 상어의 크기보다 작거나 같아함 && 방문한적 없음
            if (map[nx][ny] > -1 && map[nx][ny] <= size && visited[nx][ny] == 0) {

                cout << "방문 했음\n";

                visited[nx][ny] = visited[x][y] + 1; //방문하기
                cout << "size : " << size << "\n";
                cout << "map[nx][ny] : " << map[nx][ny] << "\n";
                cout << "visited[nx][ny] : " << visited[nx][ny] << "\n";

                if (map[nx][ny] != 0 && map[nx][ny] < size) {//자신보다 작은 물고기를 찾았음 (먹기)

                    cout << "물고기 먹음\n";
                    pos_x = nx;
                    pos_y = ny;
                    map[nx][ny] = 0;//해당 칸의 물고기 제거
                    return visited[nx][ny] - 1; //1부터 시작해서 -1해줘야함

                }

                q.push({nx, ny}); // 탐색을 위해 큐에 이동한 위치 넣기
                cout << "============================================\n";
            }

        }


    }

    return -1;//자신보다 작은 물고기를 찾지 못했음

}

int main() {

    int n;
    cin >> n;

    map.assign(n + 2, vector<int>(n + 2, -1));


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];

            if (map[i][j] == 9) {//상어의 현 위치
                pos_x = i;
                pos_y = j;
            }
        }
    }


    int size = 2;//상어의 크기
    int time = 0;
    int cnt = 0;


    while (true) {
        cout << "상어의 위치 와 상어의 크기 \n";
        cout << "pos_x : " << pos_x << " pos_y : " << pos_y << " size : " << size << "\n";

        int res = bfs(pos_x, pos_y, size, n);

        cout << "결과 값 : " << res << "\n";

        if (res == -1) break;

        //결과가 어쨌든 있으니 물고기 한마리 먹음
        cnt++;

        time += res;//time을 추가

        if (cnt == size) {
            size++;//물고기를 먹어서 크기가 1커짐
            cnt = 0;
        }
    }

    cout << "답 " << time;


}

