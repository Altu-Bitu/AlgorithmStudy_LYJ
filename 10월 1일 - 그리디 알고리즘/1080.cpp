//
// 행렬
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> arr;
vector<vector<int>> ans;


void change(int x, int y) {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // i~ i+3-1
            // j~ j+3-1
            // 한줄로 -> 삼항연산자 사용?
            arr[x + i][y + j] == 0 ? arr[x + i][y + j] = 1 : arr[x + i][y + j] = 0;
//            if (arr[x + i][y + j] == 0) arr[x + i][y + j] = 1;
//            else arr[x + i][y + j] = 0;

        }
    }

}


int main() {

    int n, m;
    cin >> n >> m;


    string s;
    vector<int> tmp(m, 0);

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            tmp[j] = s[j] - '0';
        }
        arr.push_back(tmp);
    }

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            tmp[j] = s[j] - '0';
        }
        ans.push_back(tmp);
    }

// 이 방법보다는 위처럼 string에 저장해서 숫자로 변환하기!
//    int temp;
//    cin.ignore();
//
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            temp = cin.get(); //문자 1개를 입력받음
//            tmp[j] = temp - '0'; //문자 - '0' 숫자로 변환 해서 저장
//        }
//        cin.ignore();//엔터무시
//        arr.push_back(tmp);
//    }
//
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            temp = cin.get(); //문자 1개를 입력받음
//            tmp[j] = temp - '0'; //문자 - '0' 숫자로 변환 해서 저장
//        }
//        cin.ignore();//엔터무시
//        ans.push_back(tmp);
//    }



    //이동횟수 (가로?) m-3 회 (1세로 당)
    //이동횟수 (세로) n-3회

    int cnt = 0;
    bool flag = false;

    if (equal(arr.begin(), arr.end(), ans.begin())) { //원래 같은 배열이 들어옴
        flag = true;
    } else {
        if (n >= 3 && m >= 3) { // 3x3보다 작은 경우는 -1

            for (int x = 0; x <= n - 3; x++) {
                for (int y = 0; y <= m - 3; y++) {

                    if (arr[x][y] != ans[x][y]) { //(그리디) 똑같으면 넘어감
                        change(x, y);
                        cnt++;

                        if (equal(arr.begin(), arr.end(), ans.begin())) {
                            flag = true;
                            break;
                        }

                    }
                }
            }
        }
    }


    if (flag)
        cout << cnt;
    else
        cout << "-1";

}

