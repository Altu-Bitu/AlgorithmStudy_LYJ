//
// 14907번 - 프로젝트 스케줄링
//

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>

using namespace std;
typedef pair<int, int> ii;

//위상정렬
vector<int> topologicalSort(int n, vector<int> &indegree, vector<vector<ii>> &graph) {
    vector<int> result(n + 1, -1);
    queue<ii> q;

    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) //진입차수가 0이라면
            q.push({i, 0});
    }
    while (!q.empty()) {
        int node = q.front().first;
        result[node] = q.front().second;
//        result.push_back({node, q.front().second}); //형재 정점 순서에 삽입

        q.pop();

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            indegree[next_node]--; //연결된 정점의 진입차수를 1씩 감소
            if (!indegree[next_node]) //연결된 정점의 진입차수가 0이 되었다면
                q.push({next_node, node});//지금노드, 어디서왔는지
        }
    }
//
//    reverse(result.begin(), result.end());

    return result;
}


vector<int> traceback(int start, vector<int> &route, vector<vector<ii>> &graph) {

    int node = start;

    while (true) {


        node = route[node];//다음 행선지

        if (node == route.size() - 1) {
            break;
        }//끝 노드에 도달


    }

}

int main() {

    int n, m;
    cin >> n >> m;


    vector<int> indegree(n + 1, 0); //각 정점의 진입차수
    vector<vector<ii>> graph(n + 1, vector<ii>()); //인접 리스트 그래프



    int a, b, w;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;

        indegree[b]++;
        graph[a].push_back({b, w});

    }

    vector<int> res1 = topologicalSort(n, indegree, graph);


    for (int i = 0; i < res1.size(); i++) {
        cout << i << "(" << res1[i] << ") ";
    }

    cout << "\n";

//    for (int i = 0; i < res1.size(); i++) {
//        cout << res1[i].second << " ";
//    }


}
