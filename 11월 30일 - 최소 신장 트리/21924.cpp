//
// 21924번 - 도시건설
//

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> tp;

vector<int> parent;

/*
 * 크루스칼
 */

int findParent(int node) {
    if (parent[node] < 0)
        return node;
    return parent[node] = findParent(parent[node]);

}


bool unionInput(int x, int y) {

    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp)
        return false;//이미 같은 집합에 존재 -> 유니온불가(사이클)

    if (parent[xp] < parent[yp]) {
        parent[xp] += parent[yp];
        parent[yp] = xp;
    } else {
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }

    return true;//유니온 한다

}

int kruskal(int vertex, priority_queue<tp, vector<tp>, greater<>> &pq) {

    int cnt = 0, sum = 0;//사용한 edge수, MST합
    while (!pq.empty()) {//최소 edge의 수 만큼

        int from = get<1>(pq.top());
        int to = get<2>(pq.top());
        int weight = get<0>(pq.top());
        pq.pop();

        if (unionInput(from, to)) { //해당 edge가 MST에 쓰임
            cnt++;//쓰인 edge수 증가
            sum += weight;//MST합에 추가
        }


        if (cnt == vertex - 1) return sum;

    }

    return -1; //MST 합

}


int main() {

    int n, m;//건물의 수(vertex), 도로의 수(edge)
    cin >> n >> m;

    parent.assign(n + 1, -1);

    priority_queue<tp, vector<tp>, greater<>> pq; //priority queue


    int total = 0;

    int from, to, cost;
    while (m--) {
        cin >> from >> to >> cost;
        pq.push(make_tuple(cost, from, to));
        total += cost;
    }


    int save = kruskal(n, pq);


    if (save == -1) {
        cout << -1;
        return 0;
    }
    cout << total - save;

}

