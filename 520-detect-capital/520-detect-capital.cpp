class Solution {
public:
    bool detectCapitalUse(string word) 
    {
        bool ans = true;
        
        if(word.length() == 1)
        {
            return true;
        }
        
        if(word[0] >= 'A' and word[0] <= 'Z')
        {
            int count = 1;
            
            for(int i=1;i<word.length();i++)
            {
                if(word[i] >= 'A' and word[i] <= 'Z')
                {
                    count++;   
                }
            }
            
            if(count == word.length())
            {
                return true;
            }
            
            count = 1;
            
            for(int i=1;i<word.length();i++)
            {
                if(word[i] >= 'a' and word[i] <= 'z')
                {
                    count++;   
                }
            }
            
            if(count == word.length())
            {
                return true;
            }
            
            return false;
        }
        else
        {
            int count = 0;
            
            for(int i=0;i<word.length();i++)
            {
                if(word[i] >= 'a' and word[i] <= 'z')
                {
                    count++;
                }
            }
            
            if(count == word.length())
            {
                return true;
            }
            else
            {
                return false;
            }
            
            
        }
        
        return true;
        
    }
};