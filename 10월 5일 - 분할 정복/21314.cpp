//
// 민겸수
//
// 피드백 : 반례
// MKMMM max - 50111 not 50100
//
//

#include <iostream>
#include <queue>

using namespace std;

queue<char> q;
string max_str;
string min_str;

int main() {

    string mk;

    cin >> mk;

    for (int i = 0; i < mk.length(); i++) {
        q.push(mk[i]);
    }

    //find max
    //K가 나올 때 마다 변환
    char c;
    int num = 0;
    while (!q.empty()) {

        c = q.front();
        q.pop();
        if (c == 'K') {

            max_str += '5';
            if (num > 0) { //쌓인 M의 수 만큼 0붙이기
                for (int i = 0; i < num; i++) {
                    max_str += '0';
                }
            }
            num = 0;
            continue;
        }

        num++;//m의 수


    }

    //남은 것 출력
    //주의! 최댓값이므로 남은 M은 전부 1인것이 크다!
    if (num > 0) {

        for (int i = 0; i < num; i++) { //1이 맨 앞에 붙어서 1개 적은 0의 수
            max_str += '1';
        }
    }


    //find min
    for (int i = 0; i < mk.length(); i++) {
        q.push(mk[i]);
    }

    num = 0;
    while (!q.empty()) {

        c = q.front();
        q.pop();
        if (c == 'K') {

            //모아둔 M출력
            if (num == 1) {
                min_str += '1';
            } else if (num > 0) {
                min_str += '1';
                for (int i = 0; i < num - 1; i++) {
                    min_str += '0';
                }
            }
            num = 0;

            //K붙이기
            min_str += '5';
            continue;
        }

        num++;//m의 수


    }

    //남은 M출력
    if (num == 1) {
        min_str += '1';
    } else if (num > 0) {
        min_str += '1';
        for (int i = 0; i < num - 1; i++) {
            min_str += '0';
        }
    }


    cout << max_str << "\n" << min_str;
}

