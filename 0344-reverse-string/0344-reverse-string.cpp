class Solution {
private:
    void usingSwapFun(vector<char>& s) {
        int l = s.size();
        for (int i=0; i<l/2; ++i) {
            swap(s[i], s[l-i-1]);
        }
    }

    void usingTwoPointers(vector<char>& s) {
        int l = 0, r = s.size()-1;
        while (l < r) {
            swap(s[l++], s[r--]);
        }
    }

public:
    void reverseString(vector<char>& s) {
        // reverse(s.begin(), s.end());
        // usingSwapFun(s);
        usingTwoPointers(s);
    }
};