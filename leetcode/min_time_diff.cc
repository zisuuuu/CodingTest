//https://leetcode.com/problems/minimum-time-difference/submissions/
class Solution {
public:
    int getMinutes(string time)
    {
        stringstream ss(time);
        string temp;
        int count = 0;
        
        int hour, minute;
        while (getline(ss, temp, ':')) {
            if(count == 0)
                hour = std::stoi(temp);
            else
                minute = std::stoi(temp);
            
            count++;
        }
        
        return hour * 60 + minute;
    }
    
    vector<int> getTimePointToMinite(vector<string> timePoints)
    {
        vector<int> result;
        
        for(string timeStr : timePoints)
        {
            result.push_back(getMinutes(timeStr));
        }
        
        return result;
    }
    
    int findMinDifference(vector<string>& timePoints)
    {
        const int MAXMINUTE = 1440;
        int result = MAXMINUTE;
        
        vector<int> minutes = getTimePointToMinite(timePoints);
        std::sort(minutes.begin(), minutes.end());
        int N = minutes.size();
        
        for(int i=0; i<N; i++)
        {
            int curr_m = minutes[i];
            int next_m;
            
            if(i == N-1)
            {
                next_m = minutes[0];
            }
            else
            {
                next_m = minutes[i+1];
            }
            
            int diff1 = std::abs(curr_m - next_m);
            int diff2 = std::abs(diff1 - MAXMINUTE);
            int minDiff = std::min(diff1, diff2);
            
            result = std::min(result, minDiff);
        }
        
        return result;
    }
};