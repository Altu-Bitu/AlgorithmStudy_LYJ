//
// 롤케이크
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int>> cakes;
priority_queue<int, vector<int>, greater<int>> ten_cakes;
int ans = 0; //길이 10짜리 시나몬롤
int lol;

// 방법 2 : 함수화 ( 대신 cakes도 priority_queue로 만들어야함 -> 약간 비효율적)
void cutCakes(priority_queue<int, vector<int>, greater<int>> &q) {

    int cake = q.top();
    q.pop();

    //cut
    ans++; //자른 앞부분은 크기 10됨
    lol = cake - 10;//잘린 뒷부분

//    if (lol < 10) return;//10이하인건 무시

    if (lol == 10) ans++;
    else if (lol % 10 == 0) ten_cakes.push(lol);
    else if (lol >= 10)cakes.push(lol);

}

int main() {


//    int ans = 0; //길이 10짜리 시나몬롤

    int n, m;
    cin >> n >> m;


//    int lol;
    while (n--) {

        cin >> lol;

        if (lol < 10) continue;//10이하인건 무시

        if (lol == 10) ans++;
        else if (lol % 10 == 0) ten_cakes.push(lol);
        else cakes.push(lol);

    }


    while (m--) {


        if (!ten_cakes.empty()) {

            cutCakes(ten_cakes);
            //1. 함수가 아닌 그냥 구현
//            int cake = ten_cakes.top();
//            ten_cakes.pop();
//
//            //cut
//            ans++; //자른 앞부분은 크기 10됨
//            lol = cake - 10;//잘린 뒷부분
//
//            if (lol < 10) continue;//10이하인건 무시
//
//            if (lol == 10) ans++;
//            else if (lol % 10 == 0) ten_cakes.push(lol);
//            else if (lol >= 10)cakes.push(lol);

        } else if (!cakes.empty()) {

            cutCakes(cakes);

//            int cake = cakes[0];
//            cakes.erase(cakes.begin());//맨앞원소 삭제
//
//
//            //cut
//            ans++; //자른 앞부분은 크기 10됨
//            lol = cake - 10;//잘린 뒷부분
//
//            if (lol >= 10) cakes.push_back(lol);//10이하인건 무시
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



//3. 배열을 1개 사용해서 해결하는 방법 -> 정렬시 10으로 나누어 떨어지는것 앞으로(오름차순)
//
//
// #include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//bool cmp(const int &a, const int &b) {
//    if (a % 10 == 0 && b % 10 == 0) //둘 다 나누어 떨어지면 짧은 것부터
//        return a < b;
//    return a % 10 == 0; //나누어떨어지는 게 먼저 오도록 정렬
//}
//
////롤케이크 자르는 함수
//int cutCakeRoll(int n, int m, vector<int> &cake) {
//    int ans = 0;
//
//    for (int i = 0; i < n; i++) {
//        int cut = cake[i] / 10; //자르는 횟수
//        if (cake[i] % 10 == 0) // 길이가 10단위 일 경우 마지막꺼는 굳이 자르지 않아도 자동으로 나오니까 -1 해주어야함
//            cut--;
//        if (cut <= m) { //모두 자르기 가능한 경우
//            m -= cut; //m에서 cut번을 빼서 소모시키기
//            ans += cake[i] / 10; // cut번 ans에 저장
//        } else { //다 못자르는 경우 -> 한 번 자를 때 1개씩 나오므로 m 더함
//            ans += m; //cut>m이면 롤케이크를 끝까지 자르지 못하기 때문에 m번만 답에 더해줌
//            break;
//        }
//    }
//
//    return ans;
//}
//
///**
// * 길이가 10인 롤케이크 개수의 최댓값을 구하는 문제
// * 길이가 10이상인 롤케이크를 잘라보자. 기본적으로 한 번 자르면 1개씩 나오게 된다.
// * 이때, 10으로 나누어 떨어지는 길이를 먼저 잘라야 한다. (ex. 15를 한 번 자르면 1개가 생기지만, 20을 한 번 자르면 2개가 생김)
// * 10으로 나누어 떨어지는 길이 중에서도, 작은 길이를 먼저 잘라야 한다. (ex. 20을 한 번 자르면 2개가 생기지만, 30을 한 번 자르면 1개가 생김)
// * 10으로 나누어 떨어지지 않는 다른 수끼리는 순서가 상관 없다.
// */
//
//int main() {
//    int n, m;
//
//    //입력
//    cin >> n >> m;
//    vector<int> cake(n, 0);
//    for (int i = 0; i < n; i++)
//        cin >> cake[i];
//
//    //연산
//    sort(cake.begin(), cake.end(), cmp);
//
//    //연산 & 출력
//    cout << cutCakeRoll(n, m, cake) << '\n';
//
//    return 0;