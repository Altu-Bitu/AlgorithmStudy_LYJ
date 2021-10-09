//
// 부등호
//

#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 10;

int k;
vector<char> v(SIZE);//operator 저장
vector<int> num(SIZE);//백트래킹중 답을 저장할 배열 (최대 0~9)
vector<int> num_list(SIZE);//백트래킹에 사용될 숫자 (최대 0~9)
vector<bool> check(SIZE);//0~9
bool is_end = false;

bool compare(char c, int a, int b) {

    if (c == '>') {
        return a > b;
    } else if (c == '<') {
        return a < b;
    }
}


void backtracking(int cnt) {//사용할 숫자 리스트는 한정되어 있음, 배치만하면됨

    //두개의 if문의 순서가 틀리면 오답 -> k+1일떄도 먼저 검사가 진행되어서 오답인지 확인해야함

    if (cnt > 1 && !compare(v[cnt - 2], num[cnt - 2],
                            num[cnt - 1])) //num에 들어간 숫자 2개 이상이어야 비교 가능, 이미 들어간 두개의 수를 비교해야해서 cnt-2, cnt-1
        return; //오답이라서 탈출
    if (cnt == k + 1) {//숫자 k+1개 다쓰면 종료
        is_end = true;//(진 탈출 조건)
        return;
    }


    for (int i = 0; i <= k; i++) {
        //사용 ㄴㄴ
        if (!check[num_list[i]]) {
            //다음 칸에 삽입
            num[cnt] = num_list[i];
            check[num_list[i]] = true;

            backtracking(cnt + 1);
            if (is_end) return;//진 탈출 조건을 만족하면 진짜로 끝

            //원상복귀
            check[num_list[i]] = false;
            num[cnt] = 0;

        }

    }

}


string arrToString(vector<int> &arr) {

    string ans;
    for (int i = 0; i <= k; i++) {
        ans += to_string(arr[i]);
    }

    return ans;
}


int main() {

    string maxString, minString;

    cin >> k;

    //연산자 입력받기 (k개)
    for (int i = 0; i < k; i++) {
        cin >> v[i];
    }


    //최댓값에 사용될 숫자목록(9부터 k+1개)
    for (int i = 0; i <= k; i++) {
        num_list[i] = 9 - i;
    }
    backtracking(0); //해당 숫자목록을 이용해서 백트래킹 진행
    maxString = arrToString(num);//정답을 string으로


    //초기화
    check.assign(SIZE, false);
    num.assign(SIZE, 0);
    is_end = false;


    //최댓값에 사용될 숫자목록(9부터 k+1개)
    for (int i = 0; i <= k; i++) {
        num_list[i] = i;
    }
    backtracking(0); //해당 숫자목록을 이용해서 백트래킹 진행
    minString = arrToString(num);//정답을 string으로


    cout << maxString << "\n";
    cout << minString;


}