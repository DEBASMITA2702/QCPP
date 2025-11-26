class Solution {
public:
    bool isSubsequence(string s, string t) {
        // string form = "";
        // for(char c:t){
        //     if(c == s[form.size()]){
        //         form.push_back(c);
        //     }
        // }
        // return form==s;

        int p1 = 0, p2 = 0;  // iterate over s and t
        int n1 = s.size(), n2 = t.size();  // storing length of s and t

        while(p1<n1 && p2<n2){
            if(s[p1] == t[p2]){
                p1++;
            }
            p2++;
        }

        return p1 == n1;
    }
};