class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) 
    {
       map<int,int> m;
        
       for(int i=0;i<arr.size();i++)
       {
           m[arr[i]]++;
       }
             
       for(auto x : m)
       {
           int val = x.first;
           
           if(val >=0 )
           {
               while(m[val]--)
               {
                   if(m.find(2*val) != m.end() and m[2*val] != 0)
                   {
                       m[2*val]--;
                   }
                   else
                   {
                       return false;
                   }
               }
           }
           else
           {
               while(m[val]--)
               {
                   if(val%2 == 0)
                   {
                       if(m.find(val/2) != m.end() and m[val/2] != 0)
                       {
                           m[val/2]--;
                       }
                       else
                       {
                           return false;
                       }
                   }
                   else
                   {
                       return false;
                   }
               }
           }
       }
        
       return true;
    }
};