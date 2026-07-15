#include <stack>
#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
  int evalRPN(std::vector<std::string> &tokens) {
    if(tokens.size() == 1) return std::stoi(tokens.at(0));

    std::stack<std::string> stk;

    stk.push(tokens.at(0));
    stk.push(tokens.at(1));
    stk.push(tokens.at(2));
    int count = 3;

    while (count < tokens.size()) {
      if(!stk.empty() && 
         (stk.top() == "+" ||
          stk.top() == "*" ||
          stk.top() == "/" ||
          stk.top() == "-"))
      {
        std::cout << "popping operator.....\n" << stk.top() << "\n";
        std::string op = stk.top(); 
        stk.pop();

        std::cout << "popped operator\n" << op << "\n";

        int num2 = std::stoi(stk.top());
stk.pop();

        int num1 = std::stoi(stk.top());
        stk.pop();

        std::string res;
        if(op == "+") res = std::to_string(num1 + num2); 
        else if(op == "-") res = std::to_string(num1 - num2);
        else if(op == "*") res = std::to_string(num1 * num2);
        else if(op == "/") res = std::to_string(num1 / num2);

        std::cout << "res\n" << res << "\n";
        stk.push(res);
        std::cout << "new top...\n" << stk.top() << "\n";
      }
    
      std::cout << "pushing next....\n" << tokens.at(count) << "\n";
      stk.push(tokens.at(count));
      count++;
    }

        std::string op = stk.top(); 
        stk.pop();

        std::cout << "popped operator\n" << op << "\n";

        int num2 = std::stoi(stk.top());
stk.pop();

        int num1 = std::stoi(stk.top());
        stk.pop();

        int res;
        if(op == "+") res = num1 + num2; 
        else if(op == "-") res = num1 - num2;
        else if(op == "*") res = num1 * num2;
        else if(op == "/") res = num1 / num2;

    return res;
  }
};
