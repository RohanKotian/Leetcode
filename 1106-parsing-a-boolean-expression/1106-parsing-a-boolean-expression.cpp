class Solution {
public:
    void solve(stack<char>& signs, stack<char>& operand){
        char op = signs.top();
        signs.pop();
        bool ans = true;
        if(op=='&'){
            while(operand.top() != '('){
                ans &= (operand.top()=='t');
                operand.pop();
            }
            operand.pop();
        }
        else if(op=='|'){
            ans = false;
            while(operand.top() != '('){
                ans |= (operand.top()=='t');
                operand.pop();
            }
            operand.pop();
        }
        else if(op=='!'){
            ans = (operand.top()=='t');
            ans = !ans;
            operand.pop();
            operand.pop();
        }
        if(ans) operand.push('t');
        else operand.push('f');
    }
    bool parseBoolExpr(string expression) {
        int n = expression.length();
        stack<char> signs, operand;
        for(char c:expression){
            if(c=='!' || c=='&' || c=='|'){
                signs.push(c);
            }
            else if(c=='(' || c=='t' || c=='f'){
                operand.push(c);
            }
            else if(c==')'){
                solve(signs, operand);
            }
        }
        return operand.top()=='t';
    }
};