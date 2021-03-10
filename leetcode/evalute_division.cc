// https://leetcode.com/problems/evaluate-division/submissions/
/* test case
[["x1","x2"],["x2","x3"],["x1","x4"],["x2","x5"]]
[3.0,0.5,3.4,5.6]
[["x3","x4"],["x4","x3"]]

[["a","b"],["b","c"]]
[2.0,3.0]
[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]

[["a","b"],["b","c"],["bc","cd"]]
[1.5,2.5,5.0]
[["a","c"],["c","b"],["bc","cd"],["cd","bc"]]

[["a","b"]]
[0.5]
[["a","b"],["b","a"],["a","c"],["x","y"]]

[["x1","x2"],["x2","x3"],["x1","x4"],["x2","x5"]]
[3.0,0.5,3.4,5.6]
[["x2","x4"],["x1","x5"],["x1","x3"],["x5","x5"],["x5","x1"],["x3","x4"],["x4","x3"],["x6","x6"],["x0","x0"]]

[["a","b"],["c","d"]]
[1.0,1.0]
[["a","c"],["b","d"],["b","a"],["d","c"]]
*/
class Solution {
public:
    bool dfs(vector<bool> visit, string start, string end, double& sum1, double& sum2, string depth)
    {
        //cout<<depth<<"start"<<endl;
        if(start == end)
        {
            //cout<<depth<<"break "<<sum1<<"/"<<sum2<<endl;
            return true;
        }
        
        int i=0;
        for(vector<string> equation : m_equations)
        {
            string A = equation[0];
            string B = equation[1];

            if(start == A && visit[i] == false)
            {
                //cout<<depth<<start<<" ["<<i<<"][1] "<<B<<" = "<<m_values[i]<<endl;
                visit[i] = true;
                
                double temp1 = sum1 * m_values[i];
                bool result = dfs(visit, B, end, temp1, sum2, depth+"**");
                if(result == true)
                {
                    sum1 = temp1;
                    //cout<<depth<<"return true"<<endl;
                    return true;
                }
            }
            else if(start == B && visit[i] == false)
            {
                //cout<<depth<<start<<" ["<<i<<"][0] "<<A<<" = 1/"<<m_values[i]<<endl;
                visit[i] = true;
                
                double temp2 = sum2 * m_values[i];
                bool result = dfs(visit, A, end, sum1, temp2, depth+"**");
                if(result == true)
                {
                    sum2 = temp2;
                    //cout<<depth<<"return true"<<endl;
                    return true;
                }
            }

            i++;
        }
        
        //cout<<depth<<"end"<<endl;
        return false;
    }
    
    bool hasEquation(string str)
    {
        for(vector<string> equation : m_equations)
        {
            string A = equation[0];
            string B = equation[1];
            
            if(str == A || str == B)
                return true;
        }
        
        return false;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, 
                                vector<double>& values, 
                                vector<vector<string>>& queries)
    {
        m_equations = equations;
        m_values = values;
        
        vector<double> result;
        
        for(vector<string> queriy : queries)
        {
            string C = queriy[0];
            string D = queriy[1];
            
            if(hasEquation(C) == false || hasEquation(D) == false)
            {
                result.push_back((double)-1);
                continue;
            }
            
            vector<bool> visit(equations.size(), false);
            double sum1 = 1.0;
            double sum2 = 1.0;
            bool valid = dfs(visit, C, D, sum1, sum2, "**");
            
            if(valid)
            {
                //cout<<"result "<<sum1<<"/"<<sum2<<endl;
                result.push_back(sum1/sum2);
            }
            else
            {
                result.push_back((double)-1);
            }
        }
        
        return result;
    }
private:
    vector<vector<string>> m_equations;
    vector<double> m_values;
};