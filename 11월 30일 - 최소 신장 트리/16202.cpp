//
// 16202번 - MST게임
//

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> tp;
vector<int> parent;


int findParent(int node) {

    if (parent[node] < 0)
        return node;
    return parent[node] = findParent(parent[node]);
}

bool unionInput(int x, int y) {

    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp)
        return false;

    if (parent[xp] < parent[yp]) {
        parent[xp] += parent[yp];
        parent[yp] = xp;
    } else {
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }

    return true;
}

pair<int, int> kruskal(int v, vector<tp> &pq) {

    pair<int, int> ans;
    ans.first = -1;
    ans.second = 0;

    int cnt = 0;


    for (int i = 0; i < pq.size(); i++) {
        int weight = get<0>(pq[i]);
        int from = get<1>(pq[i]);
        int to = get<2>(pq[i]);


        if (unionInput(from, to)) {
            cnt++;
            ans.second += weight;
            if (cnt == 1) ans.first = weight;//제일 작은 값이 몇번째 간선이었는지
        }

        if (cnt == v - 1) return ans;

    }

    return make_pair(-1, -1);

}


int main() {

    int n, m, k;
    cin >> n >> m >> k;

    vector<tp> input;

    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        input.push_back({i, a, b});//cost가 순서대로라 pq사용하지 않음
    }


    while (k--) {


        parent.assign(n + 1, -1);//초기화
        pair<int, int> res = kruskal(n, input);

        //최소 신장 트리를 만들 수 없을 때 연속으로 0을 출력
        if (res.first == -1 && res.second == -1) {
            cout << 0 << " ";
            while (k--) {
                cout << 0 << " ";
            }
            return 0;

        }

        //MST값 출력
        cout << res.second << " ";

        //간선하나 제거
        for (int i = 0; i < input.size(); i++) {
            int weight = get<0>(input[i]);
            if (weight == res.first) {
                input.erase(input.begin() + i);//i번째 원소 삭제
            }
        }


    }


}