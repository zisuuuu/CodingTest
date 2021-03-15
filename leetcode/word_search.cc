// https://leetcode.com/problems/word-search/submissions/
/*
test cast
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"ABCCED"
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"D"
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"FCS"
[["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"]]
"AAAAAAAAAAAAAAB"
*/
class Solution {
public:
    bool hasChar(char c)
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(m_board[i][j] == c)
                    return true;
            }
        }
        
        return false;
    }
    bool dfs(int i, int j, int word_index, vector<vector<bool>> visit)
    {
        if(word_index >= m_word.length())
            return true;
        
        char comp_word = m_word.at(word_index);
        
        visit[i][j] = true;
        
        if(i < N-1 && visit[i+1][j] == false && m_board[i+1][j] == comp_word)
        {
            //cout<<"1] ["<<i<<", "<<j<<"],"<<word_index<<", "<<comp_word<<endl;
            bool result = dfs(i+1, j, word_index+1, visit);
            if(result == true)
                return true;
        }
        if(j < M-1 && visit[i][j+1] == false && m_board[i][j+1] == comp_word)
        {
            //cout<<"2] ["<<i<<", "<<j<<"],"<<word_index<<", "<<comp_word<<endl;
            bool result = dfs(i, j+1, word_index+1, visit);
            if(result == true)
                return true;
        }
        if(i > 0 && visit[i-1][j] == false && m_board[i-1][j] == comp_word)
        {
            //cout<<"3] ["<<i<<", "<<j<<"],"<<word_index<<", "<<comp_word<<endl;
            bool result = dfs(i-1, j, word_index+1, visit);
            if(result == true)
                return true;
        }
        if(j > 0 && visit[i][j-1] == false && m_board[i][j-1] == comp_word)
        {
            //cout<<"4] ["<<i<<", "<<j<<"],"<<word_index<<", "<<comp_word<<endl;
            bool result = dfs(i, j-1, word_index+1, visit);
            if(result == true)
                return true;
        }
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word)
    {
        m_board = board;
        m_word = word;
        
        if(m_board.empty())
            return false;
        
        N = m_board.size();
        M = m_board[0].size();
        
        for(int i=0; i<word.length(); i++)
        {
            if(hasChar(word.at(i)) == false)
            {
                return false;
            }
        }
        
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(m_board[i][j] == m_word.at(0))
                {
                    vector<vector<bool>> visit(N, vector<bool>(M, false));
                    bool result = dfs(i,j,1,visit);
                    if(result == true)
                        return true;
                }
            }
        }
        
        return false;
    }
private:
    string m_word;
    vector<vector<char>> m_board;
    int N;
    int M;
};