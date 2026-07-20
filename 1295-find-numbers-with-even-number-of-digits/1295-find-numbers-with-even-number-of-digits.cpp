class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int digit=0;
        int n=nums.size()-1;
        int count=0;
        for(int i=0;i<=n;i++){
            int digits=0;
            int num=nums[i];
            while(num>0){
                num/=10;
                digits++;

            }
            if(digits%2==0){
                count++;
            }
        }
        return count;
    }
};