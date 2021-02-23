#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/72411
// https://cutemoomin.tistory.com/entry/c-nextpermutation-%EC%A1%B0%ED%95%A9-%EA%B5%AC%ED%95%98%EA%B8%B0
// https://ansohxxn.github.io/algorithm/combination/

void combination(vector<string> arr, 
                 vector<string> comb, 
                 int index, 
                 int depth, 
                 vector<string>& results)
{
    if (depth == comb.size())
    {
        string result;
        for(int i = 0; i < comb.size(); i++)
            result += comb[i];
        
        results.push_back(result);
        return;
    }
    else
    {
        for(int i = index; i < arr.size(); i++)
        {
            comb[depth] = arr[i];
            combination(arr, comb, i + 1, depth + 1, results);
        }
    }
}

vector<string> combination2(vector<string> orders, int k)
{
    vector<string> results;
    
    int n = orders.size();
 
    // 0, 1을 넣어 임시 조합 생성
    vector<int> tempVector;
 
    for (int i = 0; i < k; i++)
    {
        tempVector.push_back(1);
    }
 
    for (int i = 0; i < orders.size() - k; i++)
    {
        tempVector.push_back(0);
    }
 
    sort(tempVector.begin(), tempVector.end());
 
    do
    {
        string result;
        for (int i = 0; i < tempVector.size(); i++)
        {
            if (tempVector[i] == 1)
            {
                result += orders[i];
            }
        }
        results.push_back(result);
    } while (next_permutation(tempVector.begin(), tempVector.end()));
    
    return results;
}

vector<string> stringToVector(string order)
{
    vector<string> result;
    
    for(int i=0; i<order.length(); i++)
    {
        result.push_back(order.substr(i,1));
    }
    
    return result;
}
vector<string> solution(vector<string> orders, vector<int> courses) {
    vector<string> answer;
    
    for(int course : courses)
    {
        unordered_map<string, int> m;
        int maxCount = 0;
        
        for(int i=0; i<orders.size(); i++)
        {
            vector<string> order = stringToVector(orders[i]);

            sort(order.begin(), order.end());

            //combination(order, course);
            
            vector<string> results;
            vector<string> comb(course);
            combination(order, comb, 0, 0, results);
            
            for(string result : results)
            {
                auto found = m.find(result);
                if(found != m.end())
                {
                    found->second = found->second + 1;
                    maxCount = max(maxCount, found->second);
                }
                else
                {
                    m.emplace(result, 1);
                }
            }
        }
        
        // m 중에서 2개 이상인것만 answer에 반영      
        if(maxCount < 2)
            continue;
        
        for(auto iter = m.begin(); iter != m.end(); iter++)
        {
            if(iter->second == maxCount)
            {
                answer.push_back(iter->first);
            }
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}