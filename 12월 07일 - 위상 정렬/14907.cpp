//
// 14907번 - 프로젝트 스케쥴링
//

#include <iostream>
#include <vector>
#include <queue>

#define SIZE 26

using namespace std;


//위상정렬 + DP
int topologicalSort(vector<int> &delay, vector<int> &indegree, vector<vector<int>> &graph) {
//    vector<int> result;
    queue<int> q;
    vector<int> dp(SIZE, 0); //각 테스크에 걸린 시간 dp
    int ans = 0;

    for (int i = 0; i < SIZE; i++) {
        dp[i] = delay[i]; //dp 배열 초기화
        if (indegree[i] == 0) //진입차수가 0이라면 && 존재하는 정점
            q.push(i);
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        ans = max(ans, dp[node]);
//        result.push_back(node); //현재 정점 순서에 삽입
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i];
            indegree[next_node]--; //연결된 정점의 진입차수를 1씩 감소
            if (!indegree[next_node]) //연결된 정점의 진입차수가 0이 되었다면
                q.push(next_node);

            //다음 정점의 최소 시간 계산 -> 이어진 전 정점(현재 정점) 중 가장 긴 시간이 걸리는 프로젝트를 선택
            dp[next_node] = max(dp[next_node], dp[node] + delay[next_node]);
        }
    }

//
//    for (int i = 0; i < result.size(); i++) {
//        cout << result[i] << " ";
//    }
//
//    cout << "===========";
    return ans; //result에서 가장 마지막순서로 진행되는  프로젝트의 dp값
}


int main() {

    vector<int> indegree(SIZE, 0); //진입차수
    vector<vector<int>> graph(SIZE, vector<int>(0)); //그래프
    vector<int> delay(SIZE, 0); //건설에 걸리는 시간


    char proj;
    int time;
    string str;


    int k = 0;
//    while (k != 6) {
    while (getline(cin, str)) {
//        getline(cin, str);
//
        proj = str[0];
//        if (indegree[proj - 'A'] == -1) indegree[proj - 'A'] = 0;

//        cout << " length : " << str.length() << "\n";
//
//        cout << "proj : " << proj << "\n";

        int start = 2;
        string tmp = "";
        for (int i = 2; i < str.length(); i++) {

            if (str[i] == ' ') {
                start = i;//time이 끝난 지점
                break;
            }

            tmp += str[i];

        }

        time = stoi(tmp);
        delay[proj - 'A'] = time;//proj 마감에 소요되는 시간

//        cout << "time : " << time << "\n";


//        cout << " graph : ";

        if (start + 1 < str.length()) {
            for (int j = start + 1; j < str.length(); j++) {
//            cout << str[j] << " ";
                indegree[proj - 'A']++;
                graph[str[j] - 'A'].push_back(proj - 'A');
            }
        }

        k++;

    }


//    cout << "\ndelay\n";
//    for (int i = 0; i < SIZE; i++) {
//
//        cout << delay[i] << " ";
//
//    }
//
//    cout << "\nindegree\n";
//    for (int i = 0; i < SIZE; i++) {
//
//        cout << indegree[i] << " ";
//
//    }
//
//
//    cout << "\ngraph\n";
//    for (int i = 0; i < SIZE; i++) {
//
//        cout << "[ " << i << " ] -> ";
//        for (int j = 0; j < graph[i].size(); j++) {
//            cout << graph[i][j] << " -> ";
//        }
//        cout << "\n";
//
//    }

    cout << topologicalSort(delay, indegree, graph);

}