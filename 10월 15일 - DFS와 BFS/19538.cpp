//
// 19538번 - 루머
//

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <math.h>
//
//using namespace std;
//typedef pair<int, int> ii;
//
//vector<int> ans;//답 배열(각 사람이 믿게된 시간을 저장)
//vector<vector<int>> adj_list;
//queue<ii> q;
//vector<bool> checked;
//
//void bfs() {
//
//    int t_b = 0;
//    queue<ii> tmp;
//
//    while (!q.empty()) {
//        int speaker = q.front().first;//지금 소문을 퍼트리는 사람
//        int t_n = q.front().second;//그사람이 믿기 시작한 시간
//        q.pop();
//
//
//        //시기가 달라지면 반영
//        if (t_b != t_n) {//한번에 반영하는게 그 같은시기에 말하는 사람(소문 믿고있는 사람이 전부다 말해야)이 다 끝나야 반영해야함
//
//            while (!tmp.empty()) {
//                int idx = tmp.front().first;
//                int value = tmp.front().second;
//                tmp.pop();
//                ans[idx] = value;
//                if (value == -1) q.push(ii(speaker, t_n + 1)); //1명이라도 안믿는 주변인이 있으면, 큐에다시 넣기
//            }
//
//        }
//
//        // 매번마다 believer를 계산하는 것은 시간낭비(이미 믿는 사람이 안믿게될 수는 없음)
//        for (int i = 0; i < adj_list[speaker].size(); i++) {//인접리스트 전부 탐색
//
//            int listener = adj_list[speaker][i];
//
//            if (ans[listener] == -1) { //아직 안믿고 있는 사람
//
//                int half = round(adj_list[listener].size() / 2.0);//주변인의 절반
//                int believer = 0; //믿고 있는 사람의 수
//                //자기 주변인이 몇명이나 믿고있는가?
//                for (int j = 0; j < adj_list[listener].size(); j++) {
//                    if (ans[adj_list[listener][j]] != -1) believer++;
//                }
//
//                if (believer >= half) {//지인중 절반 이상이 믿는 중 -> 본인도 믿기 시작
//                    tmp.push(ii(listener, t_n + 1)); //한번에 반영하기 위해 임시로 담아둠
//                    q.push(ii(listener, t_n + 1));
//                }
//
//            }
//        }
//        t_b = t_n; //이전 시간 저장
//
//
//    }
//
//
//}
//
//
//int main() {
//    cin.tie(NULL);
//    ios_base::sync_with_stdio(false);
//
//    int n;//총 사람의 수
//    cin >> n;
//
//    // 연결관계 -> 연결리스트
//    adj_list.assign(n + 1, vector<int>());
//
//    int num;
//    for (int i = 1; i <= n; i++) {
//
//        while (true) {
//            cin >> num;
//            if (num == 0)break;
//            adj_list[i].push_back(num);
//        }
//    }
//
//    int m;
//    cin >> m;//최초 루머 유포자의 수
//
//    ans.assign(n + 1, -1);//1부터 저장하기 위해서 , 모두들 안믿는 상태로 초기화
//
//    //최초 루머 유포자들을 믿는 상태 + 0초로 초기화해둠
//    checked.assign(n + 1, false);
//    while (m--) {
//        cin >> num;
//        ans[num] = 0; //0초 부터 믿기 시작함
//        checked[num] = true;
//        q.push(ii(num, 0));
//    }
//
//    bfs();
//
//    for (int i = 1; i < n + 1; i++) {
//        cout << ans[i] << " ";
//    }
//
//}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(int n, vector<int> init, vector<vector<int>> &adj_list) {
    vector<int> believer(n + 1, 0); //i번 사람의 주변인이 몇명이나 믿고있는지 = believer[i]
    vector<int> ans(n + 1, -1); //몇 분 후에 믿는지(믿기 시작한 시간 저장)

    queue<int> q;

    //최초 유포자들
    for (int i = 0; i < init.size(); i++) {
        ans[init[i]] = 0;
        q.push(init[i]);
    }


    while (!q.empty()) {
        int speaker = q.front(); //루머를 퍼트리는사람(루머를 믿고있는 사람임)
        int t = ans[speaker];
        q.pop();

        for (int i = 0; i < adj_list[speaker].size(); i++) {
            int near = adj_list[speaker][i]; //speaker의 주변인
            believer[near]++;//speaker의 주변인은 speaker를 주변인으로 보유하므로 주변인을 +1해준다


            //speaker의 주변인은 2가지 경우가 가능
            /*
             * 1. 이미 루머를 믿는 사람 -> 아무일도 x
             * 2. 루머를 믿지 않는 사람
             *      1) 주변 지인중 절반 이상이 루머를 믿는 상황 -> 루머를 믿기 시작함
             *      2) 주변 지인중 절반 이하가 루머를 믿는 상황 -> 아무일도 x
             */
            if (ans[near] != -1) //이미 루머를 믿는 사람이라면 넘어감
                continue;
            if (believer[near] >= (adj_list[near].size() + 1) / 2) {
                ans[near] = t + 1;
                q.push(near);
            }

        }


    }


    return ans;
}

int main() {

    int n;
    cin >> n;

    vector<vector<int>> adj_list(n + 1, vector<int>());


    int num;
    for (int i = 1; i <= n; i++) {
        while (true) {
            cin >> num;
            if (num == 0)break;
            adj_list[i].push_back(num);
        }
    }

    int m;
    cin >> m;//최초 유포자의 수
    vector<int> init(m, 0);
    for (int i = 0; i < m; i++)
        cin >> init[i];

    //연산
    vector<int> ans = bfs(n, init, adj_list);

    //출력
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';

    return 0;

}