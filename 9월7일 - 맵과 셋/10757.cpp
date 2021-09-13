/*
 *
 * 알튜비튜 - 0907
 * 10757번
 * 큰 수 A + B
 *
 * 두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
 *
 * Tip : string으로 변경해야함
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {


    string A, B;
    cin >> A >> B;
    vector<int> C;


    int longer, shorter;
    string long_s, short_s;
    if (A.length() >= B.length()) {
        longer = A.length();
        shorter = B.length();
        long_s = A;
        short_s = B;
    } else {
        longer = B.length();
        shorter = A.length();
        long_s = B;
        short_s = A;
    }

    //string 특성 상 .at 을 사용하면 앞자리 부터 되어서 반전
    reverse(short_s.begin(), short_s.end());
    reverse(long_s.begin(), long_s.end());


    int aa, bb, tmp;
    bool flag = false;


    for (int i = 0; i < shorter; i++) {

        aa = long_s.at(i) - '0'; //char into int
        bb = short_s.at(i) - '0';

        tmp = aa + bb;

        //carry 존재 여부 반영
        if (flag == true) tmp++;
//            else add_tmp = tmp;

        // carry 발생 여부 확인
        if (tmp >= 10) flag = true;
        else flag = false;

        C.push_back(tmp % 10);

    }

    //남은 자리수 계산
    for (int k = shorter; k < longer; k++) {
        int tmp = long_s.at(k) - '0';

        if (flag == true) tmp++;
//            else add_tmp = tmp;

        if (tmp >= 10) flag = true;
        else flag = false;

        C.push_back(tmp % 10);

    }

    // 계산 후 마지막 남은 carry반영
    if (flag == true) C.push_back(1);




    //출력 뒤에서 부터
    for (int j = C.size() - 1; j >= 0; j--) {

        cout << C[j];


    }

}