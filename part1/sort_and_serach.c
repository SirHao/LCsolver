#include <stdbool.h>

//
// Created by lucas on 2020/2/15.
//
//no.1合并两个有序数组
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    if(n==0) return ;
    if(m==0) for(int i=0;i<n;i++) nums1[i]=nums2[i];

    int i=m-1,j=n-1;  //分别指向两个数组的最后一个数
    int k=m+n-1;
    while(i>=0 && j>=0)
    {
        if(nums1[i]>=nums2[j])
        {
            nums1[k--]=nums1[i];
            i--;
        }
        else
        {
            nums1[k--]=nums2[j];
            j--;
        }
    }
    while(j>=0)//将nums2中剩余元素复制到nums1中
    {
        nums1[k--]=nums2[j];
        j--;
    }

}

//no.2 第一个错误版本
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);
int firstBadVersion(int n) {
    int low = 1;
    int high = n;
    while(low < high){
        int mid = low+((high-low)>>1);
        if(isBadVersion(mid))
            high = mid;
        else
            low = mid+1;
    }
    return low;
}