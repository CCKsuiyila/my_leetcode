class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1Size = nums1.size();
        int nums2Size = nums2.size();
        int * nums3 = new int[nums1Size+nums2Size+10];
        int num1_index = 0;
        int num2_index = 0;
        int num3_index = 0;
        while(num1_index<nums1Size&&num2_index<nums2Size){
            if(nums1[num1_index]<=nums2[num2_index]){
                nums3[num3_index++] = nums1[num1_index++];
            }else{
                nums3[num3_index++] = nums2[num2_index++];
            }
        }
        while(num1_index<nums1Size){
            nums3[num3_index++] = nums1[num1_index++];
        }
        while(num2_index<nums2Size){
            nums3[num3_index++] = nums2[num2_index++];
        }
        if(num3_index%2 != 0){
            return nums3[num3_index/2];
        }else{
            double a = nums3[num3_index/2 - 1];
            double b = nums3[num3_index/2];
            double temp = (a+b)/2;
            return temp;
        }
    }
};
