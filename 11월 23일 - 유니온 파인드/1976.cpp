//
// 1976번 - 여행 가자
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int findParent(int node) {

    if (parent[node] < 0)
        return node;
    return parent[node] = findParent(parent[node]);


}


void unionInput(int x, int y) {

    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp)
        return;

    if (parent[xp] < parent[yp]) {

        parent[xp] += parent[yp];
        parent[yp] = xp;

    } else {
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }

}

int main() {

    int n, m;//도시의 수, 여행 할 도시의 수
    cin >> n >> m;

    parent.assign(n + 1, -1);

    int num;
    //도시들 끼리의 연결 정보
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // from i
            // to j
            cin >> num;
            if (num == 1) {
                unionInput(i, j); // 1이면 두 도시가 연결되어 있는 것
            }
        }
    }

    int from, to;
    cin >> from;

    for (int i = 1; i < m; i++) {
        cin >> to;
        if (findParent(from) != findParent(to)) { //from - to 도시가 연결되어 있는지 확인
            cout << "NO";
            return 0;
        }
        from = to;
    }

    cout << "YES";

}
