class Solution {
public:

    void solve(string digits,unordered_map<char, string> map,vector<string>& ans,int i,string& output,int n){
        if(i>=n){
            ans.push_back(output);
            return;
        }
        
        string letters = map[digits[i]];  // Get the string of letters for the current digit
        for (char letter : letters) {
            output.push_back(letter);
            solve(digits, map, ans, i + 1, output, n);
            output.pop_back(); 
        }

    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
         unordered_map<char, string> map = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        
        vector<string> ans;
        int i=0;
        string output ;
        int n = digits.length();

        solve(digits,map,ans,i,output,n);
        return ans;

        
    }
};