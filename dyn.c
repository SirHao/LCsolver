//
// Created by lucas on 2020/2/19.
//
//爬楼梯
int climbStairs(int n){
    int a[10000];
    if(n<4) return n;
    a[0]=0;a[1]=1;a[2]=2;a[3]=3;
    for(int i=4;i<n+1;i++){
        a[i]=a[i-1]+a[i-2];
    }
    return a[n];
}
// 买卖股票的最佳时机
int maxProfit(int* prices, int pricesSize){
    if(pricesSize<2) return 0;
    int maxp[pricesSize];
    int max;
    maxp[0]=0;
    maxp[1]=prices[1]-prices[0];
    int lowest=(prices[0]<prices[1])?prices[0]:prices[1];
    for(int i=2;i<pricesSize;i++){
        if(lowest>prices[i]){
            lowest=prices[i];
            maxp[i]=maxp[i-1];
        }else{
            maxp[i]=((prices[i]-lowest)>maxp[i-1])?(prices[i]-lowest):maxp[i-1];
        }
    }
    return (maxp[pricesSize-1]>0)?maxp[pricesSize-1]:0;
}
//最大子序和
int maxSubArray(int* nums, int numsSize){
    int max=nums[0];
    int n=nums[0];
    for(int i=1;i<numsSize;i++) {
        if(n>0)n+=nums[i];
        else n=nums[i];
        if(max<n)max=n;
    }
    return max;
}
//打家劫舍
int rob(int* nums, int numsSize){
    if(numsSize==0) return 0;
    if(numsSize==1) return nums[0];
    if(numsSize==2) return (nums[0]>nums[1])?nums[0]:nums[1];
    int dp[numsSize];
    dp[0]=nums[0];
    dp[1]=(nums[0]>nums[1])?nums[0]:nums[1];
    for(int i=2;i<numsSize;i++){
        dp[i]=(dp[i-1]>(dp[i-2]+nums[i]))?dp[i-1]:(dp[i-2]+nums[i]);
    }
    return dp[numsSize-1];
}