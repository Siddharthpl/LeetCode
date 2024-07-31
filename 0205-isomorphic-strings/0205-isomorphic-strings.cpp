class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hash[256] = {0};
        bool isTmapped[256] = {0};

        for(int i=0;i<s.length();i++){
            if(hash[s[i]] ==0 && isTmapped[t[i]] == 0){
                hash[s[i]] = t[i];
                isTmapped[t[i]] = true;
            }
        }

        for(int i=0;i<s.length();i++){
            if(char(hash[s[i]])!= t[i]){
                return false;
            }
        }
        return true;
    }
};

// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         int m1[256] = {0}, m2[256] = {0}, n = s.size();
//         for (int i = 0; i < n; ++i) {
//             if (m1[s[i]] != m2[t[i]]) return false;
//             m1[s[i]] = i + 1;
//             m2[t[i]] = i + 1;
//         }
//         return true;
//     }
// };