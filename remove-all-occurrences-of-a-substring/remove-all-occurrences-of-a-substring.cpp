class Solution {
public:
    string removeOccurrences(string s, string part) 
    {   
        while(1)
        {
            size_t found = s.find(part);
            if(found == string::npos)
            {
                break;
            }
            else
            {
                int first = found;
                s.erase(first,part.length());
            }
        }
        
        return s;
    }
};