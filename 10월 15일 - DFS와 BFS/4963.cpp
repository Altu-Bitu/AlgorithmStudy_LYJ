//
// 4963번 - 섬의 개수
//

/*
 * 하드 코딩된 부분이 많음
 * 1의 갯수를 찾는데 O(n^2)의 시간 복잡도가 소요!
 *
 * + visited 배열을 사용하지 않고, 섬(1)->바다(0)로 변경하면 효율적
 * 4963_2 참고
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
typedef pair<int, int> ii;

vector<vector<int>> map;
vector<vector<bool>> visited;

int dfs(vector<vector<int>> map, int w, int h, int cnt) {
    int ans = 0;

    stack<ii> s;

    //상 하 좌 우 (대각선 : (좌상) (우상) (좌하) (우하)
    int row[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int col[8] = {0, 0, -1, 1, -1, 1, -1, 1};


    while (cnt > 0) { //1의 개수가 전부 소모되면 종료


        //이어진 섬을 탐색하기 위해 최초 시작점을 stack에 삽입하기
        bool detectOne = false; //이중 for문을 빠져나가기 위한 변수 (1을 찾아냈는지 표시)
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (!visited[i][j] && map[i][j] == 1) { //방문하지 않은 곳 중 1인 곳( 탐색 시작점 ) -> 찾아내기
                    s.push(ii(i, j));//스택에 삽입
                    visited[i][j] = true;// 방문표시
                    detectOne = true;//1을 찾아냄
                    cnt--; //1의 갯수감소
                    break;
                }
            }
            if (detectOne == true) break;
        }


        //위에서 찾아낸 시작점과 연결된 부분을 dfs로 탐색함
        while (!s.empty()) {
            int r = s.top().first;
            int c = s.top().second;
            visited[r][c] = true;// 방문표시 -> dfs에서는 스택에서 빠져나왔을 때 방문표시
            s.pop();

            //상하좌우 대각선 차례로 방문
            for (int i = 0; i < 8; i++) {
                int nr = r + row[i];
                int nc = c + col[i];

                if (!visited[nr][nc] && map[nr][nc] == 1) { //해당 지점이 1이며, 방문한적이 없을 떄
                    s.push(ii(nr, nc));//스택에 위치를 삽입
                    cnt--;// 1의 갯수 감소
                }

            }


        }
        ans++;// 섬의 갯수 증가
    }


    return ans;
}

int main() {


    int w, h;

    while (true) {
        cin >> w >> h; //지도 (너비, 높이)

        if (w == 0 && h == 0) break;

        int cnt = 0; //1의 갯수
        int num;
        map.assign(h + 2, vector<int>(w + 2, -1)); //테두리 -1로 넣어두기
        visited.assign(h + 2, vector<bool>(w + 2, false)); //방문 여부
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> num;
                map[i][j] = num;
                if (num == 1) cnt++; //총 1의 갯수를 count
            }
        }

        cout << dfs(map, w, h, cnt) << "\n";


    }

}

