//
// 2623번 - 음악프로그램
//

#include <iostream>
#include <queue>
#include <vector>


using namespace std;


//위상정렬
vector<int> topologicalSort(int n, vector<int> &indegree, vector<vector<int>> &graph) {
    vector<int> result;
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) //진입차수가 0이라면
            q.push(i);
    }

    while (!q.empty()) {

        if (result.size() > n) {
            vector<int> res(1, -1);
            return res;
        }

        int node = q.front();
        q.pop();

        result.push_back(node); //형재 정점 순서에 삽입
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i];
            indegree[next_node]--; //연결된 정점의 진입차수를 1씩 감소
            if (!indegree[next_node]) //연결된 정점의 진입차수가 0이 되었다면
                q.push(next_node);
        }
    }
    return result;
}


int main() {

    int n, m;
    cin >> n >> m;

    vector<int> indegree(n + 1, 0); //각 정점의 진입차수
    vector<vector<int>> graph(n + 1, vector<int>(0)); //인접 리스트 그래프

    for (int i = 0; i < m; i++) {

        int num, from, to; // i번쨰 매니저가 담당한 가수의 수
        cin >> num;

        cin >> from;
        num--;

        while (num--) {
            cin >> to;

            indegree[to]++;
            graph[from].push_back(to);

            from = to;
        }
    }


    vector<int> res = topologicalSort(n, indegree, graph);

    if (res[0] == -1 || res.size() < n) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << "\n";
    }


}
