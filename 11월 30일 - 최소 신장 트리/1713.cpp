//
// 1713번 - 후보 추천하기
//

#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

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


int leastVote(int min_pick, int pick) {//더 적은 인간을 리턴함


    //매번 교체될 사람을 갱신해보기
    //가장 적은 표를 받은 학생을 항상 저장해두기
    if (vote[min_pick].first > vote[pick].first) {//표수가 더적으면 갱신
        return pick;
    } else if (vote[min_pick].first == vote[pick].first && vote[min_pick].second > vote[pick].second) {
        return pick;
    }

    return min_pick;


}


int main() {

    int n, m; //사진틀, 학생의 추천횟수
    cin >> n >> m;

    vote.assign(21, {m + 1, m + 1});

    int pick, cnt = 0, min_pick = -1;


    for (int i = 0; i < m; i++) {
        cin >> pick;

        if (i == 0) min_pick = pick;

        cout << i << "회차\n";

        //매번 교체될 사람을 갱신해보기
        //가장 적은 표를 받은 학생을 항상 저장해두기
        if (vote[pick].first != m + 1 && vote[min_pick].first > vote[pick].first) {//표수가 더적으면 갱신
            min_pick = pick;
        } else if (vote[min_pick].first == vote[pick].first && vote[min_pick].second > vote[pick].second) {
            //표수는 같은데, 더오래된애 있으면 갱신
            min_pick = pick;
        }


        cout << "min pick : " << min_pick << "\n";

        //해당 후보가 이미 존재하는 후보인지 확인
        if (vote[pick].first != m + 1) {
            cout << pick << "은 이미 존재하는 후보입니다.\n";
            vote[pick].first++;
            cnt++;
            continue;
        }


        if (cnt >= n) {//사진 칸이 다참
            cout << "사진 칸이 전부 차있다\n";
            cout << min_pick << "\n";
            //교체될 사람을 그냥 초기화 해버리기
            vote[min_pick].first = m + 1;
            vote[min_pick].second = m + 1;

        }


        cout << "새로운 사람을 추가한다\n";
        //새로운 사람을 넣기
        vote[pick].first++; //투표수 증가
        vote[pick].second = i;// 처음언급된 시간을 표시
        cnt++;


        for (int j = 0; j < 21; j++) {
            cout << " [ " << j << " ] " << vote[j].first << " " << vote[j].second << "\n";
        }


/*
 * 2 7 6
 * 2 1 1
 *
 */



    }


//    for (int i = 0; i < 21; i++) {
//        cout << " [ " << i << " ] " << vote[i].first << " " << vote[i].second << "\n";
//    }


}

