#include "stack.hpp"
#include <string>

using namespace std;

int main(){
  freopen("input_postfixEval.txt", "r", stdin);
  string s;
  int solution;
  int line_counter = 0;
    while(cin>>solution){
    cin>>s;
    Stack<int> stack;
    // The input file is in the format "expected_solution postfix_expression"

    // We assume that all operands in the input are one digit (so they range from 0 to 9)
    for(int i=0; i<s.length(); ++i){
      // WRITE CODE HERE to evaluate the postfix expression in s
        
        int left;           // stores left handside operand of binary operator
        int right;          // stores left handside operand of binary operator
        int num = 0;        // temorarily stores the number value from string before passing it in
        
        // get operand
        if (isdigit(s.at(i))) {         // check if the char at index of string is a number
            
            num = s.at(i) - '0';
            stack.push(num);
            
        }
        
        // operators cases
        switch(s.at(i))
        {
        
        // exponentiation
            case '^':   // check if the char at index of string is operator ^
            
                right = stack.pop();        // get right
                left = stack.pop();         // get left
            
                num = pow(left, right);     // evaluate operation
            
                stack.push(num);            // push the result to stack
                break;
                
        // multiplication
            case '*':       // check if the char at index of string is operator *
                
                right = stack.pop();
                left = stack.pop();
            
                num = left * right;
            
                stack.push(num);
                break;
                
        // division
            case '/':        // check if the char at index of string is operator /
                
                right = stack.pop();
                left = stack.pop();
            
                num = left / right;
            
                stack.push(num);
                break;
                
        // addition
            case '+':         // check if the char at index of string is operator +
                
                right = stack.pop();
                left = stack.pop();
            
                num = left + right;
            
                stack.push(num);
                break;
                
        // subtraction
            case '-':         // check if the char at index of string is operator -
                
                right = stack.pop();
                left = stack.pop();
            
                num = left - right;
            
                stack.push(num);
                    break;
            
        }
      // At the end of the loop, stack.pop() should contain the value of the postfix expression
    }
    // Checking whether the value you calculated is correct ...
    int value = stack.pop();
        
    if(solution == value){
      cout << "line " << line_counter << ": OK [" << solution << " " << value << "]" << endl;
    }else{
      cout << "line " << line_counter << ": ERROR [" << solution << " " << value << "]" << endl;
    }
    line_counter++;
  }
}
