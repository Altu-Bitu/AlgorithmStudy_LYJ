//
// 4485번 - 녹색 옷 입은 애가 젤다지?
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ii;


vector<vector<int>> cave;
const int INF = 1e5 * 1.5; //최대 V-1개의 간선을 지나게 됨

//상 하 좌 우
int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, -1, 1};

vector<vector<ii>> makeList(int n) {

    //그래프 번호는
    /*3x3인 경우
     * 1 2 3
     * 4 5 6
     * 7 8 9
     * 이렇게 지정함
     * cave[i][j]의 그래프 번호는
     * i * n - j - n 으로 구할 수 있음
     * =>  n(i-1) * j
     *
     */
    vector<vector<ii>> graph(n * n + 1, vector<ii>(0));


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            //cave[i][j]는 v number를 i*n+j로 지정 -> 상하좌우로 움직였을때 cave[nr][nc]
            //from i*n+j -> to nr*n+nc 's weight cave[nr][nc]

//            cout << "===============================================\n";
//            cout << " i : " << i << " j : " << j << "\n";

            for (int k = 0; k < 4; k++) {
                int nr = i + row[k];
                int nc = j + col[k];
//                cout << " nr : " << nr << " nc : " << nc << "\n";

                if (cave[nr][nc] != -1) {//해당값이 -1이면 테두리이므로 그냥 넘어감
//                    cout << "FROM : " << i * n + j - n << " TO : " << nr * n + nc - n << " W : " << cave[nr][nc]
//                         << '\n';
                    graph[(i - 1) * n + j].emplace_back((nr - 1) * n + nc, cave[nr][nc]);
                }


            }

        }
    }
    return graph;

}

//다익스트라
// pq는 (거리,정점)이고 graph는 (정점,거리)이다 .. 주의
vector<int> dijkstra(int vertex, int start, vector<vector<ii>> &graph) {

    priority_queue<ii, vector<ii>, greater<>> pq; //작은 순서대로 정렬 -> (start ~ vertex 거리 ,vertex )
    vector<int> dist(vertex + 1, INF);//답으로 내보낼 배열 (각 정점별 최소거리)

    //시작값 큐에 넣기
    dist[start] = 0; //start to start : 0
    pq.push({0, start});


    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first; // start -> u 까지의 weight
        pq.pop();


        if (w > dist[u]) continue; //dist[u]가 이미 w보다 작게 설정되었다는 것은 이미 검사된 정점이라는 의미 -> pass

        for (int i = 0; i < graph[u].size(); i++) { //꺼낸 정점 u와 연결된 정점들 탐색
            int node = graph[u][i].first; // u와 연결된 정점
            int weight = w + graph[u][i].second;// start -> u(w) + u -> node(graph[u][i]) = start -> node

            //새로 구한 값이 원래 저장되어 있는 값보다 작으면 갱신
            if (weight < dist[node]) {
                dist[node] = weight;
                pq.push({weight, node});
            }


        }


    }
    return dist;


}


int main() {

    int n;
    int i = 1;
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

//출력해보기
//        for (int i = 0; i <= n + 1; i++) {
//            for (int j = 0; j <= n + 1; j++) {
//                cout << cave[i][j] << " ";
//            }
//            cout << "\n";
//        }

        //v의 수 : n * n
        //e의 수 : n * ( 4 + (n-1)*2 ) = 2n(n+1) -> n칸짜리 line이 사각형 테두리 4개 + 내부 선들 n-1개씩 세로 1개, 가로 1개

        vector<vector<ii>> graph = makeList(n);

        //연산
        vector<int> ans = dijkstra(n * n, 1, graph); //정점의 수 n*n , 시작정점 무조건 1, 인접리스트

        //출력 (마지막 정점)

        cout << "Problem " << i << ": " << ans[n * n] + cave[1][1] << "\n"; // 시작정점의 가중치는 무조건 포함되므로 더해서 출력
        i++;


    }


}

