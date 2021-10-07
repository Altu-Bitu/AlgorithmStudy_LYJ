//
// 삼각형 만들기
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> line;


int makeTri(int n) { //이거 왜 에러지
    for (int i = 0; i < n - 2; i++) {
        if (line[i] < line[i + 1] + line[i + 2]) {
            return line[i] + line[i + 1] + line[i + 2];

        }
    }
    return -1;
}


int main() {

    cin.tie(NULL); //cin , cout의 묶음을 풀어줌
    ios_base::sync_with_stdio(false); //c, c++버퍼를 분리


    int n;
    cin >> n;

    vector<int> line;
    line.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> line[i];
    }


    sort(line.begin(), line.end(), greater<int>());


//    cout << makeTri(n); -> 이거 왜 error??


    for (int i = 0; i < n - 2; i++) {
        if (line[i] < line[i + 1] + line[i + 2]) {
            cout << line[i] + line[i + 1] + line[i + 2] << "\n";
            exit(0);
        }
    }


    cout << -1;
}