class MyCalendar 
{
public:
    vector<int> v1;
    vector<int> v2;
    MyCalendar() 
    {
         
    }
    
    bool book(int start, int end) 
    {
        if(v1.size() == 0 || v2.size() == 0)
        {
            v1.push_back(start);
            v2.push_back(end);
            return true;
        }
        else
        {
            for(int i=0;i<v1.size();i++)
            {
                if(start < v1[i])
                {
                    if(end <= v1[i])
                    {
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(start >= v1[i] and start < v2[i])
                {
                    return false;
                }
                else if(start >= v2[i])
                {
                    continue;
                }
            }
            
            v1.push_back(start);
            v2.push_back(end);
            return true;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */