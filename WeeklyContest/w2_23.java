import static java.lang.Math.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;


class Solution {

    //5169. 日期之间隔几天 easy https://leetcode-cn.com/problems/number-of-days-between-two-dates/
    public int daysBetweenDates(String date1, String date2) {
         Long re;
        SimpleDateFormat formatter =   new SimpleDateFormat( "yyyy-MM-dd");
        Date date11 = null;
        Date date22=null;
        try {
            date11 = formatter.parse(date1);
            date22 = formatter.parse(date2);
        } catch (ParseException e) {
            e.printStackTrace();
        }
        
        long d1=date11.getTime();
        long d2=date22.getTime();
        re=(d1-d2)/(86400000);

        int flag=(d1<d2)?-1:1;
        re=re*flag;
        return re.intValue();
    }
    //5170. 验证二叉树 medium https://leetcode-cn.com/problems/validate-binary-tree-nodes/
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        int count = 0;
        for(int i=0;i<n;i++){
            if(leftChild[i]==-1) count ++;
            if(rightChild[i]==-1) count ++;
        }
        return count==n+1;
    }
    //5171. 最接近的因数 medium https://leetcode-cn.com/problems/closest-divisors/
    public int[] closestDivisors(int num) {
        int v =(int) Math.sqrt(num + 2);
        int num1 = num + 1;
        int num2 = num + 2;
        int flag=0;
        
        for(int i = v; i > 0; i--)
        {
            if(num2 % i == 0) flag=2;   
            if(num1 % i == 0) flag=1;  
            if(flag==1){
                int []ret={i, num1/i};
                return ret;
            }else if(flag==2){
                int []ret= {i, num2/i};
                return ret;
            }
        }
        int []ret={1,num};
        return ret;
    }
    //5172. 形成三的最大倍数
    List<Integer>[] res=new List[3];
        for (int i=0;i<3;i++) res[i]=new ArrayList<>();
        int sum=0;
        //求和
        for(int i:digits){
            res[i%3].add(i);
            sum+=i;
        }
        //排序
        for(int i=0;i<3;i++) Collections.sort(res[i],Collections.reverseOrder());
        int flag=sum%3;
        //分情况讨论
        if(flag!=0){
            if(res[flag].size()>0) res[flag].remove(res[flag].size()-1);
            else if(res[3-flag].size()>1){
                res[3-flag].remove(res[3-flag].size()-1);
                res[3-flag].remove(res[3-flag].size()-1);
            }
            else {
                res[1].clear();
                res[2].clear();
            }
        }
        //合并求最后的结果
        res[0].addAll(res[1]);
        res[0].addAll(res[2]);
        Collections.sort(res[0],Collections.reverseOrder());
        StringBuilder sn=new StringBuilder();
        for(int i:res[0]){
           sn.append(i);
        }
        //前导零
        if(sn.length()!=0&&sn.charAt(0)=='0') return "0";
        return sn.toString();
}