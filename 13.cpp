//����˼·����֮�󶼲���,Ȼ��ٶ�һ��,�������˵�����
//���¿ɸ�����  K-SUM ԭ����һ������   ��ͦ��
//���ҹ�����������Ҳ�������ַ���   hash������    ����ȥ��Ҳ�Ǻ���Ҫ��һ����
//���������9���𴲿�ʼ��������5���   Ŭ��û�׷Ѱ�    
//��Ȼ����֮������  ֱ�ӵ����Ͽ�����  Ȼ��һЩ�����˷��˺ܶ�ʱ��
//����ʱ��ع�ͷ������������.



//�ܿ����뵽,����hash��,��quicksort+binary_search
//��ξ���ԭ�������ϸ�  �ܿ�   but
//��ͬ���ĵط�ʱ�䳬ʱ��

//311 / 313 test cases passed
class Use_for_quicksort{
	public:
		int compare;
		int store_one;
};

//quicksort algotithm
int quicksort(Use_for_quicksort *data,int low,int high){
	int partition(Use_for_quicksort *data,int low,int high);
	if ((high-low)<1){
		return 0;
	}
	
	int middle=partition(data,low,high-1);
	quicksort(data,low,middle);
	quicksort(data,middle+1,high);
	return 0;
}

int partition(Use_for_quicksort *data,int low,int high){
	int backup_low=low;
	int backup_high=high;
	Use_for_quicksort middle_data=data[low];
	for(;low<high;){
		for(;low<high;){
			if(data[high].compare>middle_data.compare){
				high=high-1;
			}else{
				data[low]=data[high];
				low=low+1;
				break;
			}
		}
		for(;low<high;){
			if(data[low].compare<middle_data.compare){
				low=low+1;
			}else{
				data[high]=data[low];
				high=high-1;
				break;
			}
		}
	}
	int middle=low;
	data[low]=middle_data;
	low=backup_low;
	high=backup_high;
	return middle;
}

//���ֲ���(�����ı�,����ֵΪ����Ԫ�صĸ���)
int binary_search(Use_for_quicksort *data,int low,int high
,int be_searched){
	int number = 0;
	for(;low<high;){
		int middle=(low+high)>>1;
		if(be_searched<data[middle].compare){
			high=middle;
		}
		else if(be_searched>data[middle].compare){
			low=middle+1;
		}
		else{
			for(;be_searched==data[middle].compare;middle=middle-1);
			middle=middle+1;
			for(;be_searched==data[middle].compare;middle=middle+1){
				number += 1;
			}
			return number;
		}
	}
	return 0;
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		int size = nums.size();
		int count = 0;
		if(size<3){
		    return result;
		}
        Use_for_quicksort* array = new Use_for_quicksort[size+10];
		for(int i=0;i<size;++i){
			array[i].compare = nums[i];
		}
		quicksort(array,0, size);
		for(int i = 0; i<size-1; ++i){
			for(int j = i+1; j<size; ++j){
				int temp = -(nums[i]+nums[j]);
				int three= binary_search(array, 0, size, temp);
				if(temp==nums[i]&&temp==nums[j]){
					if(three>=3){
							vector<int> child;
							int a;
							int b;
							int c;
							if(nums[i]>=nums[j]&&nums[i]>=temp){
								c=nums[i];
								if(nums[j]>=temp){
									b=nums[j];
									a=temp;
								}else{
									b=temp;
									a=nums[j];
								}
							}else if(nums[j]>=nums[i]&&nums[j]>=temp){
								c=nums[j];
								if(nums[i]>=temp){
									b=nums[i];
									a=temp;
								}else{
									b=temp;
									a=nums[i];
								}
							}else{
								c=temp;
								if(nums[i]>=nums[j]){
									b = nums[i];
									a= nums[j];
								}else{
									b = nums[j];
									a= nums[i];
								}
							}
							child.push_back(a);
							child.push_back(b);
							child.push_back(c);
							int sign = 0;
							for(int i = 0;i<count;++i){
								if(child==result[i]){
									sign = 8;
									break;
								}
							}
							if(sign == 0){
								result.push_back(child);
								++count;
							}
						}
			    }
				else if(temp==nums[i]||temp==nums[j]){
						if(three>=2){
							vector<int> child;
							int a;
							int b;
							int c;
							if(nums[i]>=nums[j]&&nums[i]>=temp){
								c=nums[i];
								if(nums[j]>=temp){
									b=nums[j];
									a=temp;
								}else{
									b=temp;
									a=nums[j];
								}
							}else if(nums[j]>=nums[i]&&nums[j]>=temp){
								c=nums[j];
								if(nums[i]>=temp){
									b=nums[i];
									a=temp;
								}else{
									b=temp;
									a=nums[i];
								}
							}else{
								c=temp;
								if(nums[i]>=nums[j]){
									b = nums[i];
									a= nums[j];
								}else{
									b = nums[j];
									a= nums[i];
								}
							}
							child.push_back(a);
							child.push_back(b);
							child.push_back(c);
							int sign = 0;
							for(int i = 0;i<count;++i){
								if(child==result[i]){
									sign = 8;
									break;
								}
							}
							if(sign == 0){
								result.push_back(child);
								++count;
							}
						}
					
				}else{
						if(three>=1){
							vector<int> child;
							int a;
							int b;
							int c;
							if(nums[i]>=nums[j]&&nums[i]>=temp){
								c=nums[i];
								if(nums[j]>=temp){
									b=nums[j];
									a=temp;
								}else{
									b=temp;
									a=nums[j];
								}
							}else if(nums[j]>=nums[i]&&nums[j]>=temp){
								c=nums[j];
								if(nums[i]>=temp){
									b=nums[i];
									a=temp;
								}else{
									b=temp;
									a=nums[i];
								}
							}else{
								c=temp;
								if(nums[i]>=nums[j]){
									b = nums[i];
									a= nums[j];
								}else{
									b = nums[j];
									a= nums[i];
								}
							}
							child.push_back(a);
							child.push_back(b);
							child.push_back(c);
							int sign = 0;
							for(int i = 0;i<count;++i){
								if(child==result[i]){
									sign = 8;
									break;
								}
							}
							if(sign == 0){
								result.push_back(child);
								++count;
							}
					 }
				}
			}
		}
		return result;
    }
};





/*
//������˼ 2��forѭ����hash  ֱ���ڵ���������
//�������Բе�һ��,û��֮һ
//��˼·��������û�����    ����û�п��Ǿ������    ֱ�������� 
//�տ�ʼ����С����   ÿһ�������źþ�    Ҫ����ֽ������һ����ƾͺö���
//��������  input��������   ��ʱ���ԲеĿ�ʼ�����³��ֵ�����Ĵ���(����ѧ��˵�Ĳ�Ӧ����������)
//����˼����Խ��Խ��   �������ǰ����е������������һ��,���Ǹо�������   ����ͷ��һ��˼·
//������ͷ����һ��˼·,Ȼ�����ڲ��û������(����˼·֮��,���������һ���������,�ܿ촦����)��������ķ�������˼·�ڴ治��
//����311,�Ͳ������   ��Ҳ��hash������   �˼�����9���, �����ڴ�������ô��ͳ����˹涨��    ֻ�ܻ�˼·��
//��  ������ʲô�������,���յ�leetcode,ʲô����˵��   ����



//311 / 313 test cases passed.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		int size = nums.size();
		int count = 0;
		if(size<3){
		    return result;
		}
        int* hash = new int[30000];
		int* hash_negative = new int[30000];
		for(int i = 0; i<30000; ++i){
			hash[i]= 0;
			hash_negative[i] = 0;
		}
		for(int i = 0; i<size; ++i){
			if(nums[i]>=0){
                hash[(nums[i])] += 1 ;
            }else{
                hash_negative[-(nums[i])] += 1 ;
            }
		}
		for(int i = 0; i<size-1; ++i){
			for(int j = i+1; j<size; ++j){
				int temp = -(nums[i]+nums[j]);
				if(temp==nums[i]&&temp==nums[j]){
					if(temp>=0){
						if(hash[temp]>=3){
							vector<int> child;
							int a;
							int b;
							int c;
							if(nums[i]>=nums[j]&&nums[i]>=temp){
								c=nums[i];
								if(nums[j]>=temp){
									b=nums[j];
									a=temp;
								}else{
									b=temp;
									a=nums[j];
								}
							}else if(nums[j]>=nums[i]&&nums[j]>=temp){
								c=nums[j];
								if(nums[i]>=temp){
									b=nums[i];
									a=temp;
								}else{
									b=temp;
									a=nums[i];
								}
							}else{
								c=temp;
								if(nums[i]>=nums[j]){
									b = nums[i];
									a= nums[j];
								}else{
									b = nums[j];
									a= nums[i];
								}
							}
							child.push_back(a);
							child.push_back(b);
							child.push_back(c);
							int sign = 0;
							for(int i = 0;i<count;++i){
								if(child==result[i]){
									sign = 8;
									break;
								}
							}
							if(sign == 0){
								result.push_back(child);
								++count;
							}
							hash[temp] = 1;
						}
					}else{
						if(hash[-temp]>=3){
							vector<int> child;
							int a;
							int b;
							int c;
							if(nums[i]>=nums[j]&&nums[i]>=temp){
								c=nums[i];
								if(nums[j]>=temp){
									b=nums[j];
									a=temp;
								}else{
									b=temp;
									a=nums[j];
								}
							}else if(nums[j]>=nums[i]&&nums[j]>=temp){
								c=nums[j];
								if(nums[i]>=temp){
									b=nums[i];
									a=temp;
								}else{
									b=temp;
									a=nums[i];
								}
							}else{
								c=temp;
								if(nums[i]>=nums[j]){
									b = nums[i];
									a= nums[j];
								}else{
									b = nums[j];
									a= nums[i];
								}
							}
							child.push_back(a);
							child.push_back(b);
							child.push_back(c);
							int sign = 0;
							for(int i = 0;i<count;++i){
								if(child==result[i]){
									sign = 8;
									break;
								}
							}
							if(sign == 0){
								result.push_back(child);
								++count;
							}
							hash[-temp] = 1;
						}
					}
				}
				else if(temp==nums[i]||temp==nums[j]){
					if(temp>=0){
						if(hash[temp]>=2){
							vector<int> child;
							int a;
							int b;
							int c;
							if(nums[i]>=nums[j]&&nums[i]>=temp){
								c=nums[i];
								if(nums[j]>=temp){
									b=nums[j];
									a=temp;
								}else{
									b=temp;
									a=nums[j];
								}
							}else if(nums[j]>=nums[i]&&nums[j]>=temp){
								c=nums[j];
								if(nums[i]>=temp){
									b=nums[i];
									a=temp;
								}else{
									b=temp;
									a=nums[i];
								}
							}else{
								c=temp;
								if(nums[i]>=nums[j]){
									b = nums[i];
									a= nums[j];
								}else{
									b = nums[j];
									a= nums[i];
								}
							}
							child.push_back(a);
							child.push_back(b);
							child.push_back(c);
							int sign = 0;
							for(int i = 0;i<count;++i){
								if(child==result[i]){
									sign = 8;
									break;
								}
							}
							if(sign == 0){
								result.push_back(child);
								++count;
							}
							hash[temp] = 1;
						}
					}else{
						if(hash_negative[-temp]>=2){
							vector<int> child;
							int a;
							int b;
							int c;
							if(nums[i]>=nums[j]&&nums[i]>=temp){
								c=nums[i];
								if(nums[j]>=temp){
									b=nums[j];
									a=temp;
								}else{
									b=temp;
									a=nums[j];
								}
							}else if(nums[j]>=nums[i]&&nums[j]>=temp){
								c=nums[j];
								if(nums[i]>=temp){
									b=nums[i];
									a=temp;
								}else{
									b=temp;
									a=nums[i];
								}
							}else{
								c=temp;
								if(nums[i]>=nums[j]){
									b = nums[i];
									a= nums[j];
								}else{
									b = nums[j];
									a= nums[i];
								}
							}
							child.push_back(a);
							child.push_back(b);
							child.push_back(c);
							int sign = 0;
							for(int i = 0;i<count;++i){
								if(child==result[i]){
									sign = 8;
									break;
								}
							}
							if(sign == 0){
								result.push_back(child);
								++count;
							}
							hash_negative[temp] = 1;
						}
					}
				}else{
					if(temp>=0){
						if(hash[temp]>=1){
							vector<int> child;
							int a;
							int b;
							int c;
							if(nums[i]>=nums[j]&&nums[i]>=temp){
								c=nums[i];
								if(nums[j]>=temp){
									b=nums[j];
									a=temp;
								}else{
									b=temp;
									a=nums[j];
								}
							}else if(nums[j]>=nums[i]&&nums[j]>=temp){
								c=nums[j];
								if(nums[i]>=temp){
									b=nums[i];
									a=temp;
								}else{
									b=temp;
									a=nums[i];
								}
							}else{
								c=temp;
								if(nums[i]>=nums[j]){
									b = nums[i];
									a= nums[j];
								}else{
									b = nums[j];
									a= nums[i];
								}
							}
							child.push_back(a);
							child.push_back(b);
							child.push_back(c);
							int sign = 0;
							for(int i = 0;i<count;++i){
								if(child==result[i]){
									sign = 8;
									break;
								}
							}
							if(sign == 0){
								result.push_back(child);
								++count;
							}
						}
					}else{
						if(hash_negative[-temp]>=1){
							vector<int> child;
							int a;
							int b;
							int c;
							if(nums[i]>=nums[j]&&nums[i]>=temp){
								c=nums[i];
								if(nums[j]>=temp){
									b=nums[j];
									a=temp;
								}else{
									b=temp;
									a=nums[j];
								}
							}else if(nums[j]>=nums[i]&&nums[j]>=temp){
								c=nums[j];
								if(nums[i]>=temp){
									b=nums[i];
									a=temp;
								}else{
									b=temp;
									a=nums[i];
								}
							}else{
								c=temp;
								if(nums[i]>=nums[j]){
									b = nums[i];
									a= nums[j];
								}else{
									b = nums[j];
									a= nums[i];
								}
							}
							child.push_back(a);
							child.push_back(b);
							child.push_back(c);
							int sign = 0;
							for(int i = 0;i<count;++i){
								if(child==result[i]){
									sign = 8;
									break;
								}
							}
							if(sign == 0){
								result.push_back(child);
								++count;
							}
						}
					}
				}
			}
		}
		return result;
    }
};
*/