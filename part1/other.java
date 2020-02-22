class Solution {
    //有效的括号
    public boolean isValid(String s) {
        int len=s.length();

        if(len==0)return true;

        if(len%2!=0) return false;
        
        char sf=s.charAt(0);
        if(sf=='}'|sf==')'|sf==']') return false;

        Stack<Character> cs=new Stack<Character>();
        for(int i =0;i<len;i++){
            sf=s.charAt(i);
            if(sf=='('|sf=='['|sf=='{'){
                cs.push(sf);
            }else{
                if(sf==')'){
                    if(cs.isEmpty()) return false;
                    if(cs.pop()!='(') return false;
                }else if(sf==']'){
                    if(cs.isEmpty()) return false;
                    if(cs.pop()!='[') return false;
                }else if(sf=='}'){
                    if(cs.isEmpty()) return false;
                    if(cs.pop()!='{') return false;
                }else return false;
            }
        }
        return cs.isEmpty();
    }

    //缺失数字
    //solution 1 :线性时间，额外线性空间：MAP
    //solution 2:nlogn时间，常数空间：排序
    //solution 3:满足线性时间 常数空间：100% 
    // public int missingNumber(int[] nums) {
    //     int sum = 0, n = nums.length;
    //     for (int i=0;i<n;i++) {
    //         sum += nums[i];
    //     }
    //     return   n * (n + 1)/2-sum;
    // }
    //solution 4:异或，同样最优   88.15%
     public int missingNumber(int[] nums) {
        int sum = 0, n = nums.length;
        for (int i=0;i<n;i++) {
            sum ^= nums[i]^(i+1);
        }
        return  sum;
    }
}