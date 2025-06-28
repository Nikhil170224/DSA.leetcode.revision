class Solution {
public:
    // Recursive helper function
    void backtrack(string num, int target, int index,
                   long currentValue, long previousOperand,
                   string expression, vector<string>& result) {

        // Base case: if we've processed all digits
        if (index == num.size()) {
            if (currentValue == target) {
                result.push_back(expression);
            }
            return;
        }

        // Loop to try all possible lengths of the next number
        for (int i = index; i < num.size(); i++) {
            // Avoid numbers with leading zeros like "05"
            if (i != index && num[index] == '0') {
                break;
            }

            // Take the substring from index to i (inclusive)
            string currentStr = num.substr(index, i - index + 1);
            long currentNum = stol(currentStr);

            // If this is the first number, we don't add any operator
            if (index == 0) {
                backtrack(num, target, i + 1, currentNum, currentNum, currentStr, result);
            } else {
                // Try adding '+'
                backtrack(num, target, i + 1,
                          currentValue + currentNum,
                          currentNum,
                          expression + "+" + currentStr,
                          result);

                // Try adding '-'
                backtrack(num, target, i + 1,
                          currentValue - currentNum,
                          -currentNum,
                          expression + "-" + currentStr,
                          result);

                // Try adding '*'
                backtrack(num, target, i + 1,
                          currentValue - previousOperand + previousOperand * currentNum,
                          previousOperand * currentNum,
                          expression + "*" + currentStr,
                          result);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> result;
        backtrack(num, target, 0, 0, 0, "", result);
        return result;
    }
};