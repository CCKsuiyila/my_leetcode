//���������,�о�����Ϥ,�廪��·������Ƶ�,Ȼ���ֺ����ݽṹ�Ǹ���������������Щ����
//�������ǵݹ�  �ݹ���,��ȻЧ�ʵ�,���Ǻ�ЩȻ��ɿ��д������
//(����ֽ�Ͻ�Ϊ���ҵ�д�˳����Ĵ���,Ȼ���õ�������)  
//Ȼ�����һЩ�������������if  Ȼ���  71 / 92 test cases passed   
//Time Limit Exceeded  [5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5]

//Ȼ�󿴿�������Ч�ʰ�   ����һ�������������(����̰���㷨��,���ٵݹ�)  ���԰�
//Ȼ�����û��ֽ��д��,ֱ���ڵ�Ч�汾����ĳ�����,��΢���˵�ʱ��,Ҳ����
//��������   һ���Ĵ���,����û��   

//��Jump Game ���޸�һЩСϸ��

// 13 MS   49.29%
class Solution {
public:
	int numToEnd(vector<int>&nums,int index){
		int compare=0;
		int store;
		int i=0,j=index+1;
		for(;i<nums[index];++i,++j){
			if(j==nums.size()-1){
				return 1;    //����return 0 �ĳ�return 1  ���������
			}
			if(i+nums[j]>=compare){
				store=j;
				compare=i+nums[j];
			}
		}
		return numToEnd(nums,store)+1;
	}
    int jump(vector<int>& nums) {
		if(nums.size()==1){
			return 0;
		}
		/*
		if(nums.size()==2){
			return 1;
		}*/                          //�������Ҫ��
        return numToEnd(nums, 0);    //�����������Ͳ���Ҫ+1��
    }
};



//��Ч��
/*
class Solution {
public:
	int numToEnd(vector<int>&nums,int index){
		int compare=10000000;
		for(int i=0,j=index+1;i<nums[index];++i,++j){
			if(j==nums.size()-1){
				return 0;
			}
			int temp = numToEnd(nums,j);
			if(temp<compare){
				compare=temp;
			}
		}
		return compare+1;
	}
    int jump(vector<int>& nums) {
		if(nums.size()==1){
			return 0;
		}
		if(nums.size()==2){
			return 1;
		}
        return numToEnd(nums, 0);
    }
};
*/