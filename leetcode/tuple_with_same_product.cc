// https://leetcode.com/problems/tuple-with-same-product/submissions/
class Solution {
public:  
    int tupleSameProduct(vector<int>& nums) {
        int result = 0;
        std::map<int, int> xmap;

        for(int i=0; i<nums.size()-1; i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                // nums가 모두 다른 숫자이므로 원소로 계산하지 않고
                // 곱한 값으로 계산해도 겹치치 않음
                int ab = nums[i]*nums[j];
                
                auto found = xmap.find(ab);
                if(found == xmap.end())
                    xmap.emplace(nums[i]*nums[j], 1);
                else
                    found->second = found->second+1;
            }
        }
        
        for(auto it : xmap)
        {
            //cout<<it.first<<", "<<it.second<<endl;
            int n = it.second;
            if(n > 1) // 2개 이상인것 부터 ab == cd 성립
            {
                // nC2 * 8
                result += n * (n-1) * 4;
            }
        }
            
        return result;
    }
    
};