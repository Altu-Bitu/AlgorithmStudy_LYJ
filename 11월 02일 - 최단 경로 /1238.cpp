//
// 1238번 - 파티
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ii;

const int INF = 1e5; //최대 V-1개의 간선을 지나게 됨

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

    int n, m, x;

    cin >> n >> m >> x;

    int a, b, c;
    vector<vector<ii>> graph_start(n + 1, vector<ii>(0));
    vector<vector<ii>> graph_end(n + 1, vector<ii>(0));
    while (m--) {
        cin >> a >> b >> c;
        graph_start[a].emplace_back(b, c); // a->b : a를 출발점으로
        graph_end[b].emplace_back(a, c);// a->b : b를 도착점으로
    }


    //각자의 마을에서 x마을로 가기 (SSP반대 -> Single Destination)
    vector<int> party = dijkstra(n, x, graph_end);//vertex수, Destination, graph

    //x마을에서 각자의 집으로 돌아가기 (SSP)
    vector<int> home = dijkstra(n, x, graph_start);//vertex수, Start, graph


    //가장 오래걸리는 사람 -> 오고 가는 시간의 최대값
    int max = 0;
    //출력
    for (int i = 1; i <= n; i++) {
        int sum = party[i] + home[i];
        if (sum > max) max = sum;
    }

    cout << max;

}