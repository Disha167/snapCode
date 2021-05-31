//There are many cases to handle in this question
//This question is not clear in explaination, you need to know about the linux canonical form of directory structure. It does not have / , . , .. etc . Basically . suggests
//current directory so you ignore it. .. suggests one directory up so you have to remove the fresh inserted i.e. parent directory. / is ignored.
//Eg for input, /a/b/c/.././././//d,  output will be /a/b/d.
//Basically, we have to make cases for .. ,. , /, dir name seperately and all are seperated by / instead of space so we seperate the string with / delimiter and then push
//all the results into a stack data structure.
//We use stack as it will help in removing the fresh element i.e. nearest parent directory as it follows LIFO order. 
//It is tough to implement , by first seperating all the values by / and then adding / at end.
//Be careful for this test case /../ , output is / .When following our algorithm it will pop the last element so it will return empty string but atleast root directory should
//be returned so it has to be handled explicitly.
string Solution::simplifyPath(string A) {
        // Vector of string to save tokens
    vector <string> tokens;
      
    // stringstream class check1
    stringstream check1(A);
      
    string intermediate;
      
    // Tokenizing w.r.t. space ' '
    while(getline(check1, intermediate, '/'))
    {
        tokens.push_back(intermediate);
    }
      
    // Printing the token vector
        stack<string>st;
    for(int i = 0; i < tokens.size(); i++)
    {
        if(!tokens[i].empty()&&tokens[i]!="."&&tokens[i]!="..")
        {
            st.push(tokens[i]);
        }
        else if(tokens[i]=="..")
        {
            if(!st.empty())
            st.pop();
        }
    }
    string ans="";
    while(!st.empty())
    {
        string tp=st.top();
        tp="/"+tp;
        ans=tp+ans;
        st.pop();
    }
    if(ans.empty())
        ans="/";
    return ans;
}

