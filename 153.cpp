//������һ���򵥵Ĵչ�array��20����   Ȼ��ѡ�������
//��Ȼֱ�����˼·,Ȼ���������,Ȼ��accept��  ������10���Ӱ�   
//����ֻ��һ��©���ķֺŵ��﷨����    ţ��
// 3MS   36.74%
class Solution {
public:
    int findMin(vector<int>& nums) {
		if(nums.size()==1){
			return nums[0];
		}
		int i = 1;
        for(;i<nums.size()&&nums[i]>nums[i-1];++i);
		if(i==nums.size()){
			return nums[0];
		}else{
			return nums[i];
		}
		
    }
};