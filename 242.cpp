//��Ȼ������,ͻȻ����������ĸо���
//�տ�ʼû�ж������,��Ϊ��whistory�ļ򵥰�,�������󲻶�
//�ٶ�����,�����������  Ȼ��ֱ��hash������������   Ȼ��ֱ����������  accept(һ��)

//�����׶η����˻�����һ��˼·(����Ȼ��ȶ�)  �����ĸ�����һ�԰�
//��,����һ����˼·���и��õ��Ż�
//�Ա�֮�»���hash����   ��ö�

//����ȶ԰�
//23MS    22.14 %
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        sort(s.begin(),s.end());
		sort(t.begin(),t.end());
		if(s==t){
			return true;
		}else{
			return false;
		}
    }
};

/*
//hash��
//9MS  77.75%
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        int s_count[30] = {0};
		int t_count[30] = {0};
		for(int i = 0;i<s.size();++i){
			++s_count[s[i]-'a'];
		}
		for(int i = 0;i<t.size();++i){
			++t_count[t[i]-'a'];
		}
		int j=0;
		for(;j<26&&s_count[j]==t_count[j];++j);
		if(j==26){
			return true;
		}else{
			return false;
		}
    }
};
*/