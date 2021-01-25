#include <string>
#include <vector>
#include <iostream>
#include <bitset>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/17681

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for(int i=0; i<n; i++)
    {
        auto b1 = bitset<16>(arr1[i]);
        auto b2 = bitset<16>(arr2[i]);
        auto b3 = b1 | b2;
        string str = b3.to_string();
        
        string result = "";
        for(int j=1; j<=n; j++)
        {
            char c = str.at(str.length() - j);
            if(c == '1')
            {
                result = "#" + result;
            }
            else
            {
                result = " " + result;
            }
        }
        answer.push_back(result);
    }
    return answer;
}