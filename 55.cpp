//�����Ĺ����з����е�����   �Լ��ȸ�һ����һ��
//��Ȼû�кͱ��˵�����  ����ȫ�����оֲ�,����Ҳ������
//���ͻȻ���˵��뷨    ���ݸ��Ӷ����ж�Ҫ��������

//Ȼ��2�Ǹ���Ҫ��¼�����ε�Ҳ������ѭ��    �ٵ�İ�
//  9 ms   93.70%
class Solution {
public:
    bool canJump(vector<int>& nums) {
		if(nums.size()<=1){
			return true;
		}
        int current = 0;
		int i = 0;
		for(;i<=current;++i){
			if(nums[i]+i>current){
				current =nums[i]+i;
				if(current>=nums.size()-1){
					return true;
				}
			}
		}
		return false;
    }
};

/*
//���ֱ�Ӵ�Jump Game||�Ĺ�����   ͬʱ�޸���һЩСϸ��
//Сϸ��������
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
				return 1;       //�����return 0 �ĳ���return 0;  �����͸��������
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
*/