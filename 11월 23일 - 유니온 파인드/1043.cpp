//
// 1043번 - 거짓말
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> parent;
vector<bool> truth;

int findParent(int node) {

    if (parent[node] < 0)
        return node;
    return parent[node] = findParent(parent[node]);

}

void unionInput(int x, int y) {

    //각각의 부모
    int xp = findParent(x);
    int yp = findParent(y);


    if (xp == yp)
        return;

    if (truth[x] || truth[y]) {//둘중에 한명이라도 진실을 알면
        truth[xp] = truth[yp] = true;//부모도 진실을 알게됨
    }


    if (parent[xp] < parent[yp]) { //더 작은게 자식이 많음(루트가 됨) -> 자식의 수가 음수로 저장되어있어서
        parent[xp] += parent[yp]; //yp의 자식도 xp가 가지게됨
        parent[yp] = xp;
    } else {
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }


}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; //사람의 수, 파티의 수
    cin >> n >> m;
    parent.assign(n + 1, -1);//음수로 초기화
    truth.assign(n + 1, false);

    int knower, a, b;


    cin >> knower;//진실을 아는 사람의 수
    for (int i = 0; i < knower; i++) {
        cin >> a;
        truth[a] = true;//진실을 아는 사람들을 표시해둠
    }


    int num;
    int k = 1;
    int ans = m; //과장된 이야기를 할 수 있는 파티의 수
    while (m--) {
        cin >> num;
        cin >> a;
        if (truth[findParent(a)]) {//진실을 아는사람이 있으면
            ans--;//과장된 이야기 불가능
            
        }

        for (int i = 1; i < num; i++) {
            cin >> b;
            unionInput(a, b);
            if (truth[findParent(b)]) {
                ans--;
                cout << k << "파티\n";
                break;
            }
        }
        k++;
    }

    cout << ans;


}

