// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 
// Cho một chuỗi s chỉ gồm các ký tự '(', ')', '{', '}', '[' và ']'.
// Hãy xác định xem chuỗi đầu vào có hợp lệ hay không.
// Một chuỗi được coi là hợp lệ nếu:
// Các dấu ngoặc mở phải được đóng bằng đúng loại dấu ngoặc tương ứng.
// Các dấu ngoặc mở phải được đóng theo đúng thứ tự.
// Mỗi dấu ngoặc đóng đều phải có một dấu ngoặc mở cùng loại tương ứng.

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main()
{

  return 0;
}