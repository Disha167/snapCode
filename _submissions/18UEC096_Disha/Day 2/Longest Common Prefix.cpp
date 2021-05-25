//This problem can be solved in a naive way , just key to this question is that the prefix will be present in all strings.So, we can take any string for reference and start 
//comparing every character of that string with corresponding characters of other strings. Time complexity is O(n*k)
string Solution::longestCommonPrefix(vector<string> &A) {
    string ans="";
    if(A.empty())
        return ans;
    char curr_char;
    for(int beg=0;beg<100001;beg++)//we can also iterate this pointer to minimum of all string's length
    {
        if(beg<A[0].size())//this condition is necessary to check to avoid access error
            curr_char=A[0][beg];
        else
            return ans;
        int flag=1;
        for (int i=1;i<A.size();i++)//then check every character of the first string with corresponding character of other strings
        {
            if(beg>=A[i].size())//imp condition for avoiding access error
            {
                flag=0;
                return ans;
            }
            if(beg<A[i].size()&&curr_char!=A[i][beg])
            {
                flag=0;
                return ans;
            }
        }
        if(flag==1)
        {
            ans+=curr_char;
        }
    
        
    }
    return ans;
    
}
