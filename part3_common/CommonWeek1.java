class CommonWeek1{
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