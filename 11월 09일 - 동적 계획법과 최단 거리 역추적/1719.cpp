//
// 1719번 - 택배 2
//


#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e5 * 2; //최대 n-1개의 간선을 지나게 됨

//최초 경로를 함께 저장하는 플로이드-워셜 수행
void floydWarshall(int n, vector<vector<int>> &graph, vector<vector<int>> &table) {
    for (int k = 1; k <= n; k++) {//거쳐야하는 정점
        for (int i = 1; i <= n; i++) {//시작 정점
            for (int j = 1; j <= n; j++) {// 도착 정점
                int new_dist = graph[i][k] + graph[k][j]; //중간에 k를 거쳐서 i에서 j로 감
                if (new_dist < graph[i][j]) { //i->k->j가 i->j보다 빠른 경로라면
                    graph[i][j] = new_dist; //더 낮은 금액으로 갱신
                    table[i][j] = table[i][k]; //경로(바로 다음 정점)저장 // i->j보다 i->k->j가 더 빠르므로, i->k table로 변경
                }
            }
        }
    }
}

/**
 * graph : 플로이드-워셜 결과 행렬 그래프
 * table : 경로표. table[i][j] = i->j로 가기 위해 제일 먼저 거쳐야 하는 정점
 *
 * 1. i->j의 중간 경로를 i로 초기화
 * 2. i->k->j가 i->j보다 짧다면 i->j의 중간 경로를 i->k의 중간 경로(table[i][k])로 갱신
 *    k로 갱신하는게 아니라 table[i][k]로 갱신하는 이유는?
 *    만약 i->k의 경로가 i->t->k라면 최종 경로는 i->t->k->j
 *    바로 k로 갱신하면 t를 놓칠 수 있기 때문에 table[i][k]로 갱신
 *    line 16을 table[i][j] = k로 바꾸면 결과가 어떻게 되는지 확인해보세요
 */
int main() {
    int n, m, s, d, c; //n : 집하장의 수(vertex), m : 경로의 수(edge), a : 출발 집하장 , b : 도착 집하장 , c : cost

    //입력
    cin >> n >> m;//vertex, edge의 수
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));// 플로이드 -워셜의 결과 행렬
    vector<vector<int>> table(n + 1, vector<int>(n + 1, 0));// i->j로가는 경로의 i바로 이후의 정점
    for (int i = 1; i <= n; i++)//자기 자신으로 가는 경로 초기화
        graph[i][i] = 0;//자기자신으로 가는 경로는 cost = 0

    while (m--) { //무방향 그래프(edge의 수 만큼 반복)
        cin >> s >> d >> c;//시작지, 도착지, 금액
        //간선 정보
        graph[s][d] = graph[d][s] = c;//무방향 그래프이므로

        //경로 정보
        table[s][d] = d; // s->d경로이므로, s다음은 d
        table[d][s] = s; // d->s경로이므로, d다음은 s
    }

    //연산
    floydWarshall(n, graph, table);//플로이드 워셜 수행

    //출력
    for (int i = 1; i <= n; i++) { //시작정점 (1~n까지)
        for (int j = 1; j <= n; j++) {//도착정점 (1~n까지)
            if (i == j)//시작==도착정점인 경우
                cout << "- ";// - 출력
            else//나머지 경우
                cout << table[i][j] << ' ';//최초로 방문하는 경로 출력
        }
        cout << '\n';//한 row마다 줄바꿈
    }
}
