//분할 정복
// ⚾
//
// 구글링 : c++ 순열 만들기 / next_permutation
// https://twpower.github.io/82-next_permutation-and-prev_permutation

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
vector<vector<int>> v; //각이닝별 타자의 결과
deque<int> dq; //1~9까지 타자의 순서

vector<bool> state(5);// 1,2,3,4 루 상태 (0은 타석)이라고 가정
int score = 0;
int out_cnt;
int max_score = -1;
vector<int> check = {2, 3, 4, 5, 6, 7, 8, 9};//1번선수 제외

//홈으로 들어왔는지
void is_score() {
    if (state[4] == true) {//4루로 사람이 들어오면 스코어 증가 후 false로 변경
        score++;
        state[4] = false;
    }

}


//홈런
void homeRun() {
    for (int i = 0; i <= 3; i++) { //타석 (0) ~ 3루까지 모든사람검사
        if (state[i] == true) {
            score++;
        }
    }
    fill(state.begin(), state.end(), false);
}

//안타,2루타,3루타
void nHits(int n) {// n=1 : 안타, n=2 :2루타

    for (int i = 1; i <= n; i++) {//n회반복
        for (int i = 3; i >= 0; i--) {
            if (state[i]) {
                state[i + 1] = true;//한칸씩 미루기
                state[i] = false;
            }
        }
        state[0] = false;
        is_score(); //한루씩 전부 전진하면 1점득점했는지 체크
    }
}

void calScore(int n) {

    //점수를 계산
    for (int i = 0; i < n; i++) { //이닝
        while (out_cnt < 3) {
            //차례올떄마다 타자를 타석에 세우는거 해야함
            state[0] = true;

            //지금 순서 타자의 결과 hit에 저장
            int hit = v[i][dq.front()];

            //친 사람은 맨 뒤로 보내기
            dq.push_back(dq.front());
            dq.pop_front();

            if (hit == 0) out_cnt++;
            else if (hit == 4) homeRun();
            else nHits(hit);

            //끝나면 타자가 사라짐(?)
            state[0] = false;
        }

        //초기화 1.out수 초기화 2. state배열 전부 false로
        out_cnt = 0;//0으로 초기화
        fill(state.begin(), state.end(), false);

    }


}


int main() {

    cin.tie(NULL); //cin , cout의 묶음을 풀어줌
    ios_base::sync_with_stdio(false); //c, c++버퍼를 분리

    int n;
    cin >> n; //n이닝


    v.assign(n, vector<int>(10, 0)); //0~9

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> v[i][j];//i이닝의 j번 타자의 결과
        }
    }


    do {

        int i = 0;
        bool flag = false;
        while (i < 8) {
            if (i == 3 && flag == false) {
                dq.push_back(1);
                flag = true;
            }
            dq.push_back(check[i]);
            i++;
        }


        //이번 순서로 점수를 계산
        calScore(n);

        //초기화
        if (score > max_score) max_score = score; //최고점 갱신
        score = 0;
        dq.clear();


    } while (next_permutation(check.begin(), check.end())); //모든 순열을 구함

    cout << max_score;


}