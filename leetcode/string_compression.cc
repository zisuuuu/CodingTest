//https://leetcode.com/problems/string-compression/submissions/
class Solution {
public:
    void record(char prev_c, int count, vector<char>& result)
    {
        if(count == 0)
            return;
        
        cout<<prev_c<<","<<count<<endl;
        result.push_back(prev_c);

        if(count != 1)
        {
            string countStr = to_string(count);
            for(int i=0; i<countStr.length(); i++)
            {
                 result.push_back(countStr.at(i));
            }
        }
    }
    int compress(vector<char>& chars) {
        vector<char> result;
        
        char prev_c = ' '; 
        int count = 0;
        for(char c : chars)
        {
            if(c == prev_c)
            {
                count++;
            }
            else
            {
                record(prev_c, count, result);

                prev_c = c;
                count = 1;
            }
        }
        
        // last record
        record(prev_c, count, result);
        
        chars = result;
        
        return chars.size();
    }
};