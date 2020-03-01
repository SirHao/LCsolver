class Solution {
    //5344. 有多少小于当前数字的数字
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int len=nums.length;
        int []sorted=new int[len];
        sorted=nums.clone();

        HashMap<Integer,Integer> hm=new HashMap<Integer,Integer>();
        Arrays.sort(sorted);
        for (int i = 0;i < len;i++) {
            if (!hm.containsKey(sorted[i])) {
                hm.put(sorted[i],i);
            }
        }
    
        int []indexNums=new int[len];
        for (int i = 0;i < len;i++) { 
            indexNums[i] =hm.get(nums[i]);
        }

    return indexNums;
    }

    //5345. 通过投票对团队排名
    //自己写的还有bug，思路一样，先map映射再来找
    public String rankTeams(String[] votes) {
        //key是参赛团队，value是该团队每个排位获得的票数
        Map<Character, int[]> teamRankMap = new HashMap<>();

        for (String vote : votes) {
            for (int i = 0; i < vote.length(); i++) {
                int[] rankArr = teamRankMap.getOrDefault(vote.charAt(i), new int[26]);
                rankArr[i]++;
                teamRankMap.put(vote.charAt(i), rankArr);
            }
        }

        List<Map.Entry<Character, int[]>> teamRankList = new ArrayList<>(teamRankMap.entrySet());
        Collections.sort(teamRankList, (team1, team2) -> {
            int[] ranks1 = team1.getValue();
            int[] ranks2 = team2.getValue();
            //根据投票排序
            for (int i = 0; i < 26; i++) {
                if (ranks1[i] != ranks2[i]) {
                    return ranks2[i] - ranks1[i];
                }
            }
            //字母顺序排序
            return team1.getKey() - team2.getKey();
        });

        //转换为字符串输出
        return teamRankList.stream().map(entry -> String.valueOf(entry.getKey())).collect(Collectors.joining());
    }

    //5346. 二叉树中的列表
    public boolean dfs(ListNode head, TreeNode root){
        if (head == null) return true;
        if (root == null) return false;
        if (root.val != head.val) return false;
        return dfs(head.next, root.left) || dfs(head.next, root.right);
    }
    public boolean isSubPath(ListNode head, TreeNode root) {
        Queue<TreeNode> que=new LinkedList<>();
        que.offer(root);

        while (!que.isEmpty()){
            TreeNode q = que.poll();
            if (q == null) continue;

            if (q.val== head.val){
                if (dfs(head, q)) return true;
            }
            que.offer(q.left);
            que.offer(q.right);
        }
        return false;
    }

    //5347. 使网格图至少有一条有效路径的最小代价
    //个人时间原因，留个坑，先说下思路
    //BFS将能到达的所有点存下，此时到这些点的代价为0；
    //接下来就是记录将这些点周围没去过的点为起点，记录这些点最后能到达的点
    //此时代价为1；以此往复，直到右下角的点在可达范围；
    
}