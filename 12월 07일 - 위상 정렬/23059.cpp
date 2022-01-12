//
// 23059번 - 리그 오브 레게노
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

//위상정렬
vector<string> topologicalSort(int n, map<string, int> &indegree, map<string, vector<string>> &graph) {
    vector<string> result;
    priority_queue<string, vector<string>, greater<string>> q;


    for (auto i = indegree.begin(); i != indegree.end(); i++) {
        if (i->second == 0) //진입차수가 0이라면
            q.push(i->first);
    }

    if (q.empty()) {
        vector<string> res(1, "none");
        return res;
    }

    int before = 0;

    while (result.size() < n) {

        //현재 구매할 수 있는 아이템을 모두 구매 (사전순 - priority queue)
        while (!q.empty()) {
            result.push_back(q.top()); //구매
            q.pop();

        }


        for (int j = before; j < result.size(); j++) {
            string node = result[j];
            for (int i = 0; i < graph[node].size(); i++) {
                string next_node = graph[node][i];
                indegree[next_node]--; //연결된 정점의 진입차수를 1씩 감소
                if (!indegree[next_node]) //연결된 정점의 진입차수가 0이 되었다면
                    q.push(next_node);
            }
        }
        before = result.size();
    }

    //result배열에 모든 정점이 들어갔는데, q에 무언가가 남아있는 경우?
    if (!q.empty()) {

        vector<string> res(1, "none");
        return res;

    }

    return result;
}


int main() {

    cin.tie(NULL); //cin , cout의 묶음을 풀어줌
    ios_base::sync_with_stdio(false); //c, c++버퍼를 분리


    int n;
    cin >> n;


    string a, b;

    map<string, vector<string>> m;//그래프
    map<string, int> indegree;//진입차수

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        m[a].push_back(b);

        indegree[a]++;
        indegree[b]++;
        indegree[a]--;//입력받은 모든 아이템을 indgree map에 넣기위해


    }


    vector<string> res = topologicalSort(indegree.size(), indegree, m);

    if (res[0] == "none" || res.size() < n) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << "\n";
    }




//
//    for (auto i = m.begin(); i != m.end(); i++) {
//
//        cout << i->first << "->";
//        for (int j = 0; j < i->second.size(); j++) {
//            cout << i->second[j] << " ";
//        }
//        cout << "\n";
//
//    }


}
