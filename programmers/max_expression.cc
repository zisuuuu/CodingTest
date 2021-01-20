#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/67257?language=cpp

vector<string> calculate(vector<string> expressions, string oper)
{
    for(int i=0; i<expressions.size(); i++)
    {
        string expression = expressions[i];
        
        string prev;
        string next;
        if(expression == oper)
        {
            prev = expressions[i-1];
            next = expressions[i+1];
            //cout<<"expression : "<<prev<<" "<<oper<<" "<<next<<endl;
        
            // calculate
            long long result = 0;
            if(oper == "*")
            {
                result = stoll(prev) * stoll(next);
            }
            else if(oper == "-")
            {
                result = stoll(prev) - stoll(next);
            }
            else if(oper == "+")
            {
                result = stoll(prev) + stoll(next);
            }

            // string replace
            auto iter = expressions.erase(expressions.begin() + i-1,expressions.begin() + i+1);
            expressions.at(i-1) = to_string(result);
            i = i-1;
            
            /*
            cout<<i<<" other : ";
            for(int j=0;j<expressions.size();j++)
            {
                cout<<expressions[j]<<" ";
            }
            cout<<endl;*/
        }
    }
    return expressions;
}

long long solution(string expression) {
    long long answer = 0;
    vector<string> oper;// = {"*", "+", "-"};
    vector<string> expressions;
    
    bool isPlus = false;
    bool isMinus = false;
    bool isMulti = false;
    for(int i=0; i<expression.length(); i++)
    {
        char c = expression.at(i);
        
        bool isOper = false;
        if(c == '*')
        {
            isMulti = true;
            isOper = true;
        }
        else if(c == '+')
        {
            isPlus = true;
            isOper = true;
        }
        else if(c == '-')
        {
            isMinus = true;
            isOper = true;
        }
        
        if(isOper == true)
        {
            // number
            expressions.push_back(expression.substr(0,i));
            
            // oper
            expressions.push_back(expression.substr(i,1));
            
            expression = expression.substr(i+1, expression.length()-i);
            i=-1;
        }
    }
    expressions.push_back(expression);
    
    // init oper list
    if(isPlus)
        oper.push_back("+");
    if(isMinus)
        oper.push_back("-");
    if(isMulti)
        oper.push_back("*");
        
    // next_permutation를 위해서는 sort가 필요
    sort(oper.begin(), oper.end());
    
    do {
        /*cout<<"oper : ";
        for(int i=0; i<oper.size(); i++)
        {
            cout<<oper[i]<<" ";
        }
        cout<<endl;*/
        
        vector<string> result = expressions;
        for(int i=0; i<oper.size(); i++)
        {
            result = calculate(result, oper[i]);    
        }
        
        //cout<<"result : "<<result[0]<<endl;
        answer = max(answer, abs(stoll(result[0])));
    } while(next_permutation(oper.begin(), oper.end()));

    return answer;
}