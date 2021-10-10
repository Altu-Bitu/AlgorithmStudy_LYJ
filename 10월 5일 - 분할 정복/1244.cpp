// 분할 정복
// 스위치 켜고 끄기
//

#include <iostream>
#include <vector>


using namespace std;

vector<int> lights;


void turnBoy(int a, int n) {

    for (int i = 1; i <= n; i++) {
        if (i % a == 0) {//idx가 a의 배수
            lights[i] = !lights[i];
        }
    }
}


void turnGirl(int a, int n) {

    int left = a, right = a;

    //범위 찾기
    while (left != 0 && right != n + 1 && lights[right] == lights[left]) {
        left--;
        right++;
    }

    //불 변경
    for (int i = left + 1; i < right; i++) {
        lights[i] = !lights[i];
    }


}


int main() {

    int n;
    cin >> n;

    lights.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) { //1부터 저장
        cin >> lights[i]; //bool배열로 하니까 이게 안되던데 뭐지
    }

    int m;
    cin >> m;

    int sex, num;

    for (int i = 0; i < m; i++) {

        cin >> sex >> num;

        if (sex == 1) turnBoy(num, n);
        else turnGirl(num, n);


    }

    for (int i = 1; i <= n; i++) { //1부터 출력
        cout << lights[i] << " ";
        if (i % 20 == 0) cout << "\n"; //20개마다 줄바꿈
    }


}