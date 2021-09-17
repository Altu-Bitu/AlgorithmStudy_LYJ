//
// Created by 이유정 on 2021/09/15.
//

#include <iostream>
#include <deque>
#include <string>
#include <vector>

// 다 안품!
// 대체 출력형식 어캐하는거지..
//


using namespace std;

deque<string> dq;
vector<string> ans;
vector<string> res;
bool flag = true; // true: front / false : back




void insert_dq(string str) {
    // index : 0 , length()-1은 제외  [ ] 임
    // ,이 나올떄까지 범위만큼


    int start = 1, cnt = 1;
    string number;

    for (int i = 1; i < str.length(); i++) {

        char c = str[i];

//        cout << " c : " << c << "\n";
//        cout << "start : " << start << " end : " << cnt << "\n";


        if (c == ',' || c == ']') {
//            cout << " c is ," << "\n";
            //index start-end까지를 int로 dq에 push

            number.append(str, start, cnt - 1);

//            cout << "number : " << number << "\n";

//            int num = atoi(number.c_str());
            dq.push_back(number);
            number = "";
            //start,end index가 i+1
            start = i + 1;
            cnt = 1;
        } else {
            //end index ++
            cnt++;

        }

    }

//    cout << "==========THIS IS DQ================ " << "\n";
//    while (!(dq.empty())) {
//        cout << dq.front() << " ";
//        dq.pop_front();
//
//    }
//    cout << "\n======================================\n";

}

int solution(string P) {

//    cout << " P : " << P << "\n";
    for (int i = 0; i < P.length(); i++) {

        char c = P[i];

        if (dq.empty()) {
//            cout << "error" << "\n";
            return -1;
        }

        if (c == 'R') {
//            cout << "flag : " << flag;
            flag = !(flag);
//            cout << "flag : " << flag;
        } else {
            if (flag) dq.pop_front();
            else dq.pop_back();
        }

    }
//    return 1;

//    cout << "==========NO ERROR=============== " << "\n";
//    while (!(dq.empty())) {
//        cout << dq.front() << " ";
//        dq.pop_front();
//
//    }
//    cout << "\n======================================\n";

    return 1;

}


int main() {


    int N, M;
    cin >> N;
    string P, str, answer; // P: 수행할 함수 str:리스트


    for (int i = 0; i < N; i++) {
        cin >> P >> M >> str;

        //deque에 삽입하는 함수
//        cout << "INSERT DQ" << "\n";
        insert_dq(str);
        //결과 찾아내는 함수

//        cout << "SOLUTION" << "\n";
        int result = solution(P);

//        cout << "[I] : " << i << " result :" << result << "\n";

        //결과 string벡터 생성ㅇ
        if (result == -1 || M == 0) res.push_back("error");
        else {

            answer.append("[");
            if (flag) {
                while (!(dq.empty())) {
                    answer.append(dq.front());
                    dq.pop_front();
                    answer.append(",");
                }
            } else {
                while (!(dq.empty())) {
                    answer.append(dq.back());
                    dq.pop_back();
                    answer.append(",");
                }
            }
            answer.pop_back();
            answer.append("]");

            res.push_back(answer);

        }
        dq.clear();
        ans.clear();
        answer = "";
        flag = true;

    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << "\n";
    }


}