//
// 2637번 - 장난감 조립
//

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>

using namespace std;
typedef pair<int, int> ii;

//위상정렬
vector<int> topologicalSort(int n, int start, vector<int> &indegree, vector<vector<ii>> &graph) {
    vector<int> result;
    queue<ii> q;


    //최초 진입차수가 0 => 기본부품
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) //진입차수가 0이라면
            q.push({i, i});
    }

//    q.push({start, start});

    vector<int> dp(n + 1, 0);
    dp[start] = 1;
//    for (int i = 1; i <= q.size(); i++) {
//        dp[i][i] = 1;
//    }

    while (!q.empty()) {
        int node = q.front().first;
        int pre_node = q.front().second;
        q.pop();

        result.push_back(node); //형재 정점 순서에 삽입
//        cout << "============================\n";
//        cout << "\n지금의 노드 : " << node;
//        cout << "\n지금의 노드의 부모(?) : " << pre_node;
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
//            cout << "\n지금의 노드와 연결된 노드 " << i << "번 : " << next_node;
            indegree[next_node]--; //연결된 정점의 진입차수를 1씩 감소
            if (!indegree[next_node]) //연결된 정점의 진입차수가 0이 되었다면
                q.push({next_node, pre_node});

//            cout << "\ndp[" << pre_node << "][" << next_node << "] += graph[" << node << "][" << i << "].second * dp["
//                 << pre_node << "][" << node << "]\n";
            dp[next_node] += graph[node][i].second * dp[node];//second (몇개 필요한지)
//            cout << dp[next_node] << " += " << graph[node][i].second << " * " << dp[node] << "\n";
        }
    }


    return dp;
}


int main() {

    int n, m;
    cin >> n >> m;


    vector<int> indegree(n + 1, 0); //각 정점의 진입차수
    vector<vector<ii>> graph(n + 1, vector<ii>()); //인접 리스트 그래프



    int a, b, w;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;

        indegree[a]++;
        graph[b].push_back({a, w});

    }

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) { //진입차수가 0이라면
            vector<int> idg = indegree;
            cout << " start : " << i << "\n";
            vector<int> res = topologicalSort(n, i, idg, graph);

            for (int j = 0; j < res.size(); j++) {
                cout << res[j] << " ";
            }

            cout << "\n";

        }
    }

//    vector<vector<int>> res = topologicalSort(n, indegree, graph);

//    cout << "\n";
//    for (int i = 0; i < res.size(); i++) {
//
//
//        for (int j = 0; j < res[i].size(); j++) {
//            cout << res[i][j] << " ";
//        }
//
//        cout << "\n";
//
//    }
//
//    cout << "\n";

//    for (int i = 0; i < res1.size(); i++) {
//        cout << res1[i].second << " ";
//    }


}
