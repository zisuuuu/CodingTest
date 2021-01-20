#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/1835

int getDist(string f1, string f2, vector<string> friends)
{
    int start = -1;
    int end = -1;
    for(int i=0; i<friends.size(); i++)
    {
        string f = friends[i];
        if(f1 == f || f2 == f)
        {
            if(start == -1)
                start = i;
            else
                end = i;
        }
    }
    
    return end - start - 1;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    vector<string> friends = {"A", "C", "F", "J", "M", "N", "R", "T"};
    
    do {
        bool flag = true;
        
        for(int i=0; i<data.size(); i++)
        {
            string f1 = data[i].substr(0,1);
            string f2 = data[i].substr(2,1);
            string oper = data[i].substr(3,1);
            int dist = stoi(data[i].substr(4,1));
            
            int fd = getDist(f1, f2, friends);
            
            //cout<<fd<<" " <<oper<<" "<<dist<<endl;
            if( (oper == "=" && fd == dist) ||
                (oper == "<" && fd < dist) ||
                (oper == ">" && fd > dist)
              )
            {
                flag = true;
            }
            else
            {
                flag = false;
                break;
            }
        }
        
        if(flag == true)
            answer++;
        
    } while(next_permutation(friends.begin(), friends.end()));
    return answer;
}