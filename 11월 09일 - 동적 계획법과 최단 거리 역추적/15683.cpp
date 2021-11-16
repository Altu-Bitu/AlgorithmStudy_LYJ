//
// 15683번 - 감시
//

#include <iostream>
#include <vector>

using namespace std;

//각 함수에서 변수 사용이 가능하도록 전역변수로 설정
int n, m, ans = 65;// board의 크기는 최대 8x8이므로, 최대사각지대는 64이다. 그래서 절대 나올 수 없는 최대값인 65로 ans를 초기화해놓고 최적화 해나가기
vector<vector<int>> board;// 사무실의 상태를 입력받을 변수

//cctv 범위 표시(파악할 수 있는 곳을 7로 변경해둠)
void ray(int row, int col, int dir) {
    //모든 cctv는 90도로 회전이 가능하므로, 최대 4개의 다른방향을 보고있는 카메라가 존재할 것
    //상,우,하,좌 (상부터 "90도로 이동함"! -> 제약조건)
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    //dir 방향으로 뻗어나가며 cctv 표시
    while (row >= 0 && row < n && col >= 0 && col < m && board[row][col] != 6) { //벽 or 범위가 끝나면 중지!
        if (board[row][col] == 0) //다른 cctv를 지우지 않기 위해 빈 공간일 때만 표시
            board[row][col] = 7;//cctv가 확인할 수 있는 지역을 7로 변경 (=="#'과 역할이 같음)
        row += dr[dir];//해당 방향으로의 다음칸을 탐색(row)
        col += dc[dir];//해당 방향으로의 다음칸을 탐색(col)
    }
}

//cctv 방향 지정
void install(int cctv, int row, int col, int dir) {//cctv번호, 위치정보(row,col), 방향

    /*
     * if dir = 0이라고 가정, (cctv를 위쪽 방향을 보게 달아둠)
     * 1번 cctv ↑
     * 2번 cctv ↑ ↓
     * 3번 cctv ↑ →
     * 4번 cctv ↑ → ↓
     * 5번 cctv ← → ↑ ↓
     * 이렇게 검사 되어야 한다.
     * 즉, dir의 한번에 입력에, 회
     * cctv 1번은 1회
     * 2,3번은 2회
     * 4번은 3회
     * 5번은 4회
     * 검사되어야 하니, 하나의 dir입력에 대해 if문이 4번 돌아간다.
     *
     * dir = 0인 경우,
     * dir = ↑ (cctv 1, 2, 3 ,4 ,5 번)
     * ( dir + 2 ) % 4 = ↓ (cctv 2, 4, 5번)
     * ( dir + 1 ) % 4 = → (cctv 3, 4, 5번)
     * ( dir + 3 ) % 4 = ← (cctv 5번)
     *  각각 4가지 방향에 대해 if문이 작성되며 각 방향에 대한 검사를 만족한다
     */


    if (cctv >= 1) //1, 2, 3, 4, 5번 cctv
        ray(row, col, dir);
    if (cctv >= 2 && cctv != 3) //2, 4, 5번 cctv
        ray(row, col, (dir + 2) % 4);
    if (cctv >= 3) //3, 4, 5번 cctv
        ray(row, col, (dir + 1) % 4);
    if (cctv == 5) //5번 cctv
        ray(row, col, (dir + 3) % 4);
}

//사각지대 계산 -> 감시 가능한 곳을 7로 변경해두었으므로 0인곳이 사각지대
int blindSpot() {
    int cnt = 0;//0의 갯수(사각지대)
    for (int i = 0; i < n; i++) { //모든 사무실 row에 대해
        for (int j = 0; j < m; j++) {//모든 사무실 col에 대해
            if (!board[i][j])//0인 경우
                cnt++;//사각지대의 수를 증가
        }
    }
    return cnt;//계산한 사각지대의 수 반환
}

void backtracking(int idx) {//현재 검사 횟수(==사무실의 모든 칸을 확인해야함)
    if (idx == n * m) { //기저 조건 : 사무실의 모든 위치 확인
        ans = min(ans, blindSpot()); //사각지대 계산 후 최솟값 갱신
        return;//다시 되돌아가 새로운 방향을 보고있는 카메라로 재탐색
    }

    //해당 idx가 어느칸인지
    int row = idx / m;// row = (idx / 한 row의 칸 수)
    int col = idx % m;// col =  (idx / 한 row의 칸 수) 의 나머지
    int cur = board[row][col]; //현재 idx에 해당하는 위치에 씌여진 값 -> 벽인지, 빈공간인지, cctv인지
    if (cur == 0 || cur == 6 || cur == 7) //cctv가 없는 곳 -> cctv가 어느 곳을 비추는지 계산 불가
        return backtracking(idx + 1);//다음 idx탐색


    // 해당지점 cctv가 존재하는 경우
    vector<vector<int>> save = board; //unvisited 처리용 board 상태 저장
    for (int i = 0; i < 4; i++) { //4개의 방향에 대해 cctv 설치 (0:↑ 1:→ 2:↓ 3:←)
        install(cur, row, col, i);//cur:cctv 번호 , cctv 위치(row,col), 방향 (↑ → ↓ ←)
        backtracking(idx + 1);
        board = save;//또 다른 탐색을 위해 board상태 복구

        //cctv가 2 or 5인 경우
        if ((cur == 2 && i == 1) || (cur == 5 && i == 0))//2번 cctv의 방향 종류는 2개, 5번 cctv의 방향 종류는 1개
            break;//4가지 방향을 전부 탐색 가능 (4번을 다 돌 필요가 없음)
    }
}

/**
 * cctv가 설치될 수 있는 모든 경우를 고려하는 완전탐색 문제
 *
 * 1. 각 cctv에 대해 가능한 모든 방향을 고려하여 설치
 *    1, 3, 4번 cctv : 4방향
 *    2번 cctv : 2방향
 *    5번 cctv : 1방향
 * 2. install 함수에서 각 cctv의 빛이 뻗어나갈 방향을 잡음
 * 3. ray 함수에서 cctv의 감시 가능 범위 표시
 * 4. 모든 위치를 확인했으면 blindSpot 함수를 통해 사각지대 계산
 *
 * 풀이 : https://myunji.tistory.com/411
 * 해당 코드는 위 링크의 코드를 리팩토링한 코드입니다.
 * 말로는 풀이를 설명하기 어려우니 링크를 꼭 확인해주세요!
 */
int main() {
    //입력
    cin >> n >> m;//사무실의 가로, 세로 크기를 입력받음
    board.assign(n, vector<int>(m));//사무실의 상태(벽, cctv의 위치 등)을 저장할 벡터크기 지정
    for (int i = 0; i < n; i++) {//모든 row에 대해
        for (int j = 0; j < m; j++)//모든 col에 대해
            cin >> board[i][j];//상태를 입력받아 저장
    }

    //연산
    backtracking(0);//0번 인덱스부터 탐색시작

    //출력
    cout << ans;//최소로 갱신된 사각지대의 수 출력
}