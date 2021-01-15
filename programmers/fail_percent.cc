#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/42889#

struct FAIL {
    int stage = 0;
    double fail = 0.0;
};

bool sortFail(FAIL a, FAIL b)
{
    if(a.fail == b.fail)
    {
        return a.stage < b.stage;
    }
    
    return a.fail > b.fail;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<FAIL> fails(N); 
    
    sort(stages.begin(), stages.end());

    int index=0;
    for(int i=1; i<=N; i++)
    {       
        int count = 0;
        int len = 0;
        for(int j=index; j<stages.size(); j++)
        {
            int stage = stages[j];
            if(stage == i)
            {
                count++;
            }
            else if(stage > i)
            {
                //cout<<"stage "<<i<<" : "<<count<<"/"<<stages.size() - index<<endl;
                len = stages.size() - index;
                index = j;
                break;
            }
            else
            {
                break;
            }
            
            if(j==stages.size()-1)
            {
                len = stages.size() - index;
                //cout<<"stage "<<i<<" : "<<count<<"/"<<stages.size() - index<<endl;
            }
        }
        
        FAIL f;
        f.stage = i;
        if(len != 0)
            f.fail = (double)count / (double)len;
        fails[i-1] = f;
    }
    
    sort(fails.begin(), fails.end(), sortFail);
    for(int i=0; i<N; i++)
    {
        FAIL f = fails[i];
        //cout<<i<<") "<<f.stage<<", "<<f.fail<<endl;
        
        answer.push_back(f.stage);
    }
         
    return answer;
}