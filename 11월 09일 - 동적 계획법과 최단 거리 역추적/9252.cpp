//
// 9252번 - LCS 2
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
//상, 좌, 좌상향
int dr[3] = {-1, 0, -1};//위로 1칸, x , 위로 1칸
int dc[3] = {0, -1, -1};//x, 좌로 1칸, 좌로1칸

//역추적
string back(string str1, vector<vector<int>> &path) { //저장된 방향대로 이동하여 역추적하며 문자열을 알아냄
    string result = "";//정답을 저장할 배열
    int r = n, c = m; //최초 값은 정답이 dp[n][m]이었으므로, path[n][m]으로부터 역추적 해나가야함
    while (path[r][c] != -1) {
        int d = path[r][c]; //dr,dc의 index 인 direction (0:↑ 1:← 2:↖)
        if (d == 2) //좌상향에서 가져온 경우 -> str1[r - 1] == str2[c - 1]
            result += str1[r - 1]; //해당위치의 문자를 답에 추가함
        r += dr[d]; //역추적
        c += dc[d]; //역추적
    }
    reverse(result.begin(), result.end());//역추적 했으므로, 순서가 반대 -> reverse필요
    return result;//reverse된 string을 return
}

//LCS 길이 구하는 함수
int lcs(string str1, string str2, vector<vector<int>> &path) {

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); //이전 문자열들의 조합에 대한 공통 부분 수열의 최대 길이
    // 계산은 row, col전부 1부터 시작한다( 이전 문자를 비교해야하기 떄문에 row 0 col 0을 전부 0으로 초기화 하고 시작해야 최초에 이전값을 가져올 수 있음


    for (int i = 1; i <= n; i++) {//str1의 각 글자에 대하여
        for (int j = 1; j <= m; j++) {//str2의 각 글자에 대하여
            if (str1[i - 1] != str2[j - 1]) { //두 문자가 서로 다르면
                dp[i][j] = dp[i - 1][j]; //우선 위쪽 값 가져온 것으로 저장
                path[i][j] = 0; //경로(방향) 저장(↑)
                if (dp[i][j] < dp[i][j - 1]) { //왼쪽이 더 크다면
                    dp[i][j] = dp[i][j - 1];//값을 왼쪽값으로 변경
                    path[i][j] = 1; //경로(방향) 저장(←)
                }
            } else if (str1[i - 1] == str2[j - 1]) { //두 문자가 서로 같다면
                dp[i][j] = dp[i - 1][j - 1] + 1; //좌상향 값 + 1
                path[i][j] = 2; //경로(방향) 저장(↖)
            }
        }
    }
    return dp[n][m]; //LCS 길이 리턴(맨 마지막에 저장되는 값)
}

/**
 * 기본 문제: LCS
 *
 * row와 col에 각각의 수열을 한자씩 가지는 2차원 표를 생성 (최대 길이를 저장한다)
 * 두 문자가 서로 같은 곳 : 공통 부분 문자열에 추가됨 -> 해당 문자들이 포함되기 이전 길이 +1 (이전 길이는 좌상향 대각선)
 * 두 문자가 서로 다른 곳 : 공통 부분 문자열에 속하지 x -> 그 전 길이의 최대값을 가져옴(왼쪽, 위쪽에 저장된 값중 최대)
 *
 *
 *
 * [역추적] -> 어디서 왔는지 경로까지 저장해야함!
 * - 위쪽, 왼쪽, 좌상향 중 어느 방향에서 왔는지 경로를 저장한 후, 역추적하는 문제
 * - 경로 저장은 dp배열이 갱신될 때 함
 *
 * 해당 풀이는 인덱스를 편하게 관리하기 위해 dp와 path 배열을 (1, 1)부터 시작
 */

int main() {
    string str1, str2;//두 수열을 저장할 변수

    //입력
    cin >> str1 >> str2;//두 수열을 입력받음
    n = str1.length();//첫번째 수열의 길이
    m = str2.length();//두번째 수열의 길이
    vector<vector<int>> path(n + 1, vector<int>(m + 1, -1)); //이전 방향을 저장할 2차원 벡터

    //연산
    int ans = lcs(str1, str2, path); //lcs -> 최장수열의 길이
    string result = back(str1, path); //역추적 -> 이전 방향을 저장해둔 vector를 이용해서 역추적

    //출력
    cout << ans << '\n' << result << '\n'; //계산한 결과값 출력
    return 0;//종료
}
