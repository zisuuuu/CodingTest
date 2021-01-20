#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/64065#

void print(vector<vector<int>> str)
{
    for(int i=0; i<str.size(); i++)
    {
        vector<int> temp = str.at(i);
        for(int j=0;j<temp.size(); j++)
        {
            cout<<temp[j]<<" ";
        }
        cout<<endl;
    }
}

int subV(vector<int> curr, vector<int> prev)
{
    for(int i=0; i<prev.size(); i++)
    {
        int p = prev[i];
        
        for(int j=0; j<curr.size(); j++)
        {
            int c = curr[j];
            
            if(p == c)
            {
                curr.erase(curr.begin() + j);
                break;
            }
        }
    }
    
    return curr[0];
}

bool compV(vector<int> a, vector<int> b)
{
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> str;
    
    // s 분리
    s = s.substr(1, s.length()-2);
    while(s.find("{") != std::string::npos)
    {
        auto start = s.find("{");
        auto end = s.find("}");
        
        string subS = s.substr(start+1, end-start-1);
        s = s.substr(end+1, s.length()-end);
        
        vector<int> temp;
        while(subS.find(",") != std::string::npos)
        {
            auto f = subS.find(",");
            
            string t = subS.substr(0, f);
            int d = std::stoi(t);
            temp.push_back(d);
            
            subS = subS.substr(f+1, subS.length()-f-1);
        }
        temp.push_back(std::stoi(subS));
        str.push_back(temp);
    }    

    // sort
    std::sort(str.begin(), str.end(), compV);
    
    //print(str);
    
    vector<int> prev = str[0];
    answer.push_back(prev[0]);
    for(int i=1; i<str.size(); i++)
    {
        vector<int> curr = str[i];
        
        answer.push_back(subV(curr, prev));
        prev = curr;
    }
    
    return answer;
}