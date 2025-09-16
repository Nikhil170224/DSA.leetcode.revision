// class Solution {
// public:
//     int divide(int dividend, int divisor) {
//         long long quotient = 0;
// long long unsignDivid = (dividend < 0) ? -(long long)dividend : (long long)dividend;
// long long unsignDiv   = (divisor < 0)  ? -(long long)divisor  : (long long)divisor;

//         while(unsignDivid >= unsignDiv){
//             quotient++;
//             unsignDivid -= unsignDiv;
//         }
//         if((dividend < 0 && divisor > 0)||(dividend > 0 && divisor < 0)) quotient *= -1;      
//         if(quotient > INT_MAX) return INT_MAX;
//         if(quotient < INT_MIN) return INT_MIN;
//         return quotient;
//     }
// };

class Solution {
public:
    int divide(int dividend, int divisor) {
    long long quotient = 0;
    long long unsignDivid = (dividend < 0) ? -(long long)dividend : (long long)dividend;
    long long unsignDiv   = (divisor < 0)  ? -(long long)divisor  : (long long)divisor; 

    // while loop to subtract and decrease the unsignDivid
    while(unsignDivid >= unsignDiv){
        long long powOf2 = 1;
        while(unsignDiv*powOf2*2 <= unsignDivid){
            powOf2 *= 2;
        }
        unsignDivid -= unsignDiv*powOf2;
        quotient += powOf2;
        powOf2 = 1;
    }
      if((dividend < 0 && divisor > 0)||(dividend > 0 && divisor < 0)) quotient *= -1;      
        if(quotient > INT_MAX) return INT_MAX;
        if(quotient < INT_MIN) return INT_MIN;
        return quotient; 
    }
};