//
// 1043번 - 거짓말
//

#include <iostream>
#include <vector>


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


    if (truth[x] || truth[y] || truth[xp] || truth[yp]) {//한명이라도 진실을 알면
        truth[x] = truth[y] = truth[xp] = truth[yp] = true;//모두 진실을 알게됨
    }

    if (xp == yp) {
        return;
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
    truth.assign(n + 1, false);//진실을 모르는 상태로 초기화

    int knower, a, b;


    cin >> knower;//진실을 아는 사람의 수
    for (int i = 0; i < knower; i++) {
        cin >> a;
        truth[a] = true;//진실을 아는 사람들을 표시해둠
    }


    int num;
    vector<int> party;
    party.assign(m, -1);


    for (int i = 0; i < m; i++) {
        cin >> num;
        cin >> a;
        party[i] = a;//첫번째 참여자를 배열에 저장

        for (int i = 1; i < num; i++) {
            cin >> b;
            unionInput(a, b);//첫번째 참여자와 같은 그룹에 넣음
        }

    }

// 파티에 참여한 첫번째 사람을 저장한 배열
//    for (int i = 0; i < m; i++) {
//        cout << party[i] << " ";
//    }
//
//    cout << "\n";
    int ans = 0;

    for (int i = 0; i < m; i++) {
        int node = party[i];//각 파티에 참여한 첫번째 사람
//        cout << i << "번째 파티 첫번째 참여자 : " << node << "\n";
//        cout << "그사람의 루트 " << findParent(node) << "\n";
//        cout << "루트가 진실을 아는가? " << truth[findParent(node)] << "\n";
        if (!truth[findParent(node)]) ans++;//그 사람 집합의 루트가 진실을 모르면 과장가능
    }


//    //진실을 아는지 여부
//    for (int i = 1; i <= n; i++) {
//        cout << truth[i] << " ";
//    }
//
//    cout << "\n";
//    //집합 잘 만들어졌는지
//    for (int i = 1; i <= n; i++) {
//        cout << parent[i] << " ";
//    }

//    cout << "\n";


    cout << ans;


}

