//
// 1713번 - 후보 추천하기
//

#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef tuple<int, int, int> tp;

vector<pair<int, int>> vote;


/*
 * 후보를 추가하려고 함
 *
 * 1. 사진 칸이 다 참
 *      1) 새로운 후보 인 경우
 *          - 사람을 삭제하고 넣기
 *
 *      2) 이미 사진칸에 있는 후보인 경우
 *          - 단순히 ++
 *
 * 2. 사진 칸이 다 차지 않음
 *      1) 새로운 후보 인 경우
 *          - 그냥 넣기
 *
 *      2) 이미 사진칸에 있는 후보인 경우
 *          - 단순히 ++
 *
 */

struct compare {
    bool operator()(const tp &a, const tp &b) {

        if (get<1>(a) != get<1>(b))
            return get<1>(a) > get<1>(b);//투표수 적은게 앞

        return get<2>(a) > get<2>(b);//더 오래된(작은수)사진이 앞
    }
};


int leastPick() {//더 적은 인간을 리턴함

    priority_queue<tp, vector<tp>, compare> pq;

    for (int i = 1; i <= 100; i++) {

        if (vote[i].second == -1) continue;//거론된적도 없는 사람
        pq.push({i, vote[i].first, vote[i].second});

    }

//    while (!pq.empty()) {
//        cout << get<0>(pq.top()) << "\n";
//        pq.pop();
//    }

    return get<0>(pq.top()); //퇴출되어야 하는 후보

}


int main() {

    int n, m; //사진틀, 학생의 추천횟수
    cin >> n >> m;

    vote.assign(101, {0, -1});

    int pick, cnt = 0;


    for (int i = 0; i < m; i++) {
        cin >> pick;


        //해당 후보가 이미 존재하는 후보인지 확인
        if (vote[pick].first != 0) {
//            cout << pick << "은 이미 존재하는 후보입니다.\n";
            vote[pick].first++;

            continue;
        }

        //존재하는 후보가 아님
        if (cnt >= n) {//사진 칸이 다참
//            cout << "사진 칸이 전부 차있다\n";

            //교체될 사람을 찾아내기
            int min_pick = leastPick();

//            cout << min_pick << "후보를 내쫓는다\n";
            //교체될 사람을 그냥 초기화 해버리기
            vote[min_pick].first = 0;
            vote[min_pick].second = -1;

        }


//        cout << "새로운 사람 " << pick << "을 추가한다\n";
        //새로운 사람을 넣기
        vote[pick].first++; //투표수 증가
        vote[pick].second = i;// 처음언급된 시간을 표시
        cnt++;


//        for (int j = 0; j < 101; j++) {
//            cout << " [ " << j << " ] " << vote[j].first << " " << vote[j].second << "\n";
//        }


    }

//    for (int j = 0; j < 101; j++) {
//        cout << " [ " << j << " ] " << vote[j].first << " " << vote[j].second << "\n";
//    }

    for (int i = 0; i < 101; i++) {
        if (vote[i].second != -1) cout << i << " ";
    }


}

