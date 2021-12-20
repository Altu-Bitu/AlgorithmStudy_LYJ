//
// 2637번 - 장난감 조립
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> ii;

//위상정렬
vector<int> topologicalSort(int n, int start, vector<int> &indegree, vector<vector<ii>> &graph) {
    queue<ii> q;


    //최초 진입차수가 0 => 기본부품
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) //진입차수가 0이라면
            q.push({i, i});//{노드, 어디서 온 노드인가}
    }

    vector<int> dp(n + 1, 0); //각 idx(부품)을 만들기 위해 start 부품이 몇개나 사용되는지를 저장한 dp배열
    dp[start] = 1;

    while (!q.empty()) {
        int node = q.front().first;//현재 부품
        int pre_node = q.front().second;// 어떤 start부품에서 왔는가
        q.pop();

//        cout << "\n지금의 노드 : " << node;
//        cout << "\n지금의 노드의 부모(?) : " << pre_node;
        for (int i = 0; i < graph[node].size(); i++) { // 현재 부품으로 만드는 모든 다른 부품
            int next_node = graph[node][i].first;

            indegree[next_node]--; //연결된 정점의 진입차수를 1씩 감소
            if (!indegree[next_node]) //연결된 정점의 진입차수가 0이 되었다면
                q.push({next_node, pre_node});

            //다음 부품을 만들기 위한 start부품의 수 +=(누적) 다음 부품이 필요로 하는 현 부품의 수 * 현 부품(node)이 필요로하는 start 부품의 수
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

    //각 기본부품에 대해 dp진행
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) { //진입차수가 0인 부품(기본 부품) 에 대해 각각 진행
            vector<int> idg = indegree; //indegree원본에 변형을 주지 않기 위해

            vector<int> res = topologicalSort(n, i, idg, graph);
            cout << i << " " << res[res.size() - 1] << "\n";//배열의 마지막 칸(최종 부품을 만드는데 사용된 기본부품 i번의 수)

        }
    }


}
