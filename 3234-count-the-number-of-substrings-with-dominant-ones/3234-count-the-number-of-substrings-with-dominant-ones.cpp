class Solution {
private:
    // TC: O(n^2)
    int bruteForceMethod(string& binStr) {
        int l = binStr.length();
        int countDominantStrings = 0;
        for (int i=0; i<l; ++i) {
            int countOnes = (binStr[i] == '1');
            int countZeroes = !countOnes;
            if(countOnes >= (countZeroes * countZeroes))
                countDominantStrings++;
            for (int j=i+1; j<l; ++j) {
                if (binStr[j] == '1') countOnes++;
                else countZeroes++;

                if(countOnes >= pow(countZeroes,2))
                    countDominantStrings++;
            }
        }

        return countDominantStrings;
    }

    int OptimizedBruteForce(string& s) {
        int n = s.length();

        vector<int> cumCountOne(n, 0);
        cumCountOne[0] = (s[0] == '1') ? 1 : 0;

        for(int i = 1; i < n; i++) {
            cumCountOne[i] = cumCountOne[i-1] + ((s[i] == '1') ? 1 : 0);
        }

        //[i...j] = cumCountOne[j] - cumCountOne[i-1];

        int result = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {

                int oneCount  = cumCountOne[j] - (i - 1 >= 0 ? cumCountOne[i-1] : 0);
                int zeroCount = (j - i + 1) - oneCount;

                if((zeroCount * zeroCount) > oneCount) {
                    //skip j to avoid waste indices
                    int wasteIndices = (zeroCount * zeroCount) - oneCount;
                    j += wasteIndices - 1;
                } else if((zeroCount * zeroCount) == oneCount) {
                    result += 1;
                } else { //(zeroCount * zeroCount) < oneCount
                    //[i....j] is a valid substring
                    result += 1;

                    //try to see how much j can shift to right until substring remains dominant
                    int k = sqrt(oneCount) - zeroCount;
                    int next = j + k;

                    if(next >= n) { //out of bound, means all indices are valid
                        result += (n - j - 1);
                        break; //early break
                    } else {
                        result += k;
                    }

                    j = next;
                }
            }
        }

        return result;
    }

public:
    int numberOfSubstrings(string s) {
        // return bruteForceMethod(s);
        return OptimizedBruteForce(s);
    }
};