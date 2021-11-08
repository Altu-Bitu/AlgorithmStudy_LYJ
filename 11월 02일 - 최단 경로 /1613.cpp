//
// 1613번 - 역사
// ASP - 플로이드-워셜

#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e5 * 5 + 1; //edge의 최대수 이상

//플로이드-워셜
void floydWarshall(int vertex, vector<vector<int>> &graph) {

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
    cin.tie(NULL); //cin , cout의 묶음을 풀어줌
    ios_base::sync_with_stdio(false); //c, c++버퍼를 분리


    int n, k;// n:vertex의 수  k : edge의 수
    cin >> n >> k;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) //자기 자신과의 거리
        graph[i][i] = 0;

    int u, v;
    while (k--) {
        cin >> u >> v;
        graph[u][v] = 1;

    }

    floydWarshall(n, graph);

//    그래프 제대로 구성되었는지
//    cout << "\n";
//    for (int i = 0; i <= n; i++) {
//        for (int j = 0; j <= n; j++) {
//            if (graph[i][j] == INF) cout << 9 << " ";
//            else cout << graph[i][j] << " ";
//        }
//        cout << "\n";
//    }


    int num;
    cin >> num;
    while (num--) {
        cin >> u >> v;

        if (graph[u][v] > 0 && graph[u][v] < INF)//u가 선행
            cout << -1 << "\n";
        else {
            if (graph[v][u] > 0 && graph[v][u] < INF)//v가 선행
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }

    }

}