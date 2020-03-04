class CommonWeek1{
    //2020 03 04
    //994. 腐烂的橘子
    int[] dr = new int[]{-1, 0, 1, 0};
    int[] dc = new int[]{0, -1, 0, 1};
    public int orangesRotting(int[][] grid) {
        int row=grid.length;
        if(row==0) return 0;
        int col=grid[0].length;
        if(col==0) return 0;
        int day=0;
        //
        Queue<int[]> que=new LinkedList<>();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    que.offer(new int[]{i,j,0});
                }
            }
        }

        while(!que.isEmpty()){
            int []tmp=que.poll();
            for(int i=0;i<4;i++){
                int x=tmp[0]+dr[i];
                int y=tmp[1]+dc[i];
                if(x>-1 & x<row &y>-1 &y<col){
                    if(grid[x][y]==1){
                        que.offer(new int[]{x,y,tmp[2]+1});
                        grid[x][y]=2;
                    }
                }
            }
            day=tmp[2];
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return day;

    }

    //2020 03 04
    //86 分割链表
    public ListNode partition(ListNode head, int x) {
        if(head==null) return null;
        ListNode small=new ListNode(0);ListNode smallhead=small;
        ListNode big=new ListNode(0);ListNode bighead=big;
        int hassmall=0,hasbig=0;
        while(head!=null){
            if(head.val<x){
                hassmall=1;
                small.next=new ListNode(head.val);
                small=small.next;
            }else{
                hasbig=1;
                big.next=new ListNode(head.val);
                big=big.next;
            }

            if(head.next==null) break;
            head=head.next;
        }

        if(hassmall==0) return bighead.next;
        if(hasbig==0) return smallhead.next;

        small.next=bighead.next;
        return smallhead.next;

    }
    //2020 03 04
    //6. Z 字形变换
    public String convert(String s, int numRows) {
        if(numRows==1) return s;
        int len=s.length();
        StringBuilder ret=new StringBuilder("");
        int topIndex=(numRows-1)*2;

        for(int i=0;i<len;i=i+topIndex){
            ret.append(s.charAt(i));
        }
        int tmplen=(len/topIndex+1)*topIndex;

        for(int i=1;i<numRows-1;i++){
            for(int j=0;j<=tmplen;j=j+topIndex){
                if(j-i>0&j-i<len)
                    ret.append(s.charAt(j-i));
                if(j+i<len)
                    ret.append(s.charAt(j+i));
            }
        }
        for(int i=numRows-1;i<len;i=i+topIndex){
            ret.append(s.charAt(i));
        }
        return ret.toString();

    }


    //141. 环形链表
    //双指针方法
    public boolean hasCycle1_1(ListNode head) {
        if (head == null || head.next == null) {
            return false;
        }
        ListNode slow = head;
        ListNode fast = head.next;
        while (slow != fast) {
            if (fast == null || fast.next == null) {
                return false;
            }
            slow = slow.next;
            fast = fast.next.next;
        }
        return true;
    }
    //141. 环形链表
    //hashset（hashMap也可）方法，性能不佳,好处在于可以直接返回重复点（下一道题就ok了）
    public boolean hasCycle1_2(ListNode head) {
        Set<ListNode> nodesSeen = new HashSet<>();
        while (head != null) {
            if (nodesSeen.contains(head)) {
                return true;
            } else {
                nodesSeen.add(head);
            }
            head = head.next;
        }
        return false;
    }

    //2020 03 03
    //142. 环形链表 II  tecent
    public ListNode detectCycle(ListNode head) {
        if (head == null || head.next == null) {
            return null;
        }
        ListNode low=head;
        ListNode fast=head;

        int flag=0;
        while (fast != null && fast.next != null) {
            low = low.next;
            fast = fast.next.next;
            if (low == fast) {
                flag=1;break;
            }
        }

        if(flag==0) return null;
        ListNode ptr=head;
        while(true){
            if(ptr==low) return low;
            ptr=ptr.next;
            low=low.next;
        }

    }
    //2020 03 03
    //160. 相交链表：hashset同样效率低的惊人  tecent
    public ListNode getIntersectionNode1(ListNode headA, ListNode headB) {
        Set<ListNode> hs=new HashSet<>();
        if(headA==null || headB==null) return null;
        while(headA!=null){
            hs.add(headA);
            if(headA.next==null) break;
            headA=headA.next;
        }
        while(headB!=null){
            if(hs.contains(headB)) return headB;
            if(headB.next==null) break;
            headB=headB.next;
        }
        return null;
    }
    //160. 相交链表：双指针法又再次秀到了我的智商   tecent
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) return null;
        ListNode pA = headA, pB = headB;
        while (pA != pB) {
            pA = pA == null ? headB : pA.next;
            pB = pB == null ? headA : pB.next;
        }
        return pA;
    }


    //2020 03 03
    //61. 旋转链表    tecent
    public ListNode rotateRight(ListNode head, int k) {
        if(head==null) return head;
        if (k==0)return head;
        int len=1;
        ListNode countPtr=head;
        while(countPtr.next!=null){
            countPtr=countPtr.next;
            len++;
        }
        countPtr.next=head;
        k=k%len;
        for(int i=1;i<len-k;i++){
            head=head.next;
        }
        ListNode ret=head.next;
        head.next=null;
        return ret;

    }


}