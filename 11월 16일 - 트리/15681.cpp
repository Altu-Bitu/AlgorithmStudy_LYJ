//
// 15681번 - 트리와 쿼리
//

#include <iostream>
#include <vector>

using namespace std;

//tree(부모,자식 관계 연결), 현재노드, 부모노드, 첫 입력으로 얻은 그래프관계
void makeTree(vector<vector<int>> &tree, int current, int parent, vector<vector<int>> &graph) {

    for (int i = 0; i < graph[current].size(); i++) {//current에 연결된 것들
        int node = graph[current][i];
        if (node != parent) {//부모가 아니면
            tree[current].push_back(node); //자식 노드로 추가
            makeTree(tree, node, current, graph);//부모를 현재노드로
        }
    }


}

void countSubtreeNodes(int current, vector<int> &size, vector<vector<int>> &tree) {

    for (int i = 0; i < tree[current].size(); i++) {//연결된 자식들
        int node = tree[current][i];
        countSubtreeNodes(node, size, tree);
        size[current] += size[node];
    }

}


int main() {

    cin.tie(NULL); //cin , cout의 묶음을 풀어줌
    ios_base::sync_with_stdio(false); //c, c++버퍼를 분리



    int n, root, q;

    cin >> n >> root >> q;

    vector<vector<int>> graph(n + 1, vector<int>());

    int a, b;
    for (int i = 1; i < n; i++) { //n-1회
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //트리로 표현
    vector<vector<int>> tree(n + 1, vector<int>());
    makeTree(tree, root, -1, graph);

//    for (int i = 1; i <= n; i++) {
//        cout << "[ " << i << " ] -> ";
//        for (int j = 0; j < tree[i].size(); j++) {
//            cout << tree[i][j] << " -> ";
//        }
//        cout << "\n";
//    }

    //size[u] : u 정점으로 시작하는 서브트리의 수를 저장
    vector<int> size(n + 1, 1);//자신도 자신을 루트로하는 서브트리 이므로 모두 1으로 초기화
    countSubtreeNodes(root, size, tree); //root부터 각 노드를 루트로 하는 서브트리의 수 구하기

    int u;
    while (q--) {
        cin >> u;
        cout << size[u] << "\n";
    }

}