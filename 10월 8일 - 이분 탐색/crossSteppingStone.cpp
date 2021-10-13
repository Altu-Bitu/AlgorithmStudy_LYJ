//
// 프로그래머스 - 2019 카카오 개발자 겨울 인턴십 : 징검다리 건너기
//

/*
 * 현위치 개울 징검다리 개울 건너편
 *
 * 징검다리는 일렬 , 디딤돌에는 모두 숫자가 적혀있는데 밟으면 --됨
 * 디딤돌 숫자가 0이되면 밟을 수 없고, 그 다음칸으로 건너뛰어야함 -> 그중 가장 가까운걸로
 * 하지만 최대 k칸 만큼만 뛸 수 있음
 *
 * 한 번에 한명씩, 동시에 여러명 못건넘
 *
 * 최대로 건널 수 있는 사람은 몇명?
 *
 *
 * Parametric Search
 * 징검다리 n칸 (밟을 수 있는 횟수 (최대200,000,000))
 * 한번에 건너 뛸 수 있는 칸 k
 *
 * -> 건널 수 있는 사람이 m일 때, 밟을 수 있는 횟수가 0이되는 칸이 연속으로 k + 1이상이되는가..?
 *
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int crossStep(vector<int> stones, int m) { //사람 수가 m명일 때, 연속되는 0의 수의 최대값 반환

    int length;
    int max = 0;

    int size = stones.size(), left = 0, right = 0;
    while (left <= right && right < size) {

        if (stones[right] <= m) {
            right++;
        } else if (stones[right] > m) {
            left++;
            length = right - left;
            if (length > max) {
                max = length;
//                cout << "최대 값 갱신 : " << max << " 이 경우 left :" << left << " right : " << right << "\n";
            }
            left = right;
            right++;
        }


    }
    left++;
    length = right - left;
    if (length > max) {
        max = length;
//        cout << "최대 값 갱신 : " << max << " 이 경우 left :" << left << " right : " << right << "\n";
    }

    return max;

}

//건널 수 있는 사람의 수 m을 upperSearch
int upperSearch(int left, int right, int target, vector<int> stones) {

    while (left <= right) {

        int mid = (left + right) / 2;
//        cout << "====== START =======\n";
        int res = crossStep(stones, mid);
//
//        cout << "건널 수 있는 최대 사람 수(mid) : " << mid << "\n";
//        cout << "이 건넜을 때 연속된 0의 갯수 : " << res << "\n";
//        cout << "\n\n";

        if (res > target) { //연속되는 0의 수가 너무 많음  -> 사람 수를 줄여야
//            cout << "연속 되는 0의 수가 많음 -> 사람 수를 줄여야함\n";
            right = mid - 1;
        } else if (res < target) {// 연속되는 0의 수가 적음  -> 사람 수 좀 늘려도 됨
//            cout << "연속 되는 0의 수가 적음  -> 사람 수를 늘려야함 \n";
            left = mid + 1;
        } else if (res == target) {
//            cout << "연속 되는 0의 수가 k와 같음 -> 혹시 추가로 있지는 않을지 오른쪽 더 탐색  \n";
            left = mid + 1;
        }

    }

    return right + 1;

}

int solution(vector<int> stones, int k) {
    int answer = 0;

    /*
     * 건널 수 있는 인원의 수
     *
     */
    answer = upperSearch(0, *max_element(stones.begin(), stones.end()), k, stones);

    /*
     * 한번 지나갈 떄 마다 1씩 까이니까
     * m명 지나가면 모든 수가 m만큼 까임
     * 근데 이제 그거중에 숫자가 연속으로 0이 k개있으면 끝나지
     *
     */


    return answer;
}


int main() {

    vector<int> stones = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1}; //m이하의 숫자의 연속이 k개이상존재?
    int k = 3;
    cout << solution(stones, k);

//    cout << crossStep(stones, 1)<<"\n";
//    cout << crossStep(stones, 2)<<"\n";
//    cout << crossStep(stones, 3)<<"\n";
//    cout << crossStep(stones, 4)<<"\n";
//    cout << crossStep(stones, 5)<<"\n";
//    cout << crossStep(stones, 6)<<"\n";



}