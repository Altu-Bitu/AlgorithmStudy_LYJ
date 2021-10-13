//
// 2343번 - 기타레슨
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> videos;

int n, m; //강의수 , 블루레이 수 (각 블루레이에 들어가는 크기 K)

/*
 * 강의 n개 (길이는 각각 다르나(최대10000분) 순서대로 들어가야한다)
 * 블루레이 수 m개 (들어갈 수 있는 길이가 전부 k분 으로 동일)
 *
 * -> 블루레이의 크기가 k일 때, m개의 블루레이에 강의 n개를 전부 넣을 수 있는가?
 *
 *
 *
 *
 */


int blueRay(int k) {// k = mid(블루레이의 크기)

    int num = 0;//들어갈 수 있는 강의 수


    int video_num = 0; // 0~n-1까지 n개
    int blue_num = 1; //
    int size = k; //blue ray 1개 당 들어갈 수 있는 최대 분 수
    int i = 0;
    while (video_num < n && blue_num <= m) {//n개의 강의를 다 넣거나 / 블루레이 m개를 다 소비하거나

//        cout << "[ " << i << " ] 회 차 \n";
//        cout << "<<<BEFORE>>>\n";
//        cout << "video number : " << video_num << "  blue number : " << blue_num << "(size:<<" << size << ")\n";


        if (size - videos[video_num] > 0) {
//            cout << "채우기 : o 남은 부분 : o\n";
            //넣을 수 있음

            size -= videos[video_num];
            video_num++; //넣었으니까 다음껄로



        } else if (size - videos[video_num] < 0) {
            //넣을 수 없음
//            cout << "채우기 : x 남은 부분 : o (있지만 못채우고 다음으로 넘어가야함)\n";
            //블루레이
            blue_num++; //새거 꺼내
            size = k; //그럼 사이즈도 새거
        } else if (size - videos[video_num] == 0) {
//            cout << "채우기 : o 남은 부분 : x (꽉 참 )\n";
            //지금 거 까진 넣을 수 있지만 앞으로는 불가능
            size -= videos[video_num];
            video_num++;

            //블루레이
            blue_num++; //새거 꺼내
            size = k; //그럼 사이즈도 새거
        }

//        cout << "<<<AFTER>>>\n";
//        cout << "video number : " << video_num << "  blue number : " << blue_num << "(size:<<" << size << ")\n";
//        cout << "===================================================\n";

        if (blue_num >= m + 1) break;

    }

    if (blue_num < m) return 1e9; //blueray를 전부 쓰지 못함 (k가 너무 크다는 뜻)

    return video_num;//넣을 수 있는 강의 수
}

int lowerSearch(int left, int right, int target) { //target = n

    int ans = 0;
    while (left <= right) {

        int mid = (left + right) / 2;
//
//        cout << "mid : " << mid << "\n";
//        cout << "blueRay(mid) : " << blueRay(mid) << "\n";

        if (blueRay(mid) < target) { //수업이 더 적게 저장됨 -> k를 증가시켜야함
            left = mid + 1;
        } else if (blueRay(mid) >= target) { //수업이 더 많이 저장됨 -> k를 감소시켜야 ㄴ
            ans = mid;
            right = mid - 1;
        }

    }


    return ans;


}


int main() {


    cin >> n >> m;

    //강의 분 수 입력받기
    int sum = 0;
    videos.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> videos[i];
        sum += videos[i];
    }

    //정렬 -> 하면 안됨 강의 순서 바뀔 수 없음 !

    //블루레이 크기의 최소 : 가장 긴 영상의 길이
    //블루레이 크기의 최대 : 모든 전체 합?
    cout << lowerSearch(*max_element(videos.begin(), videos.end()), sum, n);

//    cout << blueRay(9);
}
