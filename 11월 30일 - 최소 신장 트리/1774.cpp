//
// 1774번 - 우주신과의 교감
//

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <tuple>


using namespace std;
typedef pair<int, int> ii;
typedef tuple<double, int, int> tp;

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


double kruskal(priority_queue<tp, vector<tp>, greater<>> &pq) {

    int cnt = 0;
    double sum = 0;

    while (!pq.empty()) {

        double weight = get<0>(pq.top());
        int from = get<1>(pq.top());
        int to = get<2>(pq.top());
        pq.pop();

        if (unionInput(from, to)) {
            cnt++;
            sum += weight;
        }

    }

    return sum;

}


int main() {

    int n, m;

    cin >> n >> m;


    vector<ii> god(n + 1, {0, 0});
    parent.assign(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        cin >> god[i].first >> god[i].second;
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        unionInput(a, b);//둘은 이미 이어져있음
    }

    priority_queue<tp, vector<tp>, greater<>> pq;

    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {

            if (findParent(i) == findParent(j)) continue;//이미 이어져 있으면 구하지 않음

            double x = god[i].first - god[j].first;
            double y = god[i].second - god[j].second;

            pq.push(make_tuple(sqrt(x * x + y * y), i, j));

        }
    }

    cout << fixed;
    cout.precision(2);
    cout << kruskal(pq);

}
