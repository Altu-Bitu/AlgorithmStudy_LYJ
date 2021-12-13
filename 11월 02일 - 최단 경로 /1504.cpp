//
// 1504번 - 특정한 최단 경로
//

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const int INF = 1e7 * 2;

//플로이드-워셜
void floydWarshall(int vertex, vector<vector<ll>> &graph) {
    for (int i = 1; i <= vertex; i++) { //필수로 거쳐가야 하는 정점
        for (int j = 1; j <= vertex; j++) { // 시작 정점
            for (int k = 1; k <= vertex; k++) { // 도착 정점
                int cost = graph[j][i] + graph[i][k]; // j->i->k
                if (cost < graph[j][k])//원래 j->k로 가는 값보다 더 작으면 갱신
                    graph[j][k] = cost;
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, e;
    cin >> n >> e;

    vector<vector<ll>> graph(n + 1, vector<ll>(n + 1, INF));
    for (int i = 1; i <= n; i++) //자기 자신과의 거리
        graph[i][i] = 0;

    int a, b, c;
    while (e--) {
        cin >> a >> b >> c;
        //양방향 그래프 이므로
        graph[a][b] = min(graph[a][b], (ll) c);
        graph[b][a] = min(graph[b][a], (ll) c);
    }

    //플로이드 워셜을 이용해 ASP구하기
    floydWarshall(n, graph);

    //꼭 거쳐야 하는 지점
    int p1, p2;
    cin >> p1 >> p2;

    //p1 -> p2를 지나가기만 하면 되는 거라 순서는 상관없음
    ll ans = graph[1][p1] + graph[p1][p2] + graph[p2][n];
    ll ans2 = graph[1][p2] + graph[p2][p1] + graph[p1][n];

    //경로가 없음(INF이상)
    if (ans >= INF) cout << -1;
    else cout << min(ans, ans2); //경로 존재시 둘중 더 작은값


}