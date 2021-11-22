//
// 2011번 - 암호코드
//

/*
 * 우선 경우의 수를 하나씩 찾는 풀이를 생각하셨다면 입력 범위를 다시 봅시다!
 * 이전에 구한 경우의 수의 해답을 활용해야 해요.
 * 또한 숫자를 검사할 때, 항상 1 ~ 26사이인지와 알파벳으로 만들 수 있는 수인지 확인하는 것이 중요해요.
 */

//41%에러

#include <iostream>
#include <vector>

#define SIZE 5000
using namespace std;

vector<long long> dp(SIZE + 1, 0);


int main() {

    string code;

    cin >> code;

    int len = code.length();

    //0으로 시작, 0으로 끝나는? 근데 10,20은 ㄱㅊ음..
    if (code[0] == '0') cout << 0;
    else if (len == 2 && code[1] == '0') {
        int number = stoi(code.substr(0, 2));
        if (number != 20 && number != 10) cout << "0";
        else cout << "1";
    } else {

        dp[0] = 1;
        dp[1] = 1;
        if (stoi(code.substr(0, 2)) <= 26) {
            if (stoi(code.substr(0, 2)) != 10 && stoi(code.substr(0, 2)) != 20)
                dp[1] = 2;
        }

        for (int i = 2; i < len; i++) {
            /*
             * 각 단계는
             * 1자리 or 2자리만 가능
             *
             * 0일때)
             * 1. 1자리 불가능
             * 1. 2자리 중에서도 10,20만 가능
             * 즉, 10,20일떄만 1개 가능
             *
             * 1개 가능 할떄는 진전의 갯수와 동일
             *
             * 나머지)
             * 1. 1자리는 항상 가능
             * 2. 2자리는 26이하면 가능
             *
             * 1개 가능하면, 직전의 수와 동일
             * 2개 가능하면, 직전의 수 + 2칸이전의 수와 동일
             *
             *
             */
            int one = stoi(code.substr(i, 1));
            int two = stoi(code.substr(i - 1, 2));

            cout << "one : " << one << " two: " << two << "\n";

            if (one == 0) {//0일떄,
                if (two != 10 && two != 20) {// 10이나 20이 아니면,
                    cout << 0;//암호화 불가능한 거
                    return 0;//종료
                }
                dp[i] = dp[i - 2]; //
            } else {
                dp[i] = dp[i - 1]; //자기자신(한글자) + 직전까지꺼
                if (two <= 26 && two >= 10) {
                    dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000;//
                }

            }


        }


        cout << dp[len - 1] % 1000000;
    }


}