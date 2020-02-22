
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


//no.1:从排序数组中删除重复项
int removeDuplicates(int* nums, int numsSize){
    if(numsSize==0){
        return 0;
    }
    int index=0;
    for(int i=0;i<numsSize;i++){
        if(nums[index]!=nums[i]){
            index++;
            nums[index]=nums[i];
        }
    }
    return index+1;
}

//no.2:买卖股票的最佳时机 II
int maxProfit(int* prices, int pricesSize){
    if(pricesSize==0) return 0;
    int money=0;
    for(int i=0;i<pricesSize-1;i++){
        if(prices[i]<prices[i+1]){
            money+=prices[i+1]-prices[i];
        }
    }
    return money;
}

//no.3:买卖股票的最佳时机 II
//本解法 超过98%
//一种巧妙的方法，超过92%：https://blog.csdn.net/weixin_39088580/article/details/82949403
void rotate(int* nums, int numsSize, int k){
    k=k%numsSize;
    if(numsSize!=0 && k!=0) {
        int tmp[k];
        for(int i=0;i<k;i++){
            tmp[i]=nums[numsSize-k+i];
        }
        for(int i=1;i<numsSize-k+1;i++){
            nums[numsSize-i]=nums[numsSize-i-k];
        }
        for(int i=0;i<k;i++){
            nums[i]=tmp[i];
        }
    }
}


//no.4: 存在重复
bool containsDuplicate(int* nums, int numsSize) {
    if(numsSize==0) return false;
    if(numsSize==1) return false;
    int max=nums[0];
    int abs=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]<0) {
            abs=0-nums[i];
            if(abs>max) max=abs;
        }else{
            if(nums[i]>max) max=nums[i];
        }
    }
    int bitmap[max+1];
    memset(bitmap, 0, max+1);
    int flag=0;

    for(int i=0;i<numsSize;i++){
        if(nums[i]<0) {
            flag=-1;
            nums[i]=0-nums[i];
        }
        else if(nums[i]>0) flag=1;
        else flag=2;                   //nums[i]=0

        switch(bitmap[nums[i]]){
            case 0:bitmap[nums[i]]=flag;break;
            case 1:
                if(flag==1) return true;
                else bitmap[nums[i]]=3;break;
            case -1:
                if(flag==-1) return true;
                else bitmap[nums[i]]=3;break;
            case 2:return true;
            case 3:return true;
        }
    }
    return false;
}
// 快排函数(升序)。
int compare(const void* a, const void* b) {
    return (*(int*)a)-(*(int*)b);
}
bool containsDuplicate2(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i-1])
            return true;
    }
    return false;
}


//no.5:只出现一次的数字
// 第二种 智商被秀了
int singleNumber(int* nums, int numsSize){
    if(numsSize==1) return nums[0];

    qsort(nums, numsSize, sizeof(int), compare);
    if(nums[0]!=nums[1])return nums[0];
    if(nums[numsSize-1]!=nums[numsSize-2]) return nums[numsSize-1];

    for(int i=1;i<numsSize-1;i++){
        if(nums[i]!=nums[i-1] && nums[i]!=nums[i+1])
            return nums[i];
    }
}
int singleNumber2(int* nums, int numsSize){
    int key, i;
    key = nums[0];
    //异或运算
    for (i = 1; i < numsSize; i++)
        key = key ^ nums[i];

    return key;
}

//no.6:两个数组的交集 II (c++)
//class Solution {
//public:
//    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//         map<int,int> MapNums;
//        for (int i=0;i<nums1.size();++i)
//        {
//            ++ MapNums[nums1[i]];
//        }
//
//        vector<int> vec;
//        for (int j=0;j<nums2.size();++j){
//            if(MapNums[nums2[j]]>0){
//                vec.push_back(nums2[j]);
//                --MapNums[nums2[j]];
//            }
//        }
//        return vec;
//    }
//};

//no.7: 加一
int* plusOne(int* digits, int digitsSize, int* returnSize){

    int *ret=(int *)malloc(sizeof(int)*(digitsSize+1));

    //*******x(x!=9)
    if(digits[digitsSize-1]<9){
        for(int i=0;i<digitsSize;i++){
            ret[i]=digits[i];
        }
        ret[digitsSize-1]+=1;
        ret[digitsSize]='\0';
        (*returnSize)=digitsSize;
        return ret;
    }


    //9999999
    int flag=1;
    int index;
    for(int i=digitsSize-1;i>-1;i--){
        if(digits[i]!=9) {
            index=i;flag=0;break;
        }
    }

    if(flag){
        ret[0]=1;
        for(int i=1;i<digitsSize+1;i++) ret[i]=0;
        (*returnSize)=digitsSize+1;
        return ret;
    }else{
        if(index==0) ret[index]=digits[index]++;
        else for(int i=0;i<index+1;i++) ret[i]=digits[i];
        ret[index]++;
        for(int i=index+1;i<digitsSize;i++) ret[i]=0;
        ret[digitsSize]='\0';
        (*returnSize)=digitsSize;
        return ret;
    }
}

//no.8移动零
void moveZeroes(int* nums, int numsSize){
    if(numsSize==1){
        return ;
    }
    int zero_count=0;
    int lianxu;
    for(int i=0;i<numsSize-zero_count;i++){
        if(nums[i]==0){
            lianxu=0;
            for(int j=i;j<numsSize-zero_count;j++){
                if(nums[j]!=0) break;
                lianxu++;
            }
            zero_count+=lianxu;
            for(int j=i;j<numsSize-lianxu;j++) nums[j]=nums[j+lianxu];
            for(int j=numsSize-lianxu;j<numsSize;j++) nums[j]=0;
        }
    }

}
void moveZeroes2(int* nums, int numsSize){
    if (numsSize == 0){
        return ;
    }
    int k = 0;
    for(int i=0;i<numsSize;i++){
        if(nums[i] != 0) {
            nums[k++] = nums[i];
        }
    }
    while(k < numsSize){
        nums[k] = 0;
        k++;
    }

}

//no.9两数之和
int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    int *result=(int*)malloc(sizeof(int)*2);
    (*returnSize)=2;
    if(numsSize==2) {
        result[0]=0;
        result[1]=1;
        return result;
    }
    for(int i=0;i<numsSize-1;i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j]==target)
            {

                result[0]=i;
                result[1]=j;
                return result;
            }
        }
    }
    return result;
}

//no.10有效的数独
bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    bool col[9][9] = {false};
    bool row[9][9] = {false};
    bool box[10][10] = {false};
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(board[i][j] == '.')
                continue;
            int num = board[i][j]-'0'-1;
            if(col[i][num] == true || row[j][num] == true || box[(i/3)*3+j/3][num] == true)
                return false;
            else{
                col[i][num] = true;
                row[j][num] = true;
                box[(i/3)*3+j/3][num] = true;
            }
        }
    }
    return true;
}

//no.11旋转图像
void rotateMatrix(int** matrix, int matrixRowSize, int *matrixColSizes) {

    int i, j;
    int temp;

    for(j = 0; j < matrixRowSize/2; j++)
        for(i = j; i < matrixRowSize - 1 - j; i++)
        {
            /* 旋转移位 */
            temp = matrix[j][i];
            matrix[j][i] = matrix[matrixRowSize - i - 1][j];
            matrix[matrixRowSize - i - 1][j] = matrix[matrixRowSize - j - 1][matrixRowSize - i - 1];
            matrix[matrixRowSize - j - 1][matrixRowSize - i - 1] = matrix[i][matrixRowSize - j - 1];
            matrix[i][matrixRowSize - j - 1] = temp;
        }
}



