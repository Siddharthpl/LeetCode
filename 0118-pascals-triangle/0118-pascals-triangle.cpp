class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            vector<int> output;
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    output.push_back(1);
                }else{
                    
                    int sum = ans[i-1][j-1] + ans[i-1][j];
                    output.push_back(sum);
                }
            }
            ans.push_back(output);
            output.clear();
        }

        return ans;
    }
};

// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> ans;
        
//         for (int i = 0; i < numRows; ++i) {
//             vector<int> row(i + 1, 1);  // Create a row with `i + 1` elements initialized to 1
            
//             for (int j = 1; j < i; ++j) {
//                 row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
//             }
            
//             ans.push_back(row);
//         }
        
//         return ans;
//     }
// };
