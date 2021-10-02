#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int SIZE = 4000; //양수의 최댓값

int calcMode(vector<int> &frequency) {
    int max_value = 0;  //최빈값의 빈도수
    for (int i = 0; i <= SIZE * 2; i++) { //최빈값의 빈도수 구하기
        if (frequency[i] > max_value)//빈도수 배열에서 최대값 검사
            max_value = frequency[i];
    }
    //두 번째로 작은 최빈값 구하기
    int cnt = 0;  //최빈값 개수
    int mode = 0; //최빈값
    for (int i = 0; i <= SIZE * 2; i++) {// -4000부터 검사하는 것이므로 제일 작은것부터 검사중임
        if (frequency[i] == max_value) {
            mode = i - SIZE; //SIZE를 더한 값으로 인덱스에 저장했었으므로 실제 값은 SIZE를 빼주어야 함
            cnt++;
            if (cnt == 2) //두 번째로 작은 최빈값
                break;
        }
    }

    return mode;
}

/**
 * 1. 산술평균 계산 시 실수 자료형으로 맞춰준 후 반올림하는거 주의
 * 2. n은 홀수이므로 중앙값은 항상 (n / 2)번째 인덱스
 * 3. 최빈값은 동일한 빈도수 내에서 두 번째로 '작은' 값임
 * 4. 최빈값이 유일하게 하나만 있는 경우 고려
 */

int main() {
    int n; //n은 홀수

    //입력
    cin >> n;

    vector<int> num(n);
    // 절댓값이 4000이 최대 이므로 -4000~4000
    vector<int> frequency(SIZE * 2 + 1, 0); //인덱스는 입력 수 + 4000의 값. 따라서 0 ~ 8000. 각 인덱스에 해당 수가 얼마나 나왔는지 저장

    double sum = 0; //평균 구하기 위한 합 변수
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        sum += (double) num[i];
        frequency[num[i] + SIZE]++; //빈도수 배열에 저장
    }

    //연산
    sort(num.begin(), num.end());

    //출력
    cout << round(sum / n) << '\n';                //산술평균
    cout << num[n / 2] << '\n';                    //중앙값
    cout << calcMode(frequency) << '\n';           //최빈값
    cout << num[num.size() - 1] - num[0] << '\n';  //범위

    return 0;
}




//
//
//#include <iostream>
//#include <vector>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//
//
//bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
//    if (a.second != b.second) return a.second > b.second; //내림차순
//    return a.first < b.first; //오름차순
//}
//
//
//int main() {
//
//    int N, num;
//    vector<int> v;
//    map<int, int> m;
//    cin >> N;
//    v.assign(N, 0);
//
//
//    int median, mode, range;
//
//    double mean;
//    double sum = 0;
//
//    for (int i = 0; i < N; i++) {
//        cin >> num;
//        v[i] = num;
//        m[num]++;
//        sum += num;
//    }
//
//    sort(v.begin(), v.end());
//
//
//    mean = sum / N;
//    median = v[N / 2];
//    range = v[N - 1] - v[0]; //v.end()-v.begin()은 안됨..
//
//
//    //mode map으로 구하는 법
//
//    vector<pair<int, int>> vec(m.begin(), m.end());
//    sort(vec.begin(), vec.end(), cmp);
//
//
//    if (vec[0].second != vec[1].second) mode = vec[0].first;
//    else mode = vec[1].first;
//
//    cout << fixed;
//    cout.precision(0);
//    cout << mean << "\n" << median << "\n" << mode << "\n" << range;
//
//
//}