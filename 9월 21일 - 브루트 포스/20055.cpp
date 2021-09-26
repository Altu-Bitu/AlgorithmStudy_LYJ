/*
 *  로봇 / 칸
 *
 *  올리는 위치 : 1
 *  내리는 위치 : N
 *
 *  <칸의 내구도>
 *  내구도(i칸) : Ai
 *  내구도 감소 (-1) : 1. 올리는 위치에 로봇을 올림  2. 로봇이 이동해서 해당 칸에 올라옴
 *
 *  목적 : 로봇을 1칸에 올려 -> 한칸씩 움직여 반대편으로
 *
 *  조건 :
 *  칸의 내구도가 0이면 해당칸으로 이동 불가능
 *  1칸당 로봇 1개까지만 가
 *
 *
 *
 *
 */


#include <iostream>
#include <vector>

using namespace std;

vector<int> dur;
vector<bool> robot;

int main() {

    int N, K;
    cin >> N >> K;

    dur.assign(2 * N + 1, 0); // 0 1 ~ 2N까지
    robot.assign(N + 1, false); // 0 1 ~ N까지


    for (int i = 1; i < 2 * N + 1; i++) { //1번칸부터 2n칸까지
        cin >> dur[i];
    }

    int num = 0;//내구도가 0인 칸의 수
    int count = 0;

    while (num < K) {

        //1. 컨베이어 벨트의 회전


        dur[0] = dur[2 * N];
        //한칸씩 이동
        for (int i = 2 * N; i > 0; i--) {
            //1) durability 변경
            dur[i] = dur[i - 1];
            //2) 위에 올라간 로봇
            if (i < N) {
                //한칸씩 땡기는데 1)N에 도달하는 애는 버리기  2) 1은 false (0은 언제나 false라 이미 ㄱㅊ)
                robot[i] = robot[i - 1];
            }
        }



        //N에 누군가 도달했다면 버려주기
        if (robot[N]) robot[N] = false;


        //2. 로봇의 이동 -> 가장 먼저 벨트에 올라간 로봇부터 움직여야하는데 (뒤부터하면될거같은디..)

        //한칸씩 이동
        for (int i = N; i > 0; i--) {


            if (robot[i - 1] && !robot[i] && dur[i] >= 1) { //해당칸에 로봇 x , 내구성 1이상
                robot[i] = true;//어쩌피 전칸에 로봇이 있을떄만 돌아가서 이렇게 해도될듯?
                robot[i - 1] = false;
                dur[i]--;

                if (dur[i] == 0) num++;
            }


        }

        if (robot[N]) robot[N] = false;



        //3. 배치
        if (dur[1] != 0) {
            robot[1] = true;
            dur[1]--;
            if (dur[1] == 0) num++;
        }


        count++;

    }

    cout << count;

}