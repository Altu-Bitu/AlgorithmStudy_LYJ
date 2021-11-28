//
// 16236번 - 아기 상어
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>

#define MAX 100

using namespace std;

typedef pair<int, int> ii;


vector<vector<int>> board;//맵
vector<vector<int>> record;//매 턴에 칸마다 최단시간을 기록
vector<vector<bool>> visited; //해당 턴에 방문여부를 체크

map<int, int> m;

//상 하 좌 우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int pos_x, pos_y, tmp_x, tmp_y, tmp_xx, tmp_yy;//상어의 위치(찐), 임시(저장), 임시

int bfs(int x, int y, int size, int n, vector<vector<bool>> &visited) {//상어의 위치

    //방문 배열 초기화
    record.assign(n + 2, vector<int>(n + 2, 0));
    //큐 초기
    queue<ii> q;

    record[x][y] = 1;//지금 위치
    q.push({x, y});


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
            if (board[nx][ny] > -1 && board[nx][ny] <= size && record[nx][ny] == 0) {

                cout << "방문 했음\n";

                record[nx][ny] = record[x][y] + 1; //방문하기
                cout << "size : " << size << "\n";
                cout << "board[nx][ny] : " << board[nx][ny] << "\n";
                cout << "record[nx][ny] : " << record[nx][ny] << "\n";

                if (board[nx][ny] != 0 && board[nx][ny] < size &&
                    !visited[nx][ny]) {//자신보다 작은 물고기를 찾았음 (먹기) && 먹은적 없는 물고기임

                    cout << "물고기 찾음\n";
                    tmp_xx = nx;
                    tmp_yy = ny;
                    visited[nx][ny] = true;//먹었다고 표시하기
//                    m[board[nx][ny]]--;//해당 칸의 크기를 가진 물고기의 수 감소
//                    board[nx][ny] = 0;//해당 칸의 물고기 제거

                    return record[nx][ny] - 1; //1부터 시작해서 -1해줘야함

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

    board.assign(n + 2, vector<int>(n + 2, -1));


    int num;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> num;
            board[i][j] = num;

            if (num == 9) {//상어의 현 위치
                pos_x = i;
                pos_y = j;
            } else if (num != 0) {//9아니고 0도아니면
                m[num]++;//각 크기별 물고기의 갯수를 저장
            }
        }
    }


    int size = 2;//상어의 크기
    int time = 0;
    int cnt = 0;

    int mintime = 9999999;
    int tmp_size;//먹을 물고기의 크기

    int fish;//먹을 수 있는 물고기의 수

    while (true) {
        cout << "상어의 위치 와 상어의 크기 \n";
        cout << "pos_x : " << pos_x << " pos_y : " << pos_y << " size : " << size << "\n";

        fish = 0;//먹을 수 있는 물고기의 수 (상어보다 작은 물고기의 수)
        for (auto i = m.begin(); i != m.end(); i++) {
            if (i->first < size) fish += i->second; //물고기의 크기가 size보다 작으면, 물고기의 수를 더함
        }

        cout << "총 물고기의 수 : " << fish << "\n";
        if (fish <= 0)break; //먹을 수 있는 물고기의 수가 0이하면, 종료

        //방문 여부 (먹을 수 있는 물고기 중에 먹은거 체크)
        visited.assign(n + 2, vector<bool>(n + 2, false));


        while (fish--) {//먹을수 있는 물고기의 수만큼 반복

            int res = bfs(pos_x, pos_y, size, n, visited);
            cout << " 걸린시간 : " << res << "\n";
            cout << " min time : " << mintime << "\n";
            if (mintime > res) { //최솟값 갱신이 된다면
                //해당 물고기의 위치 저장 (나중에 여기로 이동해야함) pos_x , pos_y
                tmp_x = tmp_xx;
                tmp_y = tmp_yy;

                //해당 물고기의 크기 저장 (해당 크기의 물고기 수 줄여야함 / 해당 칸의 물고기 없애야함)
                tmp_size = board[tmp_x][tmp_y];//물고기의 크기 갱신 (해당 크기의 물고기 수 줄여야함 / 해당 칸의 물고기 없애야함)

                //mintime 갱신
                mintime = res;

                cout << "물고기 찾음1\n";

            } else if (mintime == res) {

                //저장되어 있는 물고기보다 x가 더 작은가(위에있는가?) -> 같으면?
                if (tmp_x > tmp_xx) {
                    cout << "물고기 찾음2\n";
                    //물고기의 위치갱신(나중에 여기로 이동해야함) pos_x , pos_y
                    tmp_x = tmp_xx;
                    tmp_y = tmp_yy;
                    tmp_size = board[tmp_x][tmp_y];//물고기의 크기 갱신 (해당 크기의 물고기 수 줄여야함 / 해당 칸의 물고기 없애야함)

                } else if (tmp_x == tmp_xx && tmp_y > tmp_yy) {//같으면, 저장되어 있는 물고기 보다 y가 더 작은가? (더 왼쪽에 있는가)

                    cout << "물고기 찾음3\n";
                    //물고기의 위치갱신(나중에 여기로 이동해야함) pos_x , pos_y
                    tmp_x = tmp_xx;
                    tmp_y = tmp_yy;
                    tmp_size = board[tmp_x][tmp_y];//물고기의 크기 갱신 (해당 크기의 물고기 수 줄여야함 / 해당 칸의 물고기 없애야함)
                }


            }


        }
        cout << "<<<<<<<<<<<<<<<<<최종으로 먹은 물고기 정보>>>>>>>>>>>>>>>>>>\n";
        //해당 위치로 이동
        pos_x = tmp_x;
        pos_y = tmp_y;
        m[tmp_size]--;//해당사이즈의 물고기 한마리 삭제
        board[pos_x][pos_y] = 0;//해당 칸의 물고기를 제거
        cout << " min_time : " << mintime << "\n";//해당 위치의 물고기를 먹는데 걸린 시간
        time += mintime;//time을 추가
        mintime = 9999999;//초기화
        cnt++;//물고기 한마리 먹음

//        cout << "<<<<<<<<<<<<<<<<<최종으로 먹은 물고기 정보>>>>>>>>>>>>>>>>>>\n";
        cout << " size : " << tmp_size << "\n"; //먹은 물고기 크기
        cout << " pos x : " << pos_x << "\n";//먹은 물고기 위치
        cout << " pos y : " << pos_y << "\n";
//        cout << " min_time : " << mintime << "\n";
        cout << " 총 먹은 물고기 수  : " << cnt << "\n";


        if (cnt == size) {
            cout << "물고기랑 사이즈 수랑 똑같아짐\n";
            size++;//물고기를 먹어서 크기가 1커짐
            cnt = 0;
        }
    }

    cout << "답 " << time;


}

