class Solution {
public:
    string fractionAddition(string expression) {
        int n = expression.size();
        int numerator = 0, denominator = 1; // 0/1 is starting
        int i = 0;
        while (i < n) {
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-') {
                if (expression[i] == '-') {
                    sign = -1;
                }
                i++;
            }
            int num = 0;
            while (i<n && isdigit(expression[i])) {
                num=num*10+(expression[i] - '0');
                i++;
            }
            num=num*sign;
            i++; // for /
            int denom = 0;
            while (i<n && isdigit(expression[i])) {
                denom=denom*10+(expression[i] - '0');
                i++;
            }
            numerator= numerator*denom + num*denominator; //lcm liya hain
            //purane fraction main naya jodd diya
            denominator =denominator*denom;
            int g = gcd(abs(numerator), denominator); //khuch common hain toh cancel karna padega
            numerator=numerator/g;
            denominator=denominator/g;
        }
        return to_string(numerator) + "/" + to_string(denominator);
    }
    int gcd(int a, int b) {
        if(b==0) return a;
        return gcd(b,a%b);
    }
};
