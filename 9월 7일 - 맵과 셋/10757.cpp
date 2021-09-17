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

    //string 특성 상 .at 을 사용하면 앞자리 부터 되어서 반전
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());


    int Alen, Blen;
    Alen = A.length();
    Blen = B.length();

    int aa, bb, add_tmp, tmp;
    bool flag = false;


    if (Alen >= Blen) {

        for (int i = 0; i < Blen; i++) {

            aa = A.at(i) - '0'; //char into int
            bb = B.at(i) - '0';

            tmp = aa + bb;

            //carry 존재 여부 반영
            if (flag == true) add_tmp = tmp + 1;
            else add_tmp = tmp;

            // carry 발생 여부 확인
            if (add_tmp >= 10) flag = true;
            else flag = false;

            C.push_back(add_tmp % 10);

        }

        //남은 자리수 계산
        for (int k = Blen; k < Alen; k++) {
            int tmp = A.at(k) - '0';

            if (flag == true) add_tmp = tmp + 1;
            else add_tmp = tmp;

            if (add_tmp >= 10) flag = true;
            else flag = false;

            C.push_back(add_tmp % 10);

        }

        // 계산 후 마지막 남은 carry반영
        if (flag == true) C.push_back(1);

    } else {


        for (int i = 0; i < Alen; i++) {
            aa = A.at(i) - '0';
            bb = B.at(i) - '0';

            tmp = aa + bb;


            if (flag == true) add_tmp = tmp + 1;
            else add_tmp = tmp;

            if (add_tmp >= 10) flag = true;
            else flag = false;

            C.push_back(add_tmp % 10);

        }

        for (int k = Alen; k < Blen; k++) {
            int tmp = B.at(k) - '0';


            if (flag == true) add_tmp = tmp + 1;
            else add_tmp = tmp;

            if (add_tmp >= 10) flag = true;
            else flag = false;

            C.push_back(add_tmp % 10);


        }

        if (flag == true) C.push_back(1);


    }




    //출력 뒤에서 부터
    for (int j = C.size() - 1; j >= 0; j--) {

        cout << C[j];


    }

}