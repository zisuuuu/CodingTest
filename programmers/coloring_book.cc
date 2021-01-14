#include <vector>
#include <stack>
#include <iostream>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/1829

int dfs(int m, int n, int i, int j, vector<vector<int>> picture, vector<vector<int>>& visit)
{
    int area = 0;
    int pic = picture[i][j];
    stack<int> s;
    
    s.push(i);
    s.push(j);
    
    while(!s.empty())
    {
        int j_ = s.top();
        s.pop();
        int i_ = s.top();
        s.pop();
        
        if(visit[i_][j_] != 0)
            continue;
        
        visit[i_][j_] = 1;
        area++;
        
        if(i_ > 0 && picture[i_ - 1][j_] == pic &&  visit[i_ - 1][j_] == 0)
        {
            s.push(i_ - 1);
            s.push(j_);
        }
        if(j_ > 0 && picture[i_][j_ - 1] == pic && visit[i_][j_ - 1] == 0)
        {
            s.push(i_);
            s.push(j_ - 1);
        }
        if(i_ < m-1 && picture[i_ + 1][j_] == pic && visit[i_ + 1][j_] == 0)
        {
            s.push(i_ + 1);
            s.push(j_);
        }
        if(j_ < n-1 && picture[i_][j_ + 1] == pic && visit[i_][j_ + 1] == 0)
        {
            s.push(i_);
            s.push(j_ + 1);
        }
    }
    
    return area;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<vector<int>> visit;
    visit.assign(m, vector<int>(n, 0));
    
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(picture[i][j] > 0 && visit[i][j] == 0)
            {
                int area = dfs(m, n, i, j, picture, visit);
                
                number_of_area++;
                max_size_of_one_area = std::max(max_size_of_one_area, area);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}