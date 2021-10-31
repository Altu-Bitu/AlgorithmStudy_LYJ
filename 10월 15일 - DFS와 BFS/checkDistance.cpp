//
// 카카오 인턴십 - 거리두기 확인하기 (Level 2)
//

/*
 * 대기실 : 크기 5x5 총 5개
 * 응시자 끼리 거리는 (r1, c1), (r2, c2) 일 때, |r1 - r2| + |c1 - c2| > 2 (2 초과여야함 )
 * 하지만, 파티션으로 막혀 있다면 거리를 지키지 않아도 상관 없음
 *
 * P : 응시자
 * O : 빈 테이블
 * X : 파티션
 *
 * -> 모든 응시자들이 거리 두기를 잘 지키고 있는가 ?
 */



/*
 * 응시자 위치기준으로 3가지가 있음
 *
 * 응시자 P를 기준으로 맨해튼 거리 1,2인경우만 체크
 *
 * O O 3 O O
 * O 2 1 2 O
 * 3 1 P 1 3
 * O 2 1 2 O
 * O O 3 O O
 *
 * 1번 자리에 앉아있으면, 위반이다
 *
 * 2번 자리에 앉은 경우 2번과 P사이 2개에 전부 파티션이 존재하지 않으면 위반이다.
 *
 * 3번 자리에 앉은 경우 그 사이에 파티션이 존재하지 않으면 위반이다.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

queue<ii> appli;
vector<vector<bool>> wall = {5, vector<bool>(5, false)};//5x5를 0으로 초기화
vector<vector<bool>> app = {5, vector<bool>(5, false)};//5x5를 0으로 초기화


void checkRoom(vector<string> v) {

    for (int i = 0; i < v.size(); i++) {
        string line = v[i];
        for (int j = 0; j < 5; j++) {
            if (line[j] == 'P') {
                appli.push({i, j});
                app[i][j] = true;
            } else if (line[j] == 'X')
                wall[i][j] = true;
        }
    }
}

bool isPossible1(int x, int y) {

    //상 하 좌 우
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nr = x + row[i];
        int nc = y + col[i];

        if (nr >= 0 && nr <= 4 && nc >= 0 && nc <= 4) {
            if (app[nr][nc]) return false; //이 방은 방역수칙을 지키지 않음
        }

    }
    return true;//방역 수칙을 지킴


}

bool isPossible2(int x, int y) {

    //상 하 좌 우
    int row[4] = {1, -1, 1, -1};
    int col[4] = {1, -1, -1, 1};


    for (int i = 0; i < 4; i++) {
        int nr = x + row[i];
        int nc = y + col[i];

        if (nr >= 0 && nr <= 4 && nc >= 0 && nc <= 4) {
            if (app[nr][nc]) {

                //둘중에 한쪽이라도 칸막이가 없으면 위반
                if (!wall[nr][nc - col[i]] || !wall[nr - row[i]][nc]) return false;

            }
        }


    }
    return true;//방역 수칙을 지킴


}

bool isPossible3(int x, int y) {

    //상 하 좌 우 2칸
    int row[4] = {2, -2, 0, 0};
    int col[4] = {0, 0, -2, 2};

    //칸막이 확인위치
    int xrow[4] = {1, -1, 0, 0};
    int xcol[4] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nr = x + row[i];
        int nc = y + col[i];
        if (nr >= 0 && nr <= 4 && nc >= 0 && nc <= 4) {

            int xr = x + xrow[i];
            int xc = y + xcol[i];

            //app[nr][nc]에 사람이 있는데, 그사이에 칸막이는 없음
            if (app[nr][nc] && !wall[xr][xc]) return false; //이 방은 방역수칙을 지키지 않음
        }


    }
    return true;//방역 수칙을 지킴


}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    answer.assign(5, 0);


    for (int i = 0; i < 5; i++) {
        bool state = true; //해당 방 정답 상태

        checkRoom(places[i]);//방내부 위치 파악 (파티션/응시자)


//        cout << "ROOM NUMBER : [ " << i << " ]\n";



        //여기서 하기 뭐..체크
        while (!appli.empty()) { // 모든 지원자에 대해서

            ii p = appli.front(); //응시자 한명 꺼냄
            appli.pop();

//            cout << "지원자 위치 : " << p.first << " " << p.second << "\n";


            //1번 ) 상하좌우에 앉아있는 사람이 있는 지 확인
            state = isPossible1(p.first, p.second);
            if (!state) { // 위반했음 -> 종료하고 0
//                cout << "RULE NUMBER 1 Violated\n";
                answer[i] = 0;
                break;
            }

            //2번 ) 대각선 자리에 사람이 있는 경우 파티션이 존재하는 지 확인
            state = isPossible2(p.first, p.second);
            if (!state) {//위반했음 -> 종료하고 0
//                cout << "RULE NUMBER 2 Violated\n";
                answer[i] = 0;
                break;
            }

            //3번 ) 2칸 떨어져 있을 경우 사이에 파티션 있는지 확인
            state = isPossible3(p.first, p.second);
            if (!state) {//위반했음 -> 종료하고 0
//                cout << "RULE NUMBER 3 Violated\n";
                answer[i] = 0;
                break;
            }
        }

//        cout << "CHECK END\n";

        if (state) {
//            cout << "모든 규칙이 지켜짐 \n";
            answer[i] = 1; //상태가 true로 나왔으면 있는게 맞음}
        }

        //appli , wall초기화?
        appli = queue<ii>();//재선언해서 비우기
        wall = {5, vector<bool>(5, false)};//5x5를 0으로 초기화
        app = {5, vector<bool>(5, false)};//5x5를 0으로 초기화

    }


    return answer;
}


int main() {

    //각 배열이 대기실 (총 5개)
    //한 배열의 구조 "POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"
    /*
     * P O O O P
     * O X X O X
     * O P X P X
     * O O X O X
     * P O X X P
     * 이런 느낌 인듯
     */

    vector<vector<string>> places = {{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
                                     {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
                                     {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
                                     {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
                                     {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
    };

    vector<int> res = solution(places);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}

