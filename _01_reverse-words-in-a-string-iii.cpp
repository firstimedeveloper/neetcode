class Solution {
public:
    string reverseWords(string s) {
        int l = -1;
        int r = 0;
        while (r <= s.size()) {
            if (s[r] == ' ' || r == s.size()) {
                int i = r;
                while (++l < --i) {
                    char temp = s[l];
                    s[l] = s[i];
                    s[i] = temp;
                }
                l = r;
            }
            r++;
        }
        return s;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        auto prev = s.begin();
        string::iterator i;
        while ((i = find(prev, s.end(), ' ')) != s.end()) {
            reverse(prev,  i);
            prev = i+1;
        }
        reverse(prev, i);
        return s;
    }
};
