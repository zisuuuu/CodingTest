#include <string>
#include <vector>
#include <iostream>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/60058

bool checkRight(string s)
{
    std::size_t found = s.find(")");
    while(found!=std::string::npos)
    {
        if(found == 0)
            return false;
        
        if(s.at(found-1) == '(')
        {
            s.replace(found-1, 2, "");
            //cout<<"replace:"<<s<<endl;
        }
        
        found = s.find(")");
    }
    
    return true;
}

string reverse(string u)
{
    if(u.empty())
        return u;
    
    // 첫번째와 마지막 문자 제거
    u = u.substr(1, u.length()-2);
    
    if(u.empty())
        return u;
    
    for(int i=0; i<u.length(); i++)
    {
        if(u.at(i) == '(')
        {
            u.replace(i, 1, ")");
        }
        else
        {
            u.replace(i, 1, "(");
        }
    }
    
    return u;
}

string process(string p)
{
    string answer = "";
    // 1. 빈 문자열 반환
    if(p.empty())
        return answer;
    
    // 2. u, v로 분리
    string u = "";
    string v = "";
    
    int lcount = 0;
    int rcount = 0;
    for(int i=0; i<p.length(); i++)
    {
        char c = p.at(i);
        if(c == '(')
        {
            lcount++;
        }
        else
        {
            rcount++;
        }
        
        if(lcount == rcount)
        {
            u = p.substr(0, i+1);
            v = p.substr(i+1, p.length()-i);
            
            //cout<<"p : "<<p<<" u : "<<u<<" v : "<<v<<endl;
            break;
        }
    }

    // 3. u가 올바른 괄호 문자열인 경우
    if(checkRight(u))
    {
        answer = u + process(v);
    }
    else // 4. u가 올바른 괄호 문자열이 아닌 경우
    {
        answer += "("; // 4.1
        answer += process(v); // 4.2
        answer += ")"; // 4.3
        answer += reverse(u); // 4.4
    }
    
    return answer;
}

string solution(string p) {
    string answer = "";
    
    // 올바른 괄호 문자열인지 체크
    if(checkRight(p))
    {
        return p;
    }
    
    answer = process(p);
    
    return answer;
}