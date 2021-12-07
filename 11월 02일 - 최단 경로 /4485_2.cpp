//
// 4485번 - 녹색 옷 입은 애가 젤다지?
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ii;
const int INF = 1e5 * 1.5; //최대 V-1개의 간선을 지나게 됨

vector<vector<int>> cave;

//상 하 좌 우
int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, -1, 1};


//다익스트라
// pq는 (거리,정점)이고 graph는 (정점,거리)이다 .. 주의
vector<vector<int>> dijkstra(int vertex, int start) {

    priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<>> pq; //작은 순서대로 정렬 -> (start ~ vertex 거리 ,vertex(위치) )
    vector<vector<int>> dist(vertex + 2, vector<int>(vertex + 2, INF));//cave의 각 칸별 최소거리 계산 [n][n]칸이 정답

    //시작값 큐에 넣기
    dist[start][start] = cave[start][start]; //start to start : 0
    pq.push({dist[start][start], make_pair(start, start)}); //해당 점까지의 최소 weight, 해당점(x,y)


    while (!pq.empty()) {
        int ux = pq.top().second.first; //x좌표
        int uy = pq.top().second.second; //y좌표
        int w = pq.top().first; // start -> u 까지의 weight
        pq.pop();


        if (w > dist[ux][uy]) continue; //dist[u]가 이미 w보다 작게 설정되었다는 것은 이미 검사된 정점이라는 의미 -> pass

        for (int i = 0; i < 4; i++) { //꺼낸 정점 u와 연결된 정점들 탐색

            //node (ux, uy)의 4방향과 연결된 정점
            int nx = ux + row[i];
            int ny = uy + col[i];

            if (cave[nx][ny] >= 0) {//범위 내에 있음

                int weight = w + cave[nx][ny];
                //새로 구한 값이 원래 저장되어 있는 값보다 작으면 갱신
                if (weight < dist[nx][ny]) {
                    dist[nx][ny] = weight;
                    pq.push({weight, make_pair(nx, ny)});
                }
            }

        }


    }
    return dist;


}

int main() {

    int n;
    int j = 1;
    while (true) {
        cin >> n;
        if (n == 0)break;

        //nxn size vector
        cave.assign(n + 2, vector<int>(n + 2, -1));//테두리 -1로 초기화 하려고

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> cave[i][j];
            }
        }

        vector<vector<int>> res = dijkstra(n * n, 1);
        cout << "Problem " << j << ": " << res[n][n] << "\n"; // 시작정점의 가중치는 무조건 포함되므로 더해서 출력
        j++;


    }


}

