//
// 큰 수 만들기
//

/**
 * k개의 수를 지워나가면서 바로바로 큰 수를 만들어나가자
 * 0번 인덱스부터 차례로 검사해서 일단 큰 수에 포함했다가, 커지는 값이 나오면 그 전의 수를 모두 지운다
 * 마지막으로 남은 수열이 원하는 정답인 큰 수가 된다
 * ex) 1924 에서 2개를 지워서 큰 수를 만들어야 한다면
 *     1->9로 넘어가는 순간 1이 지워짐 -> 9는 큰 수에 포함
 *     2->4로 넘어가는 순간 2가 지워짐 -> 4는 큰 수에 포함
 *     94가 최종 정답
 *
 * 이러한 그리디적 풀이가 가능한 이유 -> number의 순서가 고정되어 있기 때문!
 * !주의! 커지는 값이 나와도, 이미 k번 수를 지웠다면 더 이상 지우면 안됨
 * !주의! 마지막까지 검사했는데 k번 지우지 못했다면 마지막 값들을 지워서 k번을 채움
 */


#include <iostream>
#include <string>
#include <deque>

using namespace std;

deque<int> dq;

string solution(string number, int k) {
    string answer = "";

    int cnt = 0; // 제거한 수의 갯수
    int i = 0;//인덱스

    while (i < number.length() && cnt != k) {


        //지금 고려하는 수
        int now = number[i++] - '0'; //int로 전환


        //*주의* !dp.empty()를 먼저 써야함(순서)
        while (!dq.empty() && dq.back() < now) { //나보다 작은거 제거
            dq.pop_back();
            cnt++;//제거한 갯수 증가
            if (cnt == k) break;// k개 도달하면 작아도 break
        }
        dq.push_back(now);//자기자신을 넣기


    }

    // 인덱스가 끝까지 가지 않은 경우 끝까지 덱에 넣기
    while (i < number.length()) {
        dq.push_back(number[i++] - '0'); //int로 변환
    }

    // 제거해야할 갯수가 남지 않은 경우 맨 뒤부터 제거
    while (cnt < k) {
        dq.pop_back();
        cnt++;
    }

    //덱에 있는 수 string으로 만들기
    while (!dq.empty()) {
        answer += dq.front() + '0'; //char로 변환 !
        dq.pop_front();
    }


    return answer;
}

int main() {

    string number;
    cin >> number;

    int k;
    cin >> k;


    cout << solution(number, k);

    return 0;
}