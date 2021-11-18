//
// 16964번 - DFS 스페셜 저지
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * visited : dfs에서 방문을 한 정점을 표시하기 위해
 * sequence : 입력으로 주어진 DFS의 방문순서(위치)를 저장하기 위해
 *              1 2 4 3 -> sequnce[1] : 1 / sequnce[2] : 2 / sequnce[3] : 4 / sequnce[4] : 3 -> 각 숫자가 입력된 순서
 * result : 입력 순서를 고려하여 dfs방문 순서를 조절하여 구해낸 dfs 결과
 */
vector<int> visited, sequence, result;

bool cmp(const int &i1, const int &i2) {
    return sequence[i1] < sequence[i2];//sequence에 저장된 입력받은 방문순서 오름차순
}

//재귀함수로 dfs 수행
void dfs(int cur, vector<vector<int>> &graph) { //현재 방문 정점, 그래프 연결관계
    visited[cur] = true;//방문 체크
    result.push_back(cur);//방문했으므로, 방문 배열에 넣음
    for (int i = 0; i < graph[cur].size(); i++) {//cur과 연결된 모든 정점에대해
        if (!visited[graph[cur][i]])//방문 이전이면,
            dfs(graph[cur][i], graph);//방문하면서 재귀로 dfs수행
    }
}

//입력받은 순서와 dfs 결과 비교
bool isDfs(vector<int> &route) {
    for (int i = 0; i < route.size(); i++) {//끝까지 탐색
        if (route[i] != result[i])//입력받은 순서 != 답으로 구해낸 순서
            return false;//올바른 방문순서가 아님
    }
    return true;//끝까지 올바르면, 올바른 방문순서임
}

/**
 *  예제 입력 3  -> 예제 입력 3
 *  1 | 2 3        1 | 3 2
 *  2 | 1 4        2 | 1 4
 *  3 | 1          3 | 1
 *  4 | 2          4 | 2
 *
 *  route : 1 3 2 4
 *
 *  알 수 있는 것
 *  1. 1번 정점은 3, 2, 4번 정점보다 먼저 탐색된다.
 *  2. 3번 정점은 2, 4번 정점보다 먼저 탐색된다.
 *  3. 2번 정점은 4번 정점보다 먼저 탐색된다.
 *  -> 정점 i, j의 위치를 x, y라고 할 때, x < y(seqeunce배열)면 정점 i는 정점 j보다 먼저 탐색해야 함(graph로 연결된 순서를 배열함)
 *  -> 위치 관계를 기준으로 정렬
 *
 *  정렬 후 dfs 탐색을 한 결과가 입력된 경로와 같다면 올바른 방문 순서
 */
int main() {
    int n, a, b; // n : 정점의 수, a: 간선의 시작정점 , b : 간선의 도착정점

    //입력
    cin >> n; // 정점의 수 입력받기
    vector<vector<int>> graph(n + 1, vector<int>(0));//그래프 연결관계를 연결리스트로 저장
    vector<int> route(n, 0);//입력으로 주어질 탐색 순서
    visited.assign(n + 1, 0);
    sequence.assign(n + 1, 0);

    for (int i = 1; i < n; i++) { //무방향 그래프
        cin >> a >> b;//간선 시작->끝
        graph[a].push_back(b);// 그래프 관계 (양방향으로 저장)
        graph[b].push_back(a);// 그래프 관계 (양방향으로 저장)
    }
    for (int i = 0; i < n; i++) { //각 정점의 순서 인덱스를 sequence 배열에 저장
        cin >> route[i];//DFS의 방문순서를 입력받아 저장함
        sequence[route[i]] = i;//각 정점이 방문된 순서를 저장하는 sequence배열
    }

    //연산
    // 강 정점의 위치(x<y)를 기준으로 연결 관계(i->j)를 정렬하여 방문순서를 맞춤
    for (int i = 1; i <= n; i++) //sequence 기준(위치) 오름차순 정렬
        sort(graph[i].begin(), graph[i].end(), cmp);//i vertex와 연결된 정점들을 sequence 기준의 오름차순으로 정렬함 (방문순서가 달라짐)
    dfs(1, graph);//(sequence기준 오름차순으로 정렬되어 방문순서가 정해진 상태) dfs진행

    //출력
    cout << isDfs(route); //구해낸 result배열과 입력받은 배열이 동일하면 1아니면, 0
}