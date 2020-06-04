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
    string s;
    
    cout << "Enter a postfix expresssion, or q to quit: ";
    cin >> s;
    
    while(s.at(1) != 'q'){
        
        cout << "Enter a postfix expresssion, or q to quit: ";
        getline(cin, s);
        
        Stack<int> stack;
        string result;
        
        
        for(int i=0; i<s.length(); ++i){
            
            int left;           // stores left handside operand of binary operator
            int right;          // stores left handside operand of binary operator
            int num = 0;        // temorarily stores the number value from string before passing it in
            string temp;        // temporarily stores operand before conversion
            
            // get operand
            if (isdigit(s.at(i))) {         // check if the char at index of string is a number
                
                int j;
                for(j=i; i < s.length(); j++){
                    if(s.at(j) != ' ')
                    temp+=s.at(j);
                    else
                        break;
                    
                    cout << temp;
                }
                      
                num = stoi(temp, nullptr, 10);
                cout << num;
                stack.push(num);
                stack.display();
                
                      i=j;
            } else if (s.at(i) == ' '){
                break;
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
                    
            }//END OF SWITCH
            
            
        }//END OF LOOP
        
        // empty the stack and append elements to result
        result = stack.pop();
        
        cout << "result: " << result << endl;
        
    }//END OF WHILE
}//END OF MAIN

