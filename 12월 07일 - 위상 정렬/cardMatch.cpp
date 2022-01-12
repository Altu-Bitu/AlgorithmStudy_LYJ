//
// KAKAO BLINDE RECRUITMENT - 카드 짝 맞추기
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;
const int SIZE = 4;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

vector<vector<ci>> findCard(vector<vector<int>> &board) { //존재하는 모든 카드의 위치를 리턴하는 함수
    vector<vector<ci>> card_pos(7, vector<ci>(0)); //카드의 번호index에 카드의 위치를 저장하는 배열( 최대 카드 수 : 0~6 => 7)
    int cnt = 0;

    //보드판을 조회
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cnt = max(cnt, board[i][j]);//등장하는 최대 카드 번호
            if (board[i][j]) //카드라면 위치 저장(not zero)
                card_pos[board[i][j]].emplace_back(i, j);
        }
    }
    card_pos.resize(cnt + 1); //실제 존재하는 카드의 수만큼 크기 조절
    return card_pos;
}

pair<int, int> ctrl(int row, int col, int dir, vector<vector<int>> &tmp) { //컨트롤로 이동하는 좌표를 리턴하는 함수
    while (true) {//해당 방향으로 계속 이동
        row += dr[dir];
        col += dc[dir];
        if (row < 0 || row >= SIZE || col < 0 ||
            col >= SIZE) //(범위를 벗어남 == 끝까지 갔는데 해당 방향에 카드가 하나도 없다)면 그 방향의 가장 마지막 칸으로 이동
            return make_pair(row - dr[dir], col - dc[dir]);
        if (tmp[row][col] != 0) //계속 이동 하다가 카드를 발견하면, 거기가 -> 누른 키 방향에 있는 가장 가까운 카드
            return make_pair(row, col);
    }
}

int bfs(int r1, int c1, int r2, int c2, vector<vector<int>> &tmp) { //현재 커서에서 목표 카드로 이동하는 가장 적은 비용을 리턴하는 함수
    vector<vector<int>> visited(SIZE, vector<int>(SIZE, 0));//현재 커서에서 해당 칸 까지 도달하는데의 dist를 저장한 배열
    queue<pair<int, int>> q;
    visited[r1][c1] = 1; //반드시 엔터를 누르게 될 것. 엔터를 미리 눌렀다 가정하고 1로 표시
    q.push({r1, c1});

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        int dist = visited[row][col];
        q.pop();

        if (row == r2 && col == c2) //목표 카드에 도달했다면
            return dist;

        for (int i = 0; i < 4; i++) { //컨트롤 입력 이동
            pair<int, int> np = ctrl(row, col, i, tmp);//컨트롤 입력했을때 도달하는 위치
            if (visited[np.first][np.second])//(not zero -> 이미 방문한 적 있음?)
                continue;
            visited[np.first][np.second] = dist + 1;//이전 칸 까지 이동하는데 누른 버튼 수 + 1회(컨트롤로 이동함)
            q.push(np);
        }

        for (int i = 0; i < 4; i++) { //방향키 입력 이동(한칸씩 이동)
            int nr = row + dr[i], nc = col + dc[i];//이동한 위치
            if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4 || visited[nr][nc])//범위 내에 존재하는가
                continue;
            visited[nr][nc] = dist + 1; // 1회 버튼 입력
            q.push({nr, nc});
        }
    }
    return -1; //목표 카드에 도달하지 못함 (실제로는 일어나지 않는 일)
}


/*
 * bit : 0 ~ 2^(카드의 수) => (카드의 수)개 만큼의 카드를 각 각 0번부터 선택하는지 1번부터 선택하는지 까지 고려했을 때 나올 수 있는 가지 수 (2^카드의 수 개)
 * num : 카드의 수
 * r : 커서의 위치 row
 * c : 커서의 위치 col
 * seq
 * cards
 */
int matchCard(int bit, int num, int r, int c, vector<int> &seq, vector<vector<ci>> &cards,
              vector<vector<int>> tmp) { //조합에 대해 카드를 매칭하는 함수
    int ans = 0;
    for (int i = 0; i < num; i++) { //카드의 수 만큼 반복
        int cur = seq[i]; //이번에 매칭할 캐릭터
        int now = 0; //해당 캐릭터의 0번째 카드부터 선택한다고 가정
        if (bit & (1 << i)) //만약 해당 위치의 비트가 1을 표시했다면 해당 위치의 카드(이번에 매칭할 카드)는 1번째 카드부터 선택
            now = 1;

        for (int j = 0; j < 2; j++) {//모든 카드는 두장씩
            now = (now + j) % 2; //이번에 매칭할 카드 인덱스 ( 0 or 1 무엇이 먼저 올 지는 위에서 bit로 결정 )
            int nr = cards[cur][now].first, nc = cards[cur][now].second; //이번에 매칭할 카드 위치
            ans += bfs(r, c, nr, nc, tmp); //현재 커서에서 목표 카드까지 이동하는 비용

            //카드 삭제 + 커서 이동
            tmp[nr][nc] = 0;//목표 지점에 방문했음->카드삭제
            r = nr;
            c = nc;
        }
    }
    return ans;
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 1e9;//최대값 (최소값으로 갱신해 나갈 것)

    vector<vector<ci>> cards = findCard(board); //존재하는 모든 카드의 위치
    int card_cnt = cards.size() - 1; //카드의 개수

    vector<int> seq(card_cnt); //순열을 위한 배열
    for (int i = 0; i < card_cnt; i++)
        seq[i] = i + 1;

    do { //가능한 모든 카드 순서에 대해
        for (int bit = 0; bit < (1
                << card_cnt); bit++) { //0, 1번째 카드 중 어떤 카드를 먼저 뒤집을지 결정 ( 1 << card_cnt == 2^card_cnt (카드 한장당 앞/뒤를 결정해야하므로 카드의 수만큼 제곱
            answer = min(answer, matchCard(bit, card_cnt, r, c, seq, cards, board));// 가능한 모든 순서에 대해 계산하면서 최솟값을 갱신
        }
    } while (next_permutation(seq.begin(), seq.end()));//seq배열에 저장된 수를 이용한 모든 순열을 구해줌 (가능한 모든 카드의 순서)
    return answer;
}

/**
 * 아이디어
 * 1. 범위가 크지 않음(board 4 x 4 & card 6개 )
 * 2. 존재하는 모든 카드의 종류는 6개, 카드 2장이 한 쌍을 이룬다.
 * 3. 뒤집을 카드 순서를 정하는 모든 경우의 수는 6!(카드 순서) * 2^6(2개의 카드 중 어떤 카드를 먼저 뒤집을지) = 46080-> 브루트포스 가능
 * 4. 이번에 목표로 하는 카드에 대해 현재 커서에서 목표 카드까지 가는 최단 경로를 구하며 이동 횟수 전부 구하고 최솟값 갱신
 *
 * 구현
 * 1. 존재하는 모든 카드의 위치를 저장하며 카드의 개수 세기 (findCard)
 * 2. 가능한 모든 카드의 순서(next_permutation)와 각 카드를 뒤집을 순서(bitmask)를 결정
 *    ex) seq = {3, 1, 2}, bit = 011 일 때
 *        3번, 1번, 2번 카드의 순서로 뒤집는다.
 *        3번 카드는 1번째 카드부터, 1번 카드는 0번째 카드부터, 2번 카드는 1번째 카드부터 뒤집는다.
 *        bit의 011이 앞에서부터 각각 1, 2, 3번 카드와 대응함
 * 3. 현재 카드 순서와 각 카드를 뒤집는 순서에 대한 커서 이동 횟수 계산 (matchCard)
 *    현재 커서 위치와 목표 카드 위치에 대해 bfs 함수 실행
 *    컨트롤 입력을 고려해야 하기 때문에 4방향에 대한 방향 이동에 추가로 컨트롤 입력도 처리한다.(ctrl)
 * 4. 매 조합에 따라 board가 갱신되므로 board를 복사한 tmp 사용
 * 공식 풀이 : https://tech.kakao.com/2021/01/25/2021-kakao-recruitment-round-1/
 */


int main() {
    vector<vector<int>> board = {{1, 0, 0, 3},
                                 {2, 0, 0, 0},
                                 {0, 0, 0, 2},
                                 {3, 0, 1, 0}};
    cout << solution(board, 1, 0);
}
