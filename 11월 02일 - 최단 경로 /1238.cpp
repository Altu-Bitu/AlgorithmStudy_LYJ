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
vector<int> dijkstra(int vertex, int start, vector<vector<ii>> &graph) {
    vector<int> dist(vertex + 1, INF);
    priority_queue<ii, vector<ii>, greater<>> pq; //first : 시작점으로부터의 거리, second : 정점



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