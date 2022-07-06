class Solution {
    public int[] shuffle(int[] nums, int n) {
    
        int[] ans = new int[n*2];
        int i,j, k=0;
        for(i=0, j=n ; (i<n || j<n*2) ; ){
            if(k%2 == 0){
                ans[k++] = nums[i++]; 
            } else {
                ans[k++] = nums[j++];
            }
        }
        return ans;
    }
}
