#include "stack.hpp"

using namespace std;

int main(){
  freopen("input_balanced.txt", "r", stdin);
  string s,r;
  int line_counter;
  while(cin >> r){
    cin>>s;
    Stack<char> stack;
    bool isBalanced = true;
    bool solution;
    if(r[0] == 'Y' || r[0] == 'y'){
      solution = true;
    }else{
      solution = false;
    }

    // The input file is in the format "expected_solution expression"
    // so variable solution tells you whether 'expression' is balanced or not

    for(int i=0; i<s.length(); ++i){
      // WRITE CODE HERE so that isBalanced indicates whether 's' is balanced
        
        char open;      // stores opening parentheses
        char close;     // stores closing parentheses
        
        switch(s.at(i))
        {
        case '(': case '[': case '{':       // opening parentheses
                
            stack.push(s.at(i));    // opening parentheses is pushed to stack
            
            break;
        case ')': case ']': case '}':       // clsoing parentheses
                
                if (stack.size() == 0){     // if a closing parentheses is passed in without the opening
                    
                    isBalanced = false;     // set balance flag to false
                    
                    break;
                    
                } else{
                    
                open = stack.pop();     // pops the previous parentheses passed
                    close = s.at(i);    // close is the any parentheses matching the case: ) ] }
                
                // this boolean expression checks for pairing of each type of parentheses
                isBalanced = ( (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}') );
                }
                
        }
    }

    // checking if you stored in isBalanced the correct value
    if(isBalanced == solution){
      cout << "line " << line_counter << ": OK [" << solution << " " << isBalanced << "]" << endl;
    }else{
      cout << "line " << line_counter << ": ERROR [" << solution << " " << isBalanced << "]" << endl;
    }
    line_counter++;
  }
}
