#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/60057#

int solution(string s) {
    int answer = 0;
    if(s.length() == 1)
        return 1;
    
    for(int i=1; i<=s.length()/2; i++) // 자를 단위
    {                                                                                                       
        int lenS = 0;
        string prevS = s.substr(0, i);
        int count = 1;
        for(int j=i; j<s.length(); j+=i) // string iter
        {
            string currS = s.substr(j, i);
            
            if(prevS != currS)
            {
                // answer length
                if(count > 1)
                {
                    lenS += (int)log10(count) + 1;
                    //cout<<(int)log(count) + 1<<" ";
                }
                lenS += prevS.length();
                //cout<<prevS<<" ";
                
                // init
                prevS = currS;
                count = 1;
            }
            else
            {
                count++;
            }
            
            if(j+i >= s.length())
            {
                if(count > 1)
                {
                    lenS += (int)log10(count) + 1;
                }
                lenS += prevS.length();
            }
        }
        //cout<<endl;
        
        // calculate min value
        if(answer == 0)
            answer = lenS;
        else
            answer = std::min(answer, lenS);
    }
    
    return answer;
}