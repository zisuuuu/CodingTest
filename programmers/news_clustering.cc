#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/17677

void print(vector<string> v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<< " ";
    }
    cout<<endl;
}
vector<string> getGroup(string str)
{
    vector<string> results;
    
    string result = "";
    for(int i=0; i<str.length(); i++)
    {
        char c = str.at(i);

        result += c;
        if(result.length() == 2)
        {
            if(isalpha(result.at(0)) && isalpha(result.at(1)))
            {
                results.push_back(result);
            }
            result = "";
            i = i-1;
        }
    }

    return results;
}

int getInter(vector<string> v1, vector<string> v2)
{
    int count = 0;
    
    for (auto it = v1.begin(); it != v1.end(); /* NOTHING */)
    {
        bool remove = false;
        
        for (auto it2 = v2.begin(); it2 != v2.end(); /* NOTHING */)
        {
            if((*it) == (*it2))
            {
                remove = true;
                count ++;
                
                it = v1.erase(it);
                it2 = v2.erase(it2);
                break;
            }
            else
                it2++;
        }
        
        if(remove == false)
            it++;
    } 
    
    for (auto it = v2.begin(); it != v2.end(); /* NOTHING */)
    {
        bool remove = false;
        
        for (auto it2 = v1.begin(); it2 != v1.end(); /* NOTHING */)
        {
            if((*it) == (*it2))
            {
                remove = true;
                count ++;
                
                it = v2.erase(it);
                it2 = v1.erase(it2);
                break;
            }
            else
                it2++;
        }
        
        if(remove == false)
            it++;
    } 
    return count;
}

int solution(string str1, string str2) {
    int answer = 0;
    
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    
    auto v1 = getGroup(str1);
    auto v2 = getGroup(str2);
    
    if(v1.empty() && v2.empty())
        return 65536;
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
        
    print(v1);
    print(v2);
    
    // 교집합
    int inter = getInter(v1, v2);

    // 합집합
    // v1 + v2 - 교집합 수
    int uni = v1.size() + v2.size() - inter;
    
    answer = (double)inter/(double)uni * 65536;

    return answer;
}