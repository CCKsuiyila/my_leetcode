//��������һ������   �о�û�������   ����ֽ�ϻ�����˼·��ֱ����������
//�տ�ʼ��˼·�����и������߰��������(����ԭ��û�е�һ��forѭ��ȷ��length)
//Ȼ��ͻȻ�뵽  ����һ�����ȷ��length���Ӷ�Ҳ�Ӳ�������    Ȼ����ȷ����˼·������   ��Ҳ����ס
//����֪����ֻ�㵽length֮ǰ,Ȼ����������STL,Ȼ�����˸�vector.clear()������    �������ֲ����ⶫ��   ��������    
//������˵,�����ѶȽϵͰ�   ������Ӧ����ǰ����ʱ������˼·,��ȡ��ʱ������.    ��ס3sum(���絽������,Ȼ������������ѧ��,����̵Ľ�ѵ)

//6 ms   14.52%
//3 ms    68.98%    �����ע�͵�nums.clear();֮��   ��Ȼ�¶���   ��ֻ�㵽length֮ǰ
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
		int j=0;
		int length = size;
		for(int i = 0;i<size;++i){
			if(nums[i]==val){
				length -= 1;
			}
		}
		if(legnth==0){
			//nums.clear();
			return length;
		}
		for(int i=size-1;i>=length;--i){
			if(nums[i]!=val){
				for(;nums[j]!=val;++j){}
				nums[j]=nums[i];
				++j;
			}
		}
		return length;
    }
};