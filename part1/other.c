#include <stdint.h>

//
// Created by lucas on 2020/2/19.
//
//位1的个数
int hammingWeight(uint32_t n) {
    int result=0;
    while(n!=0){
        result+=(n-((n>>1)<<1));
        n=n>>1;
    }
    return result;
}

//汉明距离
int hammingDistance(int x, int y){
    return hammingWeight(x|y)-hammingWeight(x&y);
}
// 颠倒二进制位
uint32_t reverseBits(uint32_t n) {
    uint32_t result=0,i=0;
    while(i<32){
        result |= (n&0x1);

        if(i<31) result<<=1;
        n=n>>1;
        i++;
    }
    return result;
}