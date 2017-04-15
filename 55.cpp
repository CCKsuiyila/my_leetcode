//这个直接从Jump Game||改过来了   同时修改了一些小细节
//小细节在下面
// 12 ms 62.89% 
class Solution {
public:
	int numToEnd(vector<int>&nums,int index, int& sign){
		int compare=0;
		int store;
		int i=0,j=index+1;
		if(0==nums[index]){
			return 1;
		}
		for(;i<nums[index];++i,++j){
			if(j==nums.size()-1){
				sign = 9;
				return 1;       //这里把return 0 改成了return 0;  这样就更好理解了
			}
			if(i+nums[j]>=compare){
				store=j;
				compare=i+nums[j];
			}
		}
		return numToEnd(nums,store,sign)+1;
	}
	
    bool canJump(vector<int>& nums) {
        if(nums.size()==1){
			return true;
		}
		int sign = 6;
		numToEnd(nums,0,sign);
		if(sign==6){
			return false;
		}else{
			return true;
		}
    }
};
