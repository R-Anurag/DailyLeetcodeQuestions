class Solution {
private:
    int solveSimulation(int& num1, int& num2) {
        int countOperations = 0;
        while (num1 != 0 && num2 != 0) {
            ++countOperations;

            if (num1 >= num2) num1 = num1-num2;
            else num2 = num2-num1;
        }

        return countOperations;
    }

    int solveOptimalIterative(int& num1, int& num2) {
        int countOperations = 0;
        while (num1 > 0 && num2 > 0) {
            countOperations += num1/num2; // assuming num1 > num2
            num1 = num1%num2;
            swap(num1, num2);
        }
    
        return countOperations;
    }

    int solveOptimalRecursive(int num1, int num2) {
        if (num1 == 0 || num2 == 0) return 0;
        return num1/num2 + solveOptimalRecursive(num2, num1%num2);
    }

public:
    int countOperations(int num1, int num2) {
        // return solveSimulation(num1, num2);
        // return solveOptimalIterative(num1, num2);
        return solveOptimalRecursive(num1, num2);
    }
};