//
// 1613번 - 역사
// ASP - 플로이드-워셜
// 선후 관계만 중요하므로, 거리를 구하지 않아도 됨

#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e5 * 5 + 1; //edge의 최대수 이상

//플로이드-워셜
void floydWarshall(int vertex, vector<vector<bool>> &graph) {

    for (int i = 1; i <= vertex; i++) { //필수로 거쳐가야 하는 정점
        for (int j = 1; j <= vertex; j++) { // 시작 정점
            for (int k = 1; k <= vertex; k++) { // 도착 정점
                if (graph[j][i] && graph[i][k]) //j->i 가 선행이 사실이고, i -> k 선행이 사실이면,
                    graph[j][k] = true;//j->k의 선행이 사실임
            }
        }
    }

}


int main() {
    cin.tie(NULL); //cin , cout의 묶음을 풀어줌
    ios_base::sync_with_stdio(false); //c, c++버퍼를 분리


    int n, k;// n:vertex의 수  k : edge의 수
    cin >> n >> k;

    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false)); //선후 관계 여부
    for (int i = 1; i <= n; i++) //자기 자신과의 거리
        graph[i][i] = true;//자기 자신으로는 언제나 true

    int u, v;
    while (k--) {
        cin >> u >> v;
        graph[u][v] = true;//u->v관계 성립

    }

    floydWarshall(n, graph);


    int num;
    cin >> num;
    while (num--) {
        cin >> u >> v;

        if (graph[u][v])//u가 선행
            cout << -1 << "\n";
        else if (graph[v][u])//v가 선행
            cout << 1 << "\n";
        else
            cout << 0 << "\n";


    }

}