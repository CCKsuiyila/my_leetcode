//������һ�ο���������һ��
//�Լ��Ǹ��뷨��Ȼ����,���ǲ�֪Ϊɶ���ǲ���ȥʵ��  
//����ǲο��˱��˷��ֵĹ���
//���е���ĸ�����͵ó����෴������ת�Ľ��


//3 MS    63.84%
//����˳ʱ��
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int length = matrix.size();
		if(length<2){
			return;
		}
		for(int i = 0; i < length/2; ++i){      //��       
			for(int j = i; j<length-i-1;++j){   //��   
				int temp = matrix[j][i];
				matrix[j][i] = matrix[length-i-1][j];
				matrix[length-i-1][j] = matrix[length-j-1][length-i-1];
				matrix[length-j-1][length-i-1] = matrix[i][length-j-1];
				matrix[i][length-j-1] = temp;
			}
		}
    }
};




/*
//������ʱ����ת90��
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int length = matrix.size();
		if(length<2){
			return;
		}
		for(int i = 0; i < length/2; ++i){     //��
			for(int j = i; j<length-i-1;++j){  //��
				int temp = matrix[i][j];
				matrix[i][j] = matrix[j][length-i-1];
				matrix[j][length-i-1] = matrix[length-i-1][length-j-1];
				matrix[length-i-1][length-j-1] = matrix[length-j-1][i];
				matrix[length-j-1][i] = temp;
			}
		}
    }
};
*/