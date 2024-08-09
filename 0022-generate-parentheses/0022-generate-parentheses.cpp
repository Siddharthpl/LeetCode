class Solution {
public:

    void solve(int n,string& output,int open,int close,vector<string>& ans){
        if(open+close== 2*n){
            ans.push_back(output);
        }

        if(open<n){
            output.push_back('(');
            solve(n,output,open+1,close,ans);
            output.pop_back();
        }
        if(close<open){
            output.push_back(')');
            solve(n,output,open,close+1,ans);
            output.pop_back();
        }
        
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        string output = "";        
        solve(n,output,0,0,ans);

        return ans;
    }
};