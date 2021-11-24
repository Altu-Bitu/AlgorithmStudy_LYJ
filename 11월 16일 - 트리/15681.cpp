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

//계산한 각 서브트리의 정점 수를 리턴
int countSubtreeNodes(int current, vector<int> &size, vector<vector<int>> &tree) {

    if (tree[current].size() == 0) return 1;// 기저조건 leaf node임 (자기 자신 1개 return)

    for (int i = 0; i < tree[current].size(); i++) {//연결된 자식들
        int node = tree[current][i];//current node에 연결된 자식들
        size[current] += countSubtreeNodes(node, size, tree);//자식을 current node로 하여, 거기에 연결된 자식을 구함
    }
    return size[current];

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

    // tree 잘 만들어졌는지 확인
//    for (int i = 1; i <= n; i++) {
//        cout << "[ " << i << " ] -> ";
//        for (int j = 0; j < tree[i].size(); j++) {
//            cout << tree[i][j] << " -> ";
//        }
//        cout << "size : " << tree[i].size() << "\n";
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