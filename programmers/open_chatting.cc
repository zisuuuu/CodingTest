#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/42888

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string,string> idmap;
    
    for(int i=0; i<record.size(); i++)
    {
        vector<string> recordS = split(record[i], ' ');
        
        string key = recordS[0];
        string id = recordS[1];
        if(key == "Enter" || key == "Change")
        {
            string name = recordS[2];
            
            auto iter = idmap.find(id);

            if ( iter == idmap.end() )
                idmap.emplace (id, name);
            else
                iter->second = name;

            if(key == "Enter")
            {
                answer.push_back(id + "님이 들어왔습니다.");
            }
        }
        else if(key == "Leave")
        {
            answer.push_back(id + "님이 나갔습니다.");
        }
    }
    
    for (auto& str: answer)
    {
        auto found = str.find("님");
        //if(found != string::nops)
        string id = str.substr(0,found);
        string name = idmap.at(id);
        str.replace(0, found, name);
    }

    return answer;
}