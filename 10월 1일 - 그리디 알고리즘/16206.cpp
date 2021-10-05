//
// 롤케이크
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> cakes;
priority_queue<int, vector<int>, greater<int>> ten_cakes;


int main() {


    int ans = 0; //길이 10짜리 시나몬롤

    int n, m;
    cin >> n >> m;


    int lol;
    while (n--) {

        cin >> lol;

        if (lol < 10) continue;//10이하인건 무시

        if (lol == 10) ans++;
        else if (lol % 10 == 0) ten_cakes.push(lol);
        else cakes.push_back(lol);

    }


    while (m--) {


        if (!ten_cakes.empty()) {
            int cake = ten_cakes.top();
            ten_cakes.pop();

            //cut
            ans++; //자른 앞부분은 크기 10됨
            lol = cake - 10;//잘린 뒷부분

            if (lol < 10) continue;//10이하인건 무시

            if (lol == 10) ans++;
            else if (lol % 10 == 0) ten_cakes.push(lol);
            else cakes.push_back(lol);

        } else if (!cakes.empty()) {

            int cake = cakes[0];
            cakes.erase(cakes.begin());//맨앞원소 삭제

            //cut
            ans++; //자른 앞부분은 크기 10됨
            lol = cake - 10;//잘린 뒷부분

            if (lol >= 10) cakes.push_back(lol);//10이하인건 무시
//
//            if (lol == 10) ans++;
//            else if (lol % 10 == 0) ten_cakes.push(lol);
//            else cakes.push_back(lol);


        } else {
            break;
        }


    }


    cout << ans;

}