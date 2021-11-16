//
// 2615번 - 오목
//

#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 19; // 오목판의 크기 19x19 크기 제한

//범위와 돌의 종류가 유효한지 확인
bool promising(int r, int c, int stone, vector<vector<int>> &board) { //위치값, 돌의색, board
    //현재 위치가 범위 내에 있음 -> 앞으로 탐색할 && 지금 돌이 정상 범위 내에 있음
    // 돌의 색(이전에 위치한 이어지는 돌의 색)이 현재 돌의 색과 같음
    // true : 정상 범위 내에 있으며(탐색 가능) && 같은 색상의 돌
    // false : 정상 범위가 아님 || 같은 색상이 아님
    return r >= 0 && r < SIZE && c >= 0 && c < SIZE && board[r][c] == stone;
}

bool validDir(int r, int c, int d, int stone, vector<vector<int>> &board) {//위치값, 방향(4가지), 돌의 색, board
    //가로, 세로, 우하향 대각선, 우상향 대각선
    int dr[4] = {0, 1, 1, -1}; // 이동x , 아래1칸, 아래 1칸, 위로 1칸
    int dc[4] = {1, 0, 1, 1}; //오른쪽 1칸 , 이동 x , 오른쪽 1칸, 오른쪽 1칸

    //(r, c) 이전에 위치한 이어지는 돌이 있나? yes면, 6개 이상이므로 답이 될수 없음
    bool is_six = promising(r - dr[d], c - dc[d], stone, board); // 조사하려는 방향 이전이므로 -로 위치값을 제공해서 실행

    int cnt = 0;//연속된 돌의 갯수
    while (cnt < 6 && promising(r, c, stone, board)) { //(r, c)를 "가장 왼쪽"으로 하는 이어지는 바둑알의 개수
        cnt++;//돌의 수 증가
        r += dr[d];//입력받은 방향으로 row를 이동 -> promising 함수로 재검사
        c += dc[d];//입력받은 방향으로 col을 이동 -> promising 함수로 재검사
    }
    return cnt == 5 && !is_six;//연속된 돌의 수가 5개 이며, 이전방향에 돌이 없음
}

bool isEnd(int r, int c, vector<vector<int>> &board) { // 매개변수 : row, col, 보드판의 상태벡터

    //현재 칸에 대하여 (가로, 세로, 우하향, 우상향 대각선을 검사해서 5개가 되었는지 검사)
    for (int i = 0; i < 4; i++) { //가로, 세로, 우하향 대각선, 우상향 대각선 (=> 총 4회)
        if (validDir(r, c, i, board[r][c], board)) //해당 방향으로 5개 연속(6개 이상은 아닌)인지 검사
            return true;//검사가 true일 경우 누군가 이겼음 (true return)
    }
    return false;//4가지 방향으로의 유효성검사를 마쳤는데 true가 return되지 않았으면, 해당 위치에서는 승리하지 않았음 -> 누군가 이기지 않음
}

/**
 * 1. 특정 좌표(r, c)를 가장 왼쪽으로 하는 가능한 모든 오목 배치에 대해 오목 여부 확인
 *    가능한 모든 배치 :  오른쪽, 아래, 우하향, 우상향
 * 2. 육목이상이 되는 경우 : (r, c) 왼쪽에 같은 돌이 있는 경우
 */
int main() {
    vector<vector<int>> board(SIZE, vector<int>(SIZE, 0)); //오목판상태를 입력받을 벡터배열 선언

    //입력
    for (int i = 0; i < SIZE; i++) {//row를 입력받음
        for (int j = 0; j < SIZE; j++)//해당 row마다의 col을 입력받음
            cin >> board[i][j];//해당 칸의 상태를 입력받음
    }

    //연산 & 출력
    // 0row 0col부터 차례대로 모든 칸을 검사함
    for (int i = 0; i < SIZE; i++) {//모든 row에 대하여
        for (int j = 0; j < SIZE; j++) {// 모든 col에 대하여
            if (!board[i][j]) //돌이 없음(0)
                continue;//  돌이 없는 경우 연산이 필요 없음
            if (isEnd(i, j, board)) { //누군가 이겼나? -> 이겼으면, 현재칸이 시작칸(가장 왼쪽이었음)이므로 출력 후 종료
                cout << board[i][j] << '\n' << i + 1 << ' ' << j + 1; //출력은 1부터 시작, 실제로는 0부터 시작이었으므로 +1
                return 0;//종료
            }
        }
    }
    cout << 0; //누군가 이긴적이 한번도 없으면, 비긴것임
}