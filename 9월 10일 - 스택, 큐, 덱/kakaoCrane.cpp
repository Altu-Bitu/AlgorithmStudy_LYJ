//
// 카카오 크레인 인형뽑기 게임
// https://programmers.co.kr/learn/courses/30/lessons/64061
//

#include <string>
#include <stack>
#include <vector>


using namespace std;

stack<int> bucket;



int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int past = -1;
    int now = -1;
    //인형을 뽑아서 bucket에 담는다
    //board에서는 그자리 0으로 바꿔야함
    for(int i=0; i<moves.size();i++){ //뽑기 기계 움직이기

        int loc = moves[i]-1; //세로줄
        //인형 뽑기
        for(int j=0;j<board.size();j++ ){

            int doll = board[j][loc];
            if(doll != 0){ //뽑을 수 있음
                now = doll;
                board[j][loc] = 0;
                break;
            }

            if(j==board.size()-1){
                now = -2; //끝까지 탐색했는데 못뽑음
            }

        }

        //이전에 뽑앗던 인형을 저장해두고 같은지 비교
        if(now != -2){
            if(past == now){    //같으면
                answer+=2;
                bucket.pop(); //이전꺼 없애기

                if(bucket.empty()) past=-1;
                else past = bucket.top(); //past를 새로운걸로 교체
            }else{
                bucket.push(now);
                past = now;
            }
        }



    }

    //이전에 뽑앗던 인형을 저장해두고 같은지 비교

    //같으면
    //1.answer +=2
    //2.stack에서 꺼내서 젤위에있는거를 이전 인형으로 갈아치기

    //다르면
    //1.방금 뽑은 인형을 이전에 뽑은 인형으로 만들기


    return answer;
}