//
// 16202번 - MST게임
//

#include <iostream>
#include <queue>
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

//        cout << i << "번째 턴" << weight << " " << from << " " << to << "\n";

        if (unionInput(from, to)) {
//            cout << "합격\n";
            cnt++;
            ans.second += weight;
            if (cnt == 1) ans.first = weight;//몇번째 간선이었는지
        }

//        cout << "============\n";

        if (cnt == v - 1) return ans;

    }

    return make_pair(-1, -1);

}


int main() {

    int n, m, k;
    cin >> n >> m >> k;


    priority_queue<tp, vector<tp>, greater<>> pq;

    vector<tp> input;

    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        input.push_back({i, a, b});
    }


    while (k--) {
//
//        for (int i = 0; i < input.size(); i++) {
//            cout << get<0>(input[i]) << " " << get<1>(input[i]) << " " << get<2>(input[i]) << "\n";
//        }


//        cout << "============\n";

        parent.assign(n + 1, -1);
        pair<int, int> res = kruskal(n, input);

        if (res.first == -1 && res.second == -1) {
            cout << 0 << " ";
            while (k--) {
                cout << 0 << " ";
            }
            return 0;

        }

        //MST값 출력
        cout << res.second << " ";

        for (int i = 0; i < input.size(); i++) {
            int weight = get<0>(input[i]);
            if (weight == res.first) {
                input.erase(input.begin() + i);//i번째 원소 삭제
            }
        }


    }


}