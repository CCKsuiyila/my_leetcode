//���������㷨��ô��,�Ϳ�ʼ����������    ��������Ǹ����ݷ�    
//���˿����˵��㷨  ���֪�����ݷ��Ǹ�ɶ��   Ȼ�����Լ���ǰ��Լ�ù�
//Ȼ����  ���˵��㷨�и��ظ��ĵط�   Ȼ��͸������˸�   ��Ȼ  ʱ�����һ��

//���ž���ѧ��˵Ҫ������˵��㷨��ԭ���     ��������쳵  ����Ҫ���������������  
//�廪���⿨ס��ǰ   �����һ����ԭ������廪���ⲻ���Ҵ�


//���ݱ��˵�����Щ�Ż�     83%   12MS
class Solution {
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<int> tmp;
		sort(candidates.begin(),candidates.end()); //�ȶ�C�к�ѡ����������Ϊ����ļ�֦��׼��
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
		if(l==sou.size()) //������Ҷ�ڵ�
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
				int temp=dfs(tmp,tag,i);
				tmp.pop_back(); //���ݣ��ָ�tmp״̬
				if(temp==1){
					return 0;
				}
			}
		}
		return 0;
	}
};



/*
//���˵�(δ�޸�)     30%    22MS
class Solution {
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<int> tmp;
		sort(candidates.begin(),candidates.end()); //�ȶ�C�к�ѡ����������Ϊ����ļ�֦��׼��
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
	void dfs(vector<int> &tmp,int tag,int l){
		if(l==sou.size()) //������Ҷ�ڵ�
			return ;
		int tot=sum(tmp);
		if(tot==tag){
			res.push_back(tmp);
			return ;
		}else if(tot>tag)  //��֦
			return ;
		else{
			for(int i=l;i!=sou.size();++i){ //��ΪC��ÿ��������ѡ��Σ�����i��l��ʼ��������l+1
				tmp.push_back(sou[i]);
				dfs(tmp,tag,i);
				tmp.pop_back(); //���ݣ��ָ�tmp״̬
			}
		}
	}
};
*/