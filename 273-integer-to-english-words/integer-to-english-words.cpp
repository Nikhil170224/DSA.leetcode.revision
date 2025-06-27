class Solution {
public:
    void solver(vector<int>& parts, int i, int n, string& ans) {
        vector<string> hundreds = {"", "One Hundred", "Two Hundred", "Three Hundred", "Four Hundred", "Five Hundred", "Six Hundred", "Seven Hundred", "Eight Hundred", "Nine Hundred"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> suff = {"Billion", "Million", "Thousand"};

        for (int index = i; index < n; index++) {
            if (parts[index] == 0) continue;

            int num = parts[index];

            if (num / 100 != 0) {
                ans += hundreds[num / 100] + " ";
                num %= 100;
            }

            if (num >= 10 && num <= 19) {
                ans += teens[num - 10] + " ";
            } else {
                if (num / 10 != 0) {
                    ans += tens[num / 10] + " ";
                    num %= 10;
                }
                if (num > 0) {
                    ans += ones[num] + " ";
                }
            }

            if (index <= 2 && parts[index] != 0) {
                ans += suff[index] + " ";
            }
        }
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";

        string ans = "";
        int n = 4;
        vector<int> parts(4, 0);
        int i = n - 1;

        while (num > 0) {
            parts[i] = num % 1000;
            num = num / 1000;
            --i;
        }

        solver(parts, i + 1, n, ans);

        // Remove trailing space
        if (!ans.empty() && ans.back() == ' ') ans.pop_back();
        return ans;
    }
};
