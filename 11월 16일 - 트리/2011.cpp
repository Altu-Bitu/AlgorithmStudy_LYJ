//
// 2011번 - 암호코드
//

#include <iostream>
#include <vector>

#define SIZE 5000
using namespace std;

vector<long long> dp(SIZE + 1, 0);

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

int decode(string code, int len) {


    if (code[0] == '0') return 0; //0으로 시작하면 변경이 불가
    else if (len == 2 && code[1] == '0') {//2자리 중에는 10,20이 아니면 불가
        string str = code.substr(0, 2);
        if (str != "20" && str != "10") return 0;
        else return 1;//10,20인 경우
    } else {

        //1칸 이전, 2칸 이전을 탐색해야할 일이 존재하므로, 미리 채워둠 -> string 내 i번째에 대한 결과를 dp[i+1]에 저장함
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 1; i < len; i++) {

            string one = code.substr(i, 1);
            string two = code.substr(i - 1, 2);


            if (one == "0") {//0일떄,
                if (two != "10" && two != "20") {// 10이나 20이 아니면,
                    return 0;
                }
                dp[i + 1] = dp[i - 1]; //10,20-> 암호화 가능 (방법이 1가지이므로 2번째 전과 동일하다)
            } else {
                dp[i + 1] = dp[i]; //자기자신(한글자) + 직전까지꺼
                if (two <= "26" && two >= "10") { //10~26사이라면, 총 2가지 방법으로 암호화가 가능 (1번째 전, 2번째 전)
                    dp[i + 1] = (dp[i] + dp[i - 1]) % 1000000; // %1000000이 없으면 중간에 범위를 초과하는 에러(27%)
                }

            }


        }

        return dp[len] % 1000000;

    }
}


int main() {

    string code;

    cin >> code;

    int len = code.length();

    cout << decode(code, len);


}