class Solution 
{
public:
vector<int> plusOne(vector<int>& digits) 
{
      int n = digits.size();
      int carry = 0 ;
      
      if(digits[n-1]!=9)
      {
          digits[n-1]+=1;
          return digits;
      }
      else
      {
          digits[n-1] = 0;
          carry = 1;
      }

      for(int i=n-2;i>=0;i--)
      {
            if(carry==1 && digits[i]!=9)
            {
                digits[i]+=1;
                carry = 0;
                return digits;
            }
            else if(carry==1 && digits[i]==9)
            {
                digits[i] = 0;
            }   
      }

      digits.insert(digits.begin(),1);

      return digits;
}


};