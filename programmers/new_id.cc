#include <string>
#include <vector>
#include <iostream>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/72410

string solution(string new_id) {
    string answer = "";
    char prev_c;
    for(int i=0; i<new_id.length(); i++)
    {
        char c = new_id.at(i);
        //cout<< "c : "<<c<<endl;
        
        if(isalpha(c) == false && 
           isdigit(c) == false &&
           c != '-' && c != '_' && c != '.')
        {
            //cout<< "level 2"<<endl;
            // 2) 모든 문자 제거
            continue;
        }
        
        char new_c = c;
        if(isalpha(c))
        {
            //cout<< "level 1"<<endl;
            // 1) 대문자 -> 소문자
            new_c = tolower(c);
        }

        if(prev_c == '.' && new_c == '.')
        {
            //cout<< "level 3"<<endl;
            // 3) 연속된 마침표 치환
            continue;
        }
        
        if(answer.length() == 0 && new_c == '.')
        {
            //cout<< "level 4"<<endl;
            // 4-1) 처음에 위치한 마침표 제거
            continue;
        }
        
        answer += new_c;
        //cout<< "answer : "<<answer<<endl;
        prev_c = new_c;
    }
    
    if(answer.length() > 0 && answer.at(answer.length()-1) == '.')
    {
        //cout<< "level 4-2"<<endl;
        // 4-2) 끝에 위치한 마침표 제거
        answer = answer.substr(0, answer.length()-1);
    }
    
    if(answer.length() == 0)
    {
        //cout<< "level 5"<<endl;
        // 5) 빈 문자열이면 a 대입
        answer = "a";
    }
    else if(answer.length() >= 16)
    {
        //cout<< "level 6"<<endl;
        // 6) 16자 이상이면 15자로 제한
        answer = answer.substr(0, 15);
        
        if(answer.length() > 0 && answer.at(answer.length()-1) == '.')
        {
            answer = answer.substr(0, answer.length()-1);
        }
    }
    
    if(answer.length() <= 2)
    {
        //cout<< "level 7"<<endl;
        // 7) 2자 이하면 3자리까지 늘리기
        char last_c = answer.at(answer.length()-1);
        while(answer.length() < 3)
        {
            answer += last_c;
        }
    }
    return answer;
}