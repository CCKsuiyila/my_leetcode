//һ�ۿ���n�ĸ��Ӷ�,����ֱ����hash,���˿���ǩarray,����.����hard.
//����ֱ�Ӱ���hash����   Ȼ��һ�¹�ȥ��
//6 ms  16.14%
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int* hash = new int[1000000];
		int size = nums.size();
		for(int i=0;i!=size;++i){
			if(nums[i]>0){
				hash[nums[i]]=nums[i];
			}
		}
		int result = 1;
		for(;hash[result]==result;++result);
		return result;
    }
};