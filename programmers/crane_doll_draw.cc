#include <string>
#include <vector>
#include <iostream>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/64061

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board.at(0).size();
    vector<int> boardSize(n);
    vector<int> result;
    
    for(int i=0; i<n; i++)
    {
        int bs = 0;
        for(int j=n-1; j>=0; j--)
        {
            
            if(board.at(j).at(i) > 0)
            {
                bs++;
            }
            else
            {
                break;
            }
        }
        boardSize.at(i) = bs;
    }
    
    for(int i=0; i<moves.size(); i++)
    {
        int m = moves.at(i) - 1;
        
        // 아무 것도 없으면 동작 x
        if(boardSize.at(m) <= 0)
            continue;
        
        int bs = n - boardSize.at(m);
        
        // 인형 뽑기
        int doll = board.at(bs).at(m);
        
        // 바구니로 이동
        if(result.size() == 0)
        {
            result.push_back(doll);
        }
        else
        {
            // 겹치는지 확인
            int prevDoll = result.back();
            if(doll == prevDoll)
            {
                result.pop_back();
                answer += 2;
            }
            else
            {
                result.push_back(doll);
            }
        }
        
        // board size 감소
        boardSize.at(m) = boardSize.at(m) - 1;
    }
    return answer;
}