//�����ǿ�ʼ��ʽ����(124������������������)  ����ǰ���廪��һ�� ����ֽ��,Ȼ���õ�������
//Congratulations, you've just unlocked a solution!   ��ξ�Ȼ�������   ��Ȼ��������ɶ��˼
//��������ջ�   ĥ�����󿳲�   д֮ǰ����ʱ��������Ǻܱ�Ҫ��
//�������  ��λ��ǿ���С�ڿ�   �������Ƶ��Ե���   ����Ӧ�ñ����   �������Ҳ�������Լ���һ������   �Ժ�һ��Ҫ��ʼ��   ��Ը�໨ʱ��
//ѭ����ÿһ������Ԫ�س�ʼ��     �����   ���Ī������     ����  ����С�ڿ�  �����Ĳ�֪��զ����   ��Ȼ���ڻ���֪������ɶ
//ԭ��(��֪����������������)
// 32 ms   48.92%

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int s_length = s.size();
		int max_size = 0;
		int cur_length = 0;
		int* hash = new int[95];
        for(int i = 0; i < s_length; ++i){
			for(int k = 0; k<95; ++k){
			    hash[k] = 0;
			}
			cur_length = 0;
			int index = 0;
			for(int j = i; j < s_length; ++j){
				index = s[j] - '!' + 1;
				if(hash[index] != 8){
					hash[index] = 8;
					cur_length += 1;
				}else{
					break;
				}
			}
			if(cur_length>max_size){
				max_size = cur_length;
			}
		}
		delete [] hash;
		return max_size;
    }
};