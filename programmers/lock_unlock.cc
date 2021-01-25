#include <string>
#include <vector>
#include <iostream>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/60059#

void print(vector<vector<int>> v)
{
    for(int i=0; i<v.size(); i++)
    {
        vector<int> v2 = v[i];
        for(int j=0; j<v2.size(); j++)
        {
            cout<< v2[j]<< " ";
        }
        cout<<endl;
    }
}

vector<vector<int>> rotation(vector<vector<int>> v)
{
    vector<vector<int>> result;
    result.assign(v[0].size(), vector<int>(v.size(), 0));
    
    for(int i=0; i<v.size(); i++)
    {
        vector<int> v2 = v[i];
        for(int j=0; j<v2.size(); j++)
        {
            result[j][i] = v[i][v2.size()-j-1];
        }
    }
    
    return result;
}

vector<vector<int>> getResult(vector<vector<int>> key, 
                              vector<vector<int>> board, 
                              int skewX, int skewY
                             )
{
    vector<vector<int>> result = board;
    
    for(int i=0; i<key.size(); i++)
    {
        for(int j=0; j<key[i].size(); j++)
        {
            if(i+skewX < result.size() && j+skewY < result[0].size())
                result[i+skewX][j+skewY] += key[i][j];
        }
    }
    
    return result;
}

bool isOnlyOne(vector<vector<int>> v, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(v[i+n][j+n] != 1)
                return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;

    int n = lock.size();
    vector<vector<int>> board;
    board.assign(n * 3, vector<int>(n*3,0));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            board[i+n][j+n] += lock[i][j];
        }
    }
    
    if(isOnlyOne(board, n))
        return true;
    
    vector<vector<int>> rKey = key;
    for(int r=0; r<4; r++) // rotation
    {
        for(int i=0; i<board.size();i++)
        {
            for(int j=0; j<board.size(); j++)
            {
                vector<vector<int>> result = getResult(rKey, board, i, j);
                if(isOnlyOne(result, n))
                {
                    //cout<<"i : "<<i<<", j : "<<j<<endl;
                    //print(rKey);
                    
                    return true;
                }
            }
        }
        
        rKey = rotation(rKey);
    }
    
    return answer;
}