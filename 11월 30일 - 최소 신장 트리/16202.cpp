//
// 16202번 - MST게임
//

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

typedef tuple<int, int, int> tp;
vector<int> parent;
deque<tp> q;


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

int kruskal(int v) {

//    pair<int, int> ans;
//    ans.first = -1;
//    ans.second = 0;

    int cnt = 0, sum = 0;
    bool flag = false;//mst가능 여부

    int len = q.size();

    while (len--) {//길이만큼 돌면서
        int weight = get<0>(q.front());
        int from = get<1>(q.front());
        int to = get<2>(q.front());
        q.pop_front();//작은 순서대로 저장되어 있으므로 앞부터 사용

        q.push_back({weight, from, to});//재활용 (뒤로 넣어주기)

        if (unionInput(from, to)) {
            cnt++;
            sum += weight;
            if (cnt == 1) q.pop_back();//첫번째꺼는 재활용 x(뒤에 넣은거 뺴기)
        }

        if (cnt == v - 1) flag = true;//mst제작가능

    }

    if (flag) return sum;
    return -1;//mst제작 불가

}


int main() {

    int n, m, k;
    cin >> n >> m >> k;

    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        q.push_back({i, a, b});//i가 작은게 앞으로오게
    }


    while (k--) {


        parent.assign(n + 1, -1);//초기화
        int res = kruskal(n);

        //최소 신장 트리를 만들 수 없을 때 연속으로 0을 출력
        if (res == -1) {
            cout << 0 << " ";
            while (k--) {
                cout << 0 << " ";
            }
            return 0;

        }

        //MST값 출력
        cout << res << " ";


    }


}