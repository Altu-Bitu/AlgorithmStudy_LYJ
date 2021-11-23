//
// 14503번 - 로봇청소기
//
// 참고(반례) : https://www.acmicpc.net/board/view/72795 -> 범위 지정안해서였음

#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, m, d;

    cin >> n >> m;

    int rr, rc; //robot row, column

    cin >> rr >> rc >> d;


    vector<vector<int>> room(n, vector<int>(m, 0));
    vector<vector<bool>> check(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
            if (room[i][j] == 1) check[i][j] = true;
        }
    }

    int ans = 0;


    while (true) {

        //1. 현재위치를 청소한다.
        if (!check[rr][rc]) {
            check[rr][rc] = true; //해당 칸을 청소했다고 바꾸기
            ans++;//몇칸이나 청소했는지
        }


        //2. 현재 위치에서 현재 방향 기준으로 왼쪽 부터 차례로 인접 칸을 탐색
        //북(0) 동(1) 남(2) 서(3)
        int row[4] = {-1, 0, 1, 0};
        int col[4] = {0, 1, 0, -1};

        int dir = d;
        int i = 0;
        while (i < 4) {//(2.b) 왼쪽 방향에 청소할 공간이 없으면다음 방향으로 머리 틀기

            //move left
            dir--;
            if (dir < 0) dir = 3;
            int nr = rr + row[dir];
            int nc = rc + col[dir];

            //벽아님(0) + 청소이전 (방이 벽으로 둘러싸여 있으므로, 범위 검사 안해도 됨)
            if (room[nr][rc] == 0 && !check[nr][nc]) {
                //(2.a)해당 방향으로 회전
                d = dir;
                //전진
                rr = nr;
                rc = nc;
                break;
            }
            i++;

        }

        //(2) 4방향 모두 청소가 되어있거나 벽임
        if (i == 4) {
            //바라보는 방향 유지 -> d바뀐적 없으므로 d계속 쓰면됨

            // 뒤로 한칸 이동했을 때 위치
            int nr = rr + row[(d + 2) % 4];
            int nc = rc + col[(d + 2) % 4];
            //2.c) 후진 가능
            if (room[nr][nc] == 0) {
                //해당 칸으로 이동 / 방향은 그대로니까 건들지 x
                rr = nr;
                rc = nc;
            } else {//2.d) 후진 불가
                cout << ans;
                return 0;
            }


        }

    }
}

