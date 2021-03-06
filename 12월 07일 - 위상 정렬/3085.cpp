//
// 3085번 - 사탕 게임
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> board;
//하 우
int dr[2] = {1, 0};
int dc[2] = {0, 1};

int cntCandy(int n, int row, int col, int dir) {//하나의 열또는 행에 대해 count
    int ans = 0, cnt = 0;//답(cnt중 최대), 연속된 사탕의 수 count
    char cur = ' ';//현재 사탕의 색
    for (int i = 0; i < n; i++) {//무조건 끝까지 체크해봐야함 -> 그중 최대
        if (cur == board[row][col]) { //연속된 사탕
            cnt++;
            ans = max(ans, cnt);
        } else { //불연속
            cnt = 1;
            cur = board[row][col];
        }
        row += dr[dir];
        col += dc[dir];
    }
    return ans;
}

int findCandy(int n) {//모든 열과 행에 대해 count
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, cntCandy(n, 0, i, 0)); //같은 열에 대해
        ans = max(ans, cntCandy(n, i, 0, 1)); //같은 행에 대해
    }
    return ans;
}

int switchCandy(int n, int row, int col, char candy) {
    int ans = 0;
    for (int i = 0; i < 2; i++) { //오른쪽, 아래에 있는 사탕과 바꿔보기
        int nr = row + dr[i], nc = col + dc[i];
        if (nr < n && nc < n && candy != board[nr][nc]) {//범위 내 존재 + 서로 다를 때에만 교환
            swap(board[row][col], board[nr][nc]);//교환
            ans = max(ans, findCandy(n));
            swap(board[row][col], board[nr][nc]);//복구
        }
    }
    return ans;
}

/**
 * 입력 범위가 크지 않으므로 바꿀 수 있는 사탕을 모두 바꿔보며 먹을 수 있는 사탕 계산
 * 오른쪽, 아래에 있는 사탕과만 바꿔도 모든 경우 고려 가능(왼쪽, 위 고려 X)
 *
 * 1. 사탕의 색이 다른 사탕만 교환하기
 * 2. 각 열, 행이 모두 같은 사탕일 때 사탕의 개수가 갱신되지 않도록 주의 (ans 갱신을 line 18~21에서 하는 경우)
 */
int main() {
    int n, max_candy = 0;

    //입력
    cin >> n;
    board.assign(n, vector<char>(n, ' '));//빈칸으로 초기화
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    //연산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            max_candy = max(max_candy, switchCandy(n, i, j, board[i][j]));
    }

    //출력
    cout << max_candy;
}