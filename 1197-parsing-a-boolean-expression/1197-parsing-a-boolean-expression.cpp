class Solution {
public:
    bool solve(string& expression, char prev, int& i, int n) {
        bool result = true;
        if(prev== '|') result=false;
        while (i < n) {
            if (expression[i] == ')') {
                i++;
                break;
            }
            if (expression[i] == ',') {
                i++;
                continue;
            }
            if (expression[i] == 't' || expression[i] == 'f') {
                bool current = expression[i] == 't';
                if (prev == '|') result |= current;
                else if (prev == '&') result &= current;
                else result = current;
                i++;
                continue;
            }
            i += 2; //fir skipping bracket 
            if (expression[i-2] == '!') {
                bool innerresult = !solve(expression, '?', i, n);
                if (prev == '|') result |= innerresult;
                else if (prev == '&') result &= innerresult;
                else result = innerresult;
            } 
            else {
                bool temp = solve(expression, expression[i-2], i, n);
                if (prev == '|') result |= temp;
                else if (prev == '&') result &= temp;
                else result = temp;
            }
        }
        return result;
    }

    bool parseBoolExpr(string expression) {
        int i = 0;
        return solve(expression, '?', i, expression.size());
        // '?' is just dummy character
    }
};