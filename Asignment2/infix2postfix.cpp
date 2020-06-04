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
    freopen("input_infix2postfix.txt", "r", stdin);
    string input;
    string solution;
    int line_counter = 0;
    while(cin >> solution){
        cin >> input;
        Stack<char> stack;
        string result;
        
        //The input file is in the format "expected_solution infix_expression",
        //where expected_solution is the infix_expression in postfix format
        bool parens = false;          // flag for parenetheses
        
        for(int i=0; i<input.length(); ++i){
            // WRITE CODE HERE to store in 'result' the postfix transformation of 'input'
            
            int prec;         // stores precedence of the current operator
            char prev;       // stores the previous operator poped from stack
            int prevPrec;   // stores the precedence of the previous operators
            
            if (isOperand(input.at(i))){        // check if the character is a valid operand
                
                result += input.at(i);          // add the opperator to the result string
                
            }
            
            // operators switch statement
            switch (input.at(i))
            {
                    // cases : operators * / + -
                case '*':   case '/':   case '+':   case '-':
                    
                    if (stack.size() == 0){             // if the stack is empty
                        stack.push(input.at(i));            // push any operator to stack
                    } else {                            // otherwise compare to previous operators
                        
                        prev = stack.pop();                 // set prev to previous entry in stack
                        prevPrec = precedence(prev);        // get precedence for the previous entry
                        prec = precedence(input.at(i));     // get precedence for the current operator
                        
                        if (prec > prevPrec)           // if precedence of current is greater than previous
                            stack.push(prev);               // push both prev back into stack in-order
                        else{                          // otherwise
                            // Erroneous
                            while (prec <= precedence(prev) && stack.size() != 0 && false){ // while operators in the stack have higher precedence // not working
                                
                                result +=prev;                  // add previous to result
                                // update
                                prev = stack.pop();
                            }
                            
                            result +=prev;
                            
                        }
                        
                        
                        
                        stack.push(input.at(i));        // append the current operator to stack
                        
                    }
                    break;
                    
                    // case operator ^
                case '^':
                    
                    if (stack.size() == 0){         // if the stack is empty
                        stack.push(input.at(i));        // push the operator to stack
                    } else {                        // otherwise
                        
                        prev = stack.pop();                 // set previous to previous entry of the stack
                        prevPrec = precedence(prev);        // get precedence for previous entry
                        prec = precedence(input.at(i));     // get precedence for the current operator
                        
                        if (prec >= prevPrec){          // if the current precedence is greater or equal to previous
                            stack.push(prev);               // push the previous entry back to stack
                        } else{                         // otherwise
                            result +=prev;                  // append previous to result
                        }
                        
                        stack.push(input.at(i));    // append the current operator to stack
                        
                    }
                    break;
                    
                    // case operator opening parentheses
                case '(':
                    
                    stack.push(input.at(i));        // push it to the stack no matter the precedence
                    parens = true;                  // set parens flag to true till when it encounters closing
                    
                    break;
                    
                    // case operator closing parentheses
                case ')':
                    
                    if (parens){            // if the parentheses flag is set true
                        
                        char popped = stack.pop();  // pop the previous operator
                        
                        while(popped != '('){       // keep poping till you reach closing brace
                            result +=popped;
                            popped = stack.pop();
                        }
                        
                    } else{                         // if the closing parenthese is there without the openning
                        cout << "error" << endl;        // the equation is invalid
                    }
                    break;
                    
            }//END OF SWITCH
            
            
        }//END OF LOOP
        
        // empty the stack and append elements to result
        while (stack.size() > 0) {
            char opr = stack.pop();
            result +=opr;
        }
        // You need to do some extra stuff here to store in 'result' the postfix transformation of 'input'
        // Checking whether the result you got is correct
        if(solution == result){
            cout << "line " << line_counter << ": OK [" << solution << " " << result << "]" << endl;
        }else{
            cout << "line " << line_counter << ": ERROR [" << solution << " " << result << "]" << endl;
        }
        line_counter++;
    }
}


