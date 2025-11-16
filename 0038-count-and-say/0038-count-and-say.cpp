class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; i++) {
            s.push_back('\0');
            string RLE;
            char digPrev = s[0];
            int countPrev = 1;
            for (int i = 1; i < s.length(); i++) {
                if (s[i] == digPrev) countPrev++;
                else {
                    RLE.push_back(char(countPrev + '0'));
                    RLE.push_back(digPrev);
                    digPrev = s[i];
                    countPrev = 1;
                }
            }
            s = RLE;
        }
        return s;
    }
};