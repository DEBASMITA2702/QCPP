class Solution {
public:
    bool isSubsequence(string s, string t) {
        string form = "";
        for(char c:t){
            if(c == s[form.size()]){
                form.push_back(c);
            }
        }
        return form==s;
    }
};