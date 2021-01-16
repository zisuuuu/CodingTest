#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/60062#
// https://yabmoons.tistory.com/552

void next_weak(vector<int>& weak, int n)
{
    int start = weak[0];
    for(int i=0; i<weak.size()-1; i++)
    {
        weak[i] = weak[i+1];
    }
    
    weak[weak.size()-1] = start + n;
}

void print(vector<int> weak, string msg)
{
    cout<<msg<<" : ";
    for(auto iter : weak)
    {
        cout<<iter<<" ";
    }
    cout<<endl;
}

bool checkOne(int n, vector<int> weak, vector<int> dist)
{
    // 가장 많이 움직일 수 있는 친구의 거리가 ( dist[last] )
    // 취약지점 start-end보다 큰 경우 return 1 (혼자서 모두 순회 가능)
    // start가 weak의 어디냐에 따라 start-end가 달라질 수 있음
    // 시작점을 weak를 돌면서 모두 확인해봐야함
    for(int i=0; i<weak.size(); i++) // 시작점 이동
    {
        next_weak(weak, n);
        
        int fin = weak[weak.size()-1] - weak[0];
        if(fin <= dist[dist.size()-1])
            return true;
    }
    
    return false;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = -1;
    
    // 거리가 긴 친구들부터 투입하기 위함
    sort(dist.begin(), dist.end());
    
    if(checkOne(n, weak, dist))
        return 1;
    
    // 친구가 두명 이상 필요
    for(int i=0; i<weak.size(); i++)  // 시작점 이동
    {
        next_weak(weak, n);
        //print(weak, "weak");
        //cout<<"  weak["<<0<<"] : "<<weak[0]<<endl;

        do
        {
            //print(dist, "    dist");
            int start = weak[0];
            int start_i = 0;
            int end_i=0;

            int result = 0;

            for(int j=1; j<=dist.size(); j++) // 긴 친구부터 투입
            {
                int d = dist[dist.size() - j];
                //cout<<"      d : "<<d<<", start : "<<start<<" ";

                // 점검할 수 있는 지점까지 점검
                int fin = start + d;
                end_i=0;
                for(end_i = start_i + 1; end_i<weak.size(); end_i++)
                {
                    if(weak[end_i] > fin)
                    {
                        break;
                    }
                }
                //cout<<", end : "<<weak[end_i - 1]<<endl;

                // 친구 추가
                result++;
                
                // 새로운 친구 시작 지점 설정
                start = weak[end_i];
                start_i = end_i;
                
                // 모두 순회한 경우, break
                if(end_i == weak.size())
                {
                    break;
                }
            }
            
            // 친구들을 다 투입했음에도 모두 순회하지 못한 경우
            if(end_i < weak.size())
                result = -1;
            
            //cout<<"    => result : "<<result<<endl;
            
            // 최소값 구하기
            if(answer < 0)
            {
                answer = result;
            }
            else
            {
                if(result > 0)
                    answer = min(answer, result);
            }
        } while(next_permutation(dist.begin(), dist.end()));
    }

    return answer;
}