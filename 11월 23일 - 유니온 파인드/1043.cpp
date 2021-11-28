//
// 1043번 - 거짓말
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> parent;


int find(int node) {

    if (parent[node] < 0)
        return node;
    return parent[node] = find(parent[node]);

}

void unionInput(int x, int y) {

    //각각의 부모
    int xp = find(x);
    int yp = find(y);

    if (xp == yp) return;//같은집합이면 합칠 수 없음

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
    parent.assign(n + 1, -1);//음수로 초기


    int knower, a, b;

    //진실을 아는 사람들을 하나의 집합으로 묶음
    cin >> knower;//진실을 아는 사람의 수
    for (int i = 0; i < knower; i++) {
        if (i == 0) {//가장 처음에 입력된 사람
            cin >> a;
        } else {
            cin >> b;
            unionInput(a, b);
        }
    }


    int ans = 0;
    int num, p;
    while (m--) {
        bool flag = false; //진실을 아는사람이 존재하는가
        bool flag2 = false; //과장된 이야기를 아는사람이 존재하는가
        cin >> num;//파티 참여자 수
        queue<int> participant;
        while (num--) {
            cin >> p;

            if (find(p) == find(a)) {//참여자가 진실을 아는 사람
                flag = true;
                continue;
            }

            if (find(p) == find(0)) {//과장된 이야기를 알고 있는 사람
                flag2 = true;
                continue;
            }
            /*
             * 집합이 없는 자 -> 상관없음 (루트가 본인임)
             * 집합이 있는 자 ( 진실을 아는 자 / 과장된 이야기를 아는 자 ) -> 둘이 공존하면 안됨
             *
             * 진실을 아는 자가 존재함 -> 구라불가
             * 과장된 이야기를 아는 자가 존재함 -> 구라 가능
             * 진실을 아는 자와 과장된 이야기를 아는 자가 존재함 -> 구라불가
             * 진실을 아는사람, 과장된 이야기를 아는 사람 둘다 없다 -> 구라가능
             *
             *
             */

            participant.push(p);//진실도, 과장된 이야기도 모르는 사람이면 큐에 넣기
        }

        cout << "BEFORE=============\n";
        for (int i = 0; i < n + 1; i++) {
            cout << parent[i] << " ";
        }
        cout << "\n";

        if (flag && flag2) {
            ans--;//구라를 알아차리는 사람이 생겨남!!
            cout << "구라불가 \n";
            while (!participant.empty()) {
                int ps = participant.front();
                participant.pop();
                unionInput(a, ps);
                cout << "ps 's parent : " << find(ps) << "\n";
            }
        } else if (flag && !flag2) {
            cout << "구라불가 진실만 얘기해야함\n";
            while (!participant.empty()) {
                int ps = participant.front();
                participant.pop();
                unionInput(a, ps);
                cout << "ps 's parent : " << find(ps) << "\n";
            }
        } else {
            cout << "구라가능\n";
            ans++;
            while (!participant.empty()) {
                int ps = participant.front();
                participant.pop();
                unionInput(0, ps);//어쩌피 0번사람 없으니까 여기다 넣자!
                cout << "ps 's parent : " << find(ps) << "\n";
            }
        }

        cout << "AFTER=============\n";
        for (int i = 0; i < n + 1; i++) {
            cout << parent[i] << " ";
        }
        cout << "\n";


    }

    cout << ans;


}

