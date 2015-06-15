class Solution {
public:
    string multiply(string num1, string num2) {
       vector<int> vec(num1.size()+num2.size()+1, 0);
       for( int i=0; i<num2.size(); ++i)
       {
           int b = num2[num2.size()-1-i]-'0';
           for( int j=0; j<num1.size(); ++j)
           {
               int a = num1[num1.size()-1-j]-'0';
               vec[i+j] += a*b;
           }
       }
       
       //update num->single
       for( int i=0; i<num1.size()+num2.size(); ++i)
       {
           vec[i+1] += vec[i]/10;
           vec[i] = vec[i]%10;
       }
       int idx = num1.size()+num2.size();
       while(idx>=0 && !vec[idx]) idx--;
       int len = max(idx+1, 1);
       string str(len, '0');
       for( int i=0; i<len; ++i)
       {
           str[len-1-i] += vec[i]; 
       }
       return str;
    }
};