#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    // Function to check if the character is alphanumeric
    bool valid(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
    }

    // Function to convert a character to lowercase
    char toLowercase(char ch) {
        if (ch >= 'A' && ch <= 'Z') {
            return ch + 'a' - 'A';
        }
        return ch;
    }

    // Function to check if the processed string is a palindrome
    bool check(string a) {
        int s = 0;
        int e = a.length() - 1;
        while (s <= e) {
            if (a[s] != a[e]) {
                return false;
            }
            s++;
            e--;
        }
        return true;
    }

public:
    // Main function to determine if the string is a palindrome
    bool isPalindrome(string s) {
        string temp = "";
        // Process the input string: keep only alphanumeric characters
        for (int i = 0; i < s.length(); i++) {
            if (valid(s[i])) {
                temp.push_back(toLowercase(s[i]));
            }
        }
        // Check if the processed string is a palindrome
        return check(temp);
    }
};

int main() {
    Solution solution;
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    bool result = solution.isPalindrome(input);
    if (result) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    return 0;
}
