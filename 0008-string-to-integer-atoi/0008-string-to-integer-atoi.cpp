class Solution {
public:
    int myAtoi(string s) {
        long long n=0;
        int signflag=0, numflag=0;
        bool neg = false;
        for(int i=0; i<s.length(); i++)
        {
            if(signflag+numflag==0 && s[i]==' ') continue;
            if(signflag+numflag==0 && s[i] == '-')
            {
                neg = true;
                signflag = 1;
                continue;
            }
            else if(signflag+numflag==0 && s[i] == '+')
            {
                signflag = 1;
                continue;
            } 
            if(!(s[i]>=48 && s[i]<=57))
               return (neg)?(0-n):n;
            else
            {
               n=n*10+((int)s[i]-48);
               if(n>INT_MAX) return ((neg) ? INT_MIN : INT_MAX);
               numflag=1;
            }
        }
        if(neg) return (0-n);
        else return n;
    }
};