//
// 15681(2) - 트리와 쿼리
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> subtree_cnt;

int treeDp(int cur, vector<vector<int>> &graph) {
    if (subtree_cnt[cur] != -1) //이미 탐색했던 상태
        return subtree_cnt[cur];// 결과를 반환

    //서브트리에 속한 정점의 수를 세고, 저장
    subtree_cnt[cur] = 0;// 최초로는 0개
    int node = 1;//자기 자신이 포함됨
    for (int i = 0; i < graph[cur].size(); i++)//연결된 관계 탐색
        node += treeDp(graph[cur][i], graph); //탐색 결과를 정점의 수에 더함
    return subtree_cnt[cur] = node;//연결된 관계를 모두 고려했으면 subtree_cnt에 저장
}

/**
 * PPT 트리의 정점의 수 구하기 응용
 *
 * 1. 루트에서부터 dfs 탐색
 * 2. 각 노드를 루트로 하는 서브트리의 정점 수를 재귀적으로 계산
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, q, u, v, input;

    //입력
    cin >> n >> r >> q;
    vector<vector<int>> graph(n + 1, vector<int>(0));
    subtree_cnt.assign(n + 1, -1);//각 정점을 루트로 하는 서브트리의 정점의 수를 저장하는 배열 (-1로 초기화)

    while (--n) { //무방향 그래프
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    //연산
    treeDp(r, graph);

    //출력
    while (q--) {
        cin >> input;
        cout << subtree_cnt[input] << '\n';
    }
}