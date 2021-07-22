class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        
        int ones = 0;
        int n  = arr.size();
        
        for(int i : arr){
            if(i==1)
                ones++;
        }
        
        //if no ones
        if(ones == 0) return {0,n-1};
        //if irregular ones, that cannot be divided in 3 parts
        if(ones%3!=0) return {-1,-1};
        
        int k = ones/3;
        
        //we find the starting position of 3 parts since leading zeroes does not matter
        int firstOne = -1, secondOne = -1, thirdOne = -1;
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        
        //Find first one
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                firstOne = i;
                break;
            }
        }
        //Find second one
        for(int i=firstOne+1;i<n;i++){
            if(arr[i]==1) cnt2++;
            if(arr[i]==1 && cnt2==k){
                secondOne = i;
                break;
            }
        }
        //Find third one
        for(int i=secondOne+1;i<n;i++){
            if(arr[i]==1) cnt3++;
            if(arr[i]==1 && cnt3==k){
                thirdOne = i;
                break;
            }
        }
        
        //checking if they are equal
        int x = firstOne, y = secondOne, z = thirdOne;
        while(x<n && y<n && z<n){
            if(arr[x] == arr[y] && arr[y] == arr[z]){
                x++;y++;z++;
            }
            else
                return {-1,-1};
        }
        
        //after the while loop we'll have the
        //    |      |
        //  1 | 0 1  | 0 1
        //    |      |
        //      ^      ^    ^
        //      |      |    |
        //      x      y    z

        return {x-1,y};
        
    }
};