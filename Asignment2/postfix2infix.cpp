#include "stack.hpp"

using namespace std;

// Auxiliary method, you probably find it useful
// Operands are all lower case and upper case characters
bool isOperand(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Auxiliary method, you probably find it useful
int precedence(char c)
{
    if(c == '+' || c == '-'){
        return 0;
    }
    if(c == '*' || c == '/'){
        return 1;
    }
    if(c == '^'){
        return 2;
    }
    return -1;
}

int main(){
    string input;
    
    cout << "Enter a postfix expresssion, or q to quit: ";
    cin >> input;
    
    while(input.at(1) != 'q'){
        
        cout << "Enter a postfix expresssion, or q to quit: ";
        cin >> input;
        
        Stack<string> stack;
        string result;
        
        for(int i=0; i<input.length(); ++i){
            
            
            string left;           // stores left handside operand of binary operator
            string right;          // stores left handside operand of binary operator
            string operand;        // stores operand
            
            // get operand
            if (isOperand(input.at(i))) {         // check if the char at index of string is a number
                
                operand.push_back(input.at(i));
                stack.push(operand);
                
            }
            
            // operators cases
            switch(input.at(i))
            {
                    
                    // exponentiation
                case '^':   // check if the char at index of string is operator ^
                    
                    right = stack.pop();        // get right
                    left = stack.pop();         // get left
                    
                    operand = "(" + left + "^" + right + ")";     // create new operand
                    
                    stack.push(operand);                        // push the operand to stack
                    break;
                    
                    // multiplication
                case '*':       // check if the char at index of string is operator *
                    
                    right = stack.pop();
                    left = stack.pop();
                    
                    operand = "(" + left + "*" + right + ")";
                    
                    stack.push(operand);
                    break;
                    
                    // division
                case '/':        // check if the char at index of string is operator /
                    
                    right = stack.pop();
                    left = stack.pop();
                    
                    operand = "(" + left + "/" + right + ")";
                    
                    stack.push(operand);
                    break;
                    
                    // addition
                case '+':         // check if the char at index of string is operator +
                    
                    right = stack.pop();
                    left = stack.pop();
                    
                    operand = "(" + left + "+" + right + ")";
                    
                    stack.push(operand);
                    break;
                    
                    // subtraction
                case '-':         // check if the char at index of string is operator -
                    
                    right = stack.pop();
                    left = stack.pop();
                    
                    operand = "(" + left + "-" + right + ")";
                    
                    stack.push(operand);
                    break;
                    
            }//END OF SWITCH
            
            
        }//END OF LOOP
        
        // empty the stack and append elements to result
        result = stack.pop();
        
        cout << "result: " << result << endl;
        
    }//END OF WHILE
}//END OF MAIN

