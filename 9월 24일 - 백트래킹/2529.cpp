//
// 부등호
//

#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 10;

long long min_cost = 999999999999;
long long max_cost = 0;
string minString;
string maxString;

int k;
vector<char> v;
bool check[SIZE];
int num[SIZE];//

bool compare(char c, int a, int b) {

    if (c == '>') {
        return a > b;
    } else if (c == '<') {
        return a < b;
    }
}


void backtracking(int cnt, int first) {


    if (cnt == k) {
        string s;

        //num배열에 저장된 내용을 string으로
        for (int i = 0; i <= k; i++) {
            s += to_string(num[i]);
        }

        //최대,최소값 갱신
        if (stoll(s) > max_cost) {
            max_cost = stoll(s);
            maxString = s;
        }
        if (stoll(s) < min_cost) {
            min_cost = stoll(s);
            minString = s;
        }
        return;
    }


    // 현재 부호가 뭔지
    char c = v[cnt];

    for (int i = 0; i < SIZE; i++) {

        //사용 ㄴㄴ && num배열 "부호" 지금 검사중인 수 true일때만
        if (!check[i] && compare(c, num[cnt], i)) {

            //다음 칸에 삽입
            num[cnt + 1] = i;
            check[i] = true;

            backtracking(cnt + 1, first);
            check[i] = false;

        }

    }
    return;


}


int main() {


    cin >> k;
    char op;

    for (int i = 0; i < k; i++) {
        cin >> op;
        v.push_back(op);
    }

    for (int i = 0; i < SIZE; i++) {
        num[0] = i;
        check[i] = true;
        backtracking(0, i);
        check[i] = false;
    }

    cout << maxString << "\n";
    cout << minString;


}