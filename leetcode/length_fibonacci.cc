/*
test case
[1,2,3,4,5,6,7,8]
[1,3,7,11,12,14,18]
[1,3,7,11,12,14,18,23,24]
[1,3,4,7]
*/
class Solution {
public:
    bool findPair(int i, int j)
    {
        for(auto iter : m_memory)
        {
            //cout<<"memory "<<iter.first<<", "<<iter.second<<", "<<i<<", "<<j<<endl;
            if(iter.first == i && iter.second == j)
                return true;
        }
        
        return false;
    }
    bool dfs(int x1_index, int x2_index, vector<bool>& visit, int& count)
    {
        int x1 = m_arr[x1_index];
        int x2 = m_arr[x2_index];
        //cout<<x1<<", "<<x2<<endl;
        
        if(count != 1 && findPair(x1_index, x2_index) == false)
            m_memory.push_back(make_pair(x1_index, x2_index));
        
        for(int i=x2_index+1; i<m_arr.size(); i++)
        {
            if(visit[i] == false && m_arr[i] == x1 + x2)
            {
                visit[i] = true;
                count++;
                bool result = dfs(x2_index, i, visit, count);
                if(result == true)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    int lenLongestFibSubseq(vector<int>& arr) {
        m_arr = arr;
        
        int answer = 0;

        // TODO : binary search로 해보기
        
        /*
        [1,3,4,7] 이면
        1->3->4->7
        3->4->7
        4->7
        총 3번 검사하게됨
        */
        
        for(int i=0; i<m_arr.size()-1; i++)
        {
            for(int j=i+1; j<m_arr.size(); j++)
            {
               if(findPair(i,j) == true)
               {
                   //cout<<"====== continue ======"<<endl;
                   continue;
               }
                    
                
                //cout<<"====== start ======"<<endl;
                
                vector<bool> visit(m_arr.size(), false);
                int count = 2;
                
                dfs(i, j, visit, count);
                
                //cout<<"====== end ====== "<<endl;
                if(count != 2)
                {
                    answer = max(answer, count);
                }
            }
        }

        return answer;
    }
    
private:
    vector<int> m_arr;
    vector<pair<int,int>> m_memory;
};