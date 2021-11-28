//
// 20040번 - 사이클 게임
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;


int findParent(int node) {

    if (parent[node] < 0)
        return node; //음수이면, 해당 인덱스가 루트임
    return parent[node] = findParent(parent[node]);

}


bool unionInput(int x, int y) {

    int xp = findParent(x);
    int yp = findParent(y);


    if (xp == yp)//이미 같은 집합에 존재
        return true;//사이클이 생김

    if (parent[xp] < parent[yp]) {//더 작은 이 자식이 많음쪽 -> 루트가 된다
        parent[xp] += parent[yp];
        parent[yp] = xp;
    } else {
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }

    return false;

}


int main() {

    int n, m;

    cin >> n >> m;

    parent.assign(n + 1, -1);//-1로 초기화 (전부 자기자신이 root인 상태)

    int x, y;
    int cnt = 1;
    while (m--) {
        cin >> x >> y;

        bool isCycle = unionInput(x, y);

        if (isCycle) {
            cout << cnt;
            return 0;
        }
        cnt++;
    }

    cout << 0;
    return 0;


}

