//
// 11780번 - 플로이드 2
//

#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e7; //최대 n-1개의 간선을 지나게 됨

//역추적
vector<int> back(int s, int x, vector<vector<int>> &path) { //x: 도착점부터
    vector<int> result(0);
    while (x != 0) {//0이면 경로 없음
        result.push_back(x);//도착 지점부터 차례대로 저장해나감
        x = path[s][x]; //다음 경로추적
    }
    return result;//저장된 경로 return
}

//모든 (i, j)쌍의 역추적 결과값
vector<vector<int>> allPath(int n, vector<vector<int>> &path) {
    vector<vector<int>> ans(n * n);//모든 도시별 -> 도시 별 경로를 저장 (즉 도시수*도시수 만큼 존재) , 경로이므로 배열로 저장됨
    for (int i = 1; i <= n; i++) { //시작점(i)
        for (int j = 1; j <= n; j++) { //도착점(j)
            if (!path[i][j])//경로가 존재하지않으면
                continue;// 넘어감
            vector<int> result = back(i, j, path); //경로가 존재하면 역추적함수를 실행하여 결과 벡터배열에 저장
            ans[(i - 1) * n + (j - 1)] = result;// (i-1) * n + (j-1) : 0 ~ n*n-1 번호로 저장해두기 위해서
        }
    }
    return ans; //이차원 벡터으로 답이 저장된 벡터를 반환함
}

//플로이드-워셜
void floydWarshall(int n, vector<vector<int>> &graph, vector<vector<int>> &path) {
    for (int k = 1; k <= n; k++) {//거쳐야 하는 정점
        for (int i = 1; i <= n; i++) {//시작 정점
            for (int j = 1; j <= n; j++) {//도착 정점
                int new_dist = graph[i][k] + graph[k][j]; //중간에 k를 거쳐서 i에서 j로 가는 cost
                if (new_dist < graph[i][j]) { //i->k->j가 i->j보다 빠른 경로라면(cost가 적다면)
                    graph[i][j] = new_dist;//새로운 cost로 갱신
                    path[i][j] = path[k][j]; //경로(가장 마지막 정점) 저장 // i->j보다 i->k->j가 더 빨랐으니 path[k][j]로 갱신되는것
                }
            }
        }
    }
}

/**
 * graph: 플로이드-워셜 결과 행렬 그래프
 * path: 경료표. i->k->j로 갈 때 거치는 가장 마지막 정점. 즉, k와 j의 경로에 저장된 정점 <=> path[i][j] = path[k][j]
 * ans: 모든 (i, j)쌍의 역추적 결과값 저장
 *
 * 1. i->j의 중간 경로를 i로 초기화
 * 2. i->k->j가 i->j보다 짧다면 i->j의 중간 경로를 k->j의 중간 경로(path[k][j])로 갱신
 *    k로 갱신하는 게 아니라 path[k][j]로 갱신하는 이유는?
 *    만약 k->j의 경로가 k->t->j라면 최종 경로는 i->k->t->j
 *    바로 k로 갱신하면 t를 놓치고, 이러면 역추적을 할 수 없기 때문에 항상 j의 바로 전 경로를 저장해야 함
 */

int main() {
    //n : 도시의 수(vertex) , m: 버스의 수(edge) , a : 출발 도시, b: 도착도시, c: a->b로의 비용
    int n, m, a, b, c;

    //입력
    cin >> n >> m;//도시의 수, 버스의 수를 입력받음
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));// 플로이드 -워셜의 결과 행렬
    // INF으로 초기화 : 더 적은 cost로 갱신하기 위해
    vector<vector<int>> path(n + 1, vector<int>(n + 1, 0));// i->j로가는 경로의 j직전의 정점 (마지막 정점을 저장 -> 역추적)
    // 0으로 초기화 : 경로가 없는 경우 0을 출력하기로 했으므로

    for (int i = 1; i <= n; i++) //자기 자신으로 가는 경로 초기화
        graph[i][i] = 0;//자기자신으로 가는 경로는 cost = 0

    while (m--) {
        cin >> a >> b >> c; // 도시 / 비용 입력받기
        graph[a][b] = min(graph[a][b], c); //단방향 그래프, 중복 간선 들어올 수 있음
        path[a][b] = a; //경로 초기화 a->b로 가는 길이니 직전 루트가 a임
    }

    //연산
    floydWarshall(n, graph, path);//플로이드-워셜 수행 : 각 도시별 최소 cost / 각 도시별 마지막 정점을 구함
    vector<vector<int>> ans = allPath(n, path); //각 도시별 마지막 정점을 이용하여, 역추적해서 전체 경로를 알아냄

    //출력
    //1. 플로이드-워셜 i->j로의 최소비용
    for (int i = 1; i <= n; i++) {//1번 row~ n번 row (from)
        for (int j = 1; j <= n; j++)//1번 col~ n번 col (to)
            cout << ((graph[i][j] == INF) ? 0 : graph[i][j]) << ' '; //inf인 경우에 0으로 출력, 아닌경우 cost를 출력
        cout << '\n';//줄바꿈
    }
    //각각의 경로가 거친 도시를 출력
    for (int i = 0; i < ans.size(); i++) { //ans의 size만ㄴ큼 반복
        int size = ans[i].size();//해당 경로에 포함된 도시의 수 (size)
        cout << size << ' ';//출력
        for (int j = size - 1; j >= 0; j--) // 도착 도시부터 저장되어있으므로, 거꾸로 출력)
            cout << ans[i][j] << ' ';//출력
        cout << '\n';//줄바꿈
    }
    return 0;
}