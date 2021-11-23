//
// 14503번 -
//

#include <iostream>
#include <vector>

using namespace std;

int cntCleanRobot(int r, int c, int d, vector<vector<int>> &board) {
    //상(0), 우(3), 하(2), 좌(1)
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    /*
     * 방향 관련
     * 왼쪽으로 회전하는 경우
     * 상(북) -> 왼(서) -> 하(남) -> 우(동)
     * 0[0] -> 1[3] -> 2[2] -> 3[1]
     * index로는 d = (d + 3) % 4
     */

    int step = 0, ans = 0;
    while (true) {
        if (board[r][c] == 0) {//청소가 되어 있지 않음,
            board[r][c] = 2;//청소된 상태로 바꾸기
            ans++;//청소한 칸의 수 증가
        }

        if (step == 4) {//4회 반복 -> 방향을 전부 탐색했음
            if (board[r - dr[d]][c - dc[d]] == 1)//뒤가 벽(1)이라 후진 불가
                return ans;//종료

            //뒤가 벽이 아니라 후진 가능
            r -= dr[d];//방향은 바뀐적 없으므로 그대로 후진
            c -= dc[d];
            step = 0;//step 초기화
        } else {//방향 탐색
            d = (d + 3) % 4;//왼쪽으로 돌기->최대 3번만 가능 (4번하면 원래대로 돌아옴)
            if (board[r + dr[d]][c + dc[d]]) {//왼쪽으로 돌았을 때, 벽(1)
                step++;
                continue; // 왼쪽으로 다시 돌아야함
            }
            //해당 방향으로 이동
            r += dr[d];
            c += dc[d];
            step = 0;//step 초기화
        }
    }
}

/**
 * board 정보 -> 0: 빈 칸, 1: 벽, 2: 청소한 공간
 * step: 회전 카운트. 4가 되면 한 바퀴 돌아 다시 제자리로 돌아왔음을 의미
 *
 * 항상 첫 행, 마지막 행, 첫 열, 마지막 열은 벽이라고 문제에서 주어졌으므로 범위 검사를 할 필요가 없음
 */

int main() {
    int n, m, r, c, d;

    //입력
    cin >> n >> m >> r >> c >> d;
    vector<vector<int>> board(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    //연산 & 출력
    cout << cntCleanRobot(r, c, d, board); //로봇청소기 위치, 방향, 방의 구조
    return 0;
}
