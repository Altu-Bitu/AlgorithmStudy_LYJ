//
// 19538번 - 루머
//

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;
typedef pair<int, int> ii;

vector<int> ans;
vector<vector<int>> adj_list;
queue<ii> q;
vector<bool> checked;

void bfs() {

//    int t = 1;

    while (!q.empty()) {
        int speaker = q.front().first;
        int t = q.front().second;//그사람이 믿기 시작한 시간
        q.pop();

//        t++;
        cout << "============================================================================\n";
        cout << " speaker : " << speaker << " time : " << t << "\n";

        queue<pair<int, int>> tmp;
        for (int i = 0; i < adj_list[speaker].size(); i++) {//인접리스트 전부 탐색

            int listener = adj_list[speaker][i];

            cout << "listener : " << listener << "\n";

            if (ans[listener] == -1) { //아직 안믿고 있는 사람
                cout << "현재 listener(" << listener << ")는 아직 믿고있지 않다.\n";
                cout << "listener의 주변인 : " << adj_list[listener].size() << "\n";

                int half = round(adj_list[listener].size() / 2.0);//주변인의 절반
                int believer = 0; //믿고 있는 사람의 수


                //자기 주변인이 몇명이나 믿고있는가?
                for (int j = 0; j < adj_list[listener].size(); j++) {
                    cout << "listener의 주변인 : " << adj_list[listener][j] << " value 상태: " << ans[adj_list[listener][j]]
                         << "\n";

                    if (ans[adj_list[listener][j]] != -1) believer++;
                }

                cout << "believer : " << believer << "\n";

                if (believer >= half) {
                    tmp.push(ii(listener, t + 1));
                    cout << "지인이 절반 이상 믿는 중->본인도 믿기 시작함\n"; //이걸 마지막에 한번에 반영해야함 ㅠ_ㅠ
                    q.push(ii(listener, t + 1));
                } else {
                    tmp.push(ii(listener, -1));
                }
            }
        }

        //한번에 반영하는게 그 같은시기에 말하는 놈(소문 믿고있는 놈이 전부다 말해야)이 다 끝나야 반영해야함...(어캐아는? -> 배열에서 -1이아닌앧르이 몇갠지? cnt로?해야하나? cnt==그갯수가되면 t++해서 저장하고?)
        while (!tmp.empty()) {
            int idx = tmp.front().first;
            int value = tmp.front().second;
            tmp.pop();
            cout << "idx : " << idx << " value : " << value << "\n";
            cout << "한번에 반영하기\n";
            ans[idx] = value;
            if (value == -1) q.push(ii(speaker, t + 1)); //1명이라도 안믿는 주변인이 있으면, 큐에다시 넣기 -> 시간이 문제 ^_^
        }


    }


}


int main() {

    int n;//총 사람의 수
    cin >> n;

    // 연결관계 -> 연결리스트
    adj_list.assign(n + 1, vector<int>());

    int num;
    for (int i = 1; i <= n; i++) {

        while (true) {
            cin >> num;
            if (num == 0)break;
            adj_list[i].push_back(num);
        }
    }

//인접리스트 출력
//    for (int i = 1; i <= n; i++) {
//        cout << "[ " << i << " ]";
//        for (int j = 0; j < adj_list[i].size(); j++) {
//            cout << "->" << adj_list[i][j];
//        }
//        cout << "\n";
//    }

    int m;
    cin >> m;//최초 루머 유포자의 수

    ans.assign(n + 1, -1);//1부터 저장하기 위해서 , 모두들 안믿는 상태로 초기화

    checked.assign(n + 1, false);
    while (m--) {
        cin >> num;
        ans[num] = 0; //0초 부터 믿기 시작함
        checked[num] = true;
        q.push(ii(num, 0));
    }

    bfs();

    for (int i = 1; i < n + 1; i++) {
        cout << ans[i] << " ";
    }

}