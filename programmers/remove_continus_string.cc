#include <iostream>
#include <string>
#include <stack>
using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/12973#

int solution(string s)
{
    stack<char> temp;
    
    for(char c : s)
    {
        if(temp.empty())
        {
            //cout<<"push1 : " <<c<<endl;
            temp.push(c);
        }
        else
        {
            if(temp.top() == c)
            {
                //cout<<"pop : " <<temp.top()<<endl;
                temp.pop();
            }
            else
            {
                //cout<<"push2 : " <<c<<endl;
                temp.push(c);
            }
        }
    }
    
    return temp.empty();
}