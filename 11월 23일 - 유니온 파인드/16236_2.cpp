//
// 20040번 - 아기 상어
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 401;
typedef pair<int, int> ci;

pair<int, ci> nextPos(int n, int shark_size, ci &shark, vector<vector<int>> &board) {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int min_dist = INF;
    queue<ci> q; //상어가 갈 수 있는 곳
    vector<vector<int>> visited(n, vector<int>(n, 0)); //상어의 방문 여부
    vector<ci> list; //상어가 먹을 수 있는 물고기들의 위치

    visited[shark.first][shark.second] = 1;//상어의 최초 위치를 방문으로 표시 (dist = 1)
    q.push(shark);//큐에 삽입
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        int dist = visited[row][col];//팝된 지점까지의 거리를 저장
        q.pop();

        if (dist >= min_dist) //최단거리 이상은 탐색할 필요 없음
            continue;
        for (int i = 0; i < 4; i++) {//4방향을 탐색
            int nr = row + dr[i];
            int nc = col + dc[i];
            //범위 밖에 존재 / 이미 방문함 / 보드에 존재하는 물고기가 상어보다 큼 -> 방문이 불가능
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] || board[nr][nc] > shark_size)
                continue;


            //방문이 가능한 경우들
            visited[nr][nc] = visited[row][col] + 1; //거리 이전보 1증가
            if (board[nr][nc] && board[nr][nc] < shark_size) { //먹을 수 있는 물고기 발견
                list.emplace_back(nr, nc);//리스트에 넣어둠
                min_dist = visited[nr][nc];// 최단거리로 설정
                continue;
            }
            //먹을 수 있는 물고기를 발견하지 못함 -> 계속 탐색
            q.push({nr, nc});
        }
    }

    if (list.empty()) //상어가 갈 수 있는 곳이 없음
        return {min_dist, {-1, -1}}; //최단거리로 종료


    //정렬 -> 가장 위에있는 물고기(front가 작은게 우선) 같으면, 가장 왼쪽에있는 물고 second가 작은게 우선 기
    sort(list.begin(), list.end(), [](const ci &p1, const ci &p2) { //정렬
        if (p1.first != p2.first)
            return p1.first < p2.first;
        return p1.second < p2.second;
    });
    return {min_dist - 1, list[0]};//가장 앞쪽 list[0]가 선정된 물고기가 된다
}

int simulation(int n, pair<int, int> &shark, vector<vector<int>> &board) {
    int ans = 0, size = 2, cnt = 0;
    while (true) {
        pair<int, ci> result = nextPos(n, size, shark, board);
        if (result.first == INF) //더 이상 먹을 수 있는 물고기가 공간에 없음
            break;
        ans += result.first;
        cnt++;//먹은물고기 수 증가
        if (cnt == size) { //상어 크기 증가
            cnt = 0;
            size++;
        }

        //상어 이동
        ci pos = result.second;
        board[shark.first][shark.second] = 0;
        shark = pos;
    }
    return ans;
}

/**
 * 1. 상어로부터 가장 가까운 거리에 있는 모든 물고기 탐색 (BFS)
 * 2. 우선순위 조건에 맞추어 먹으러 갈 물고기 확정
 *    탐색하는 방향에 우선순위를 두는 걸로 해결되지 않음! (예제 입력 4) 정렬 필요
 * 3. 상어가 이동할 수 있는 곳이 없을 때까지 BFS 탐색 반복
 *
 * 입력 범위가 작기 때문에 매번 BFS 탐색을 반복해도 시간 초과 X
 * 가능한 물고기의 최대 마리 수 : 399마리
 * 최대 BFS 탐색 횟수 : 399회, 1회 탐색마다 while 문은 최대 400회 미만으로 순회
 * 총 연산 횟수 약 160000번으로 충분히 가능
 *
 * 해설 : https://myunji.tistory.com/378
 * *글 자체는 별로 도움이 안되고...그냥 리팩토링하면 코드가 이렇게 되는구나 정도만 봐주세요
 */
int main() {
    int n;
    pair<int, int> shark_pos;

    //입력
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) //상어의 초기 위치
                shark_pos = make_pair(i, j);
        }
    }

    //연산 & 출력
    cout << simulation(n, shark_pos, board);
}