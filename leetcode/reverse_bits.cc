//https://leetcode.com/problems/reverse-bits/submissions/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        std::bitset<32> b(n);
        
        string bitStr = b.to_string();
        //cout<<bitStr<<endl;
        
        string reverseStr = "";
        for(int i=bitStr.length()-1; i >= 0; i--)
        {
            reverseStr += bitStr.at(i);
        }
        
        std::bitset<32> reverseBitSet(reverseStr);
        //cout<<reverseBitSet.to_ulong()<<endl;
        
        return (uint32_t)reverseBitSet.to_ulong();
    }
};