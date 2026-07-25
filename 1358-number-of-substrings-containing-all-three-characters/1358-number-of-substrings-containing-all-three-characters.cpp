class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> v(3,-1);
        int cnt =0;
        for(int i=0;i<s.length();i++){
            v[s[i] - 'a'] = i;
            if(v[0] != -1 && v[1] != -1 && v[2] != -1) {
                cnt = cnt + min(v[2],min(v[0],v[1])) + 1;
            }
        }
        return cnt;
    }
};