//
// 14500번 - 테르토미노 
//

#include <iostream>
#include <vector>

using namespace std;

int ans, n, m;
vector<vector<int>> board;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

//board[row][col]을 가운데로 하는 +모양 만들기
int horn(int row, int col) {
    int cnt = 0, min_block = 1001;//블럭 한칸이 가질 수 있는 최대 값 1000
    int sum = board[row][col]; //sum에 (+의)중앙 값을 저장

    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr < 0 || nr >= n || nc < 0 || nc >= m) //범위를 벗어나면 무시
            continue;
        min_block = min(min_block, board[nr][nc]); //가장자리 블럭 중 값이 가장 작은 블럭
        sum += board[nr][nc];
        cnt++;//사용한 블럭의 수 (총 3개여야함)
    }

    //continue에 걸려서 강제로 3개 or 3개 이하가 된경우
    if (cnt < 3) //가능한 가장자리가 최소 3개 이상이어야 함
        return 0;
    if (cnt == 3) //ㅗㅏㅜㅓ
        return sum;
    //+ ( 범위에 걸리지 않아 + 가 완성된 경우 거기서 제일 작은 수를 하나 빼서 리턴)
    return sum - min_block;
}

//한붓 그리기가 가능한 블럭들 백트래킹 탐색
void backtracking(int row, int col, int cnt, int sum) { //sum : 블록들의 합 (이번 회차에서 방문표시한 블록을 더해서보내줌)
    if (cnt == 4) { //기저조건 : 4개의 블럭을 탐색함
        ans = max(ans, sum);//구한 값이 ans로 저장된 값보다 크면 갱신
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr < 0 || nr >= n || nc < 0 || nc >= m || !board[nr][nc]) //범위를 벗어나거나, 이미 방문했다면
            continue;

        int save = board[nr][nc];
        board[nr][nc] = 0;//방문표시 (0으로 변경)
        backtracking(nr, nc, cnt + 1, sum + save);
        board[nr][nc] = save;//원복
    }
}

/**
 * 1. 각 블럭을 백트래킹이 가능한 블럭과 불가능한 블럭으로 나누기
 *    -> 블럭을 한붓 그리기로 그릴 수 있으면 백트래킹이 가능 아니라면 불가능
 *    -> 보라색 블럭(ㅜ)을 제외하면 모두 백트래킹 가능
 * 2. 보라색 블럭은 + 모양에서 가장자리를 하나 제거한 것과 같음
 *    -> 가운데 블럭을 중심으로 가장자리 블럭을 붙여보고 가능한 최댓값 구하기
 * 3. 각 블럭에 대해 깊이가 4인 백트래킹 함수를 수행하며 최댓값 갱신
 *
 * 해설 : https://myunji.tistory.com/297
 * *코드가 살짝 달라요(블로그 코드는 최적화 하기 전)
 */
int main() {
    //입력
    cin >> n >> m; // n x m의 점수 board
    board.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    //연산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, horn(i, j)); //보라색 블럭 처리 -> 보라색 블록중에서 나올 수 있는 최대값

            //[i][j]를 시작으로 하는 (한붓그리기 가능한) 연속 4개의 합 
            int save = board[i][j];
            board[i][j] = 0; //방문 표시
            backtracking(i, j, 1, save); //나머지 모양 처리
            board[i][j] = save;//원상복귀
        }
    }

    //출력
    cout << ans;
}