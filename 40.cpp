//�� ����һ���Լ�������˼·(���ÿ��һ��Ͱ����ճ��ȥ)
//1.�������
//2.ȷ������˼·(ѡ�����ݽṹ�㷨ʲô��)   ȷ���ܽ���������,Ҳ���ÿ���̫�ิ�Ӷ�
//3.2�ﵽ֮��, ��ʼ���Ǹ��ֽ������������������   Ȼ�󿴿���û�и��Ӷȸ��͵�˼·

//ֱ�Ӵ�39�ı���
// 9 ms  63.86%
//��Ż��˽���2��Сʱ�Ű�����ĺ�    ����ǰ��˼·������ǿ���  �˷�ʱ��   �������ڻ�����˵û������
//�Ǹ�hash���˺þ�,ȴ���޳ɹ�,������Ҫ��ʱ������ѧϰһ��hash��   
//���Ǻ���������ȫ����Ҫͨ��hash     �����������Ȧ

class Solution {
public:
	vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
		vector<int> tmp;
		sort(candidates.begin(),candidates.end()); //�ȶ�C�к�ѡ����������Ϊ����ļ�֦��׼��
		for(int i=0;i!=candidates.size();++i){
			cout<<candidates[i];
		}
		sou=candidates;
		dfs(tmp,target,0);
		return res;
	}
private:
	vector<vector<int> > res;  //���������
	vector<int> sou;  
	int sum(vector<int> tmp){ //�����ۼӺ�
		int r=0;
		for(int i=0;i!=tmp.size();++i)
			r+=tmp[i];
		return r;
	}
	int dfs(vector<int> &tmp,int tag,int l){
		if(l==sou.size()+1) //������Ҷ�ڵ�
			return 0;
		int tot=sum(tmp);
		if(tot==tag){
			res.push_back(tmp);
			return 1;
		}else if(tot>tag)  //��֦
			return 1;
		else{
			for(int i=l;i!=sou.size();++i){ //��ΪC��ÿ��������ѡ��Σ�����i��l��ʼ��������l+1
				tmp.push_back(sou[i]);
				int temp=dfs(tmp,tag,i+1);
				tmp.pop_back(); //���ݣ��ָ�tmp״̬
				if(temp==1){
					return 0;
				}
				for(;i!=sou.size()-1&&sou[i]==sou[i+1];++i);
				
			}
		}
		return 0;
	}
};