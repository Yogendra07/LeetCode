class Solution {
public:
    string intToRoman(int n) 
    {
        if(n==4)
        {
            return "IV";
        }
        if(n==9)
        {
            return "IX";
        }
        if(n==40)
        {
            return "XL";
        }
        if(n==90)
        {
            return "XC";
        }
        if(n==400)
        {
            return "CD";
        }
        if(n==900)
        {
            return "CM";
        }
        string s;
        while(n>0)
        {
            if(n==4)
            {
                s=s+"IV";
                n=n-4;
                                continue;
            }
            else if(n==9)
            {
                s=s+"IX";
                n=n-9;
                                continue;

            }
           
           
            if(n>=1 && n<=3)
            {
                s=s+'I';
                n=n-1;
            }
            else if(n>=5 && n<=9)
            {
                s=s+'V';
                n=n-5;
            }
            else if(n>=10 && n<=39)
            {
                s=s+'X';
                n=n-10;
            }
            else if(n>=40 && n<=49)
            {
                s=s+"XL";
                n=n-40;
            }
            else if(n>=50 && n<=89)
            {
                s=s+'L';
                n=n-50;
            }
            else if(n>=90 && n<=99)
            {
                s=s+"XC";
                n=n-90;
            }
            else if(n>=100 && n<=399)
            {
                s=s+'C';
                n=n-100;
            }
            else if(n>=400 && n<=499)
            {
                s=s+"CD";
                n=n-400;
            }
            else if(n>=500 &&n<=899)
            {
                s=s+'D';
                n=n-500;
            }
            else if(n>=900 && n<=999)
            {
                s=s+"CM";
                n=n-900;
            }
            else
            {
                s=s+'M';
                n=n-1000;
            }
        }
        return s;
        
    }
};