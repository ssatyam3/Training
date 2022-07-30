static int unboundedKnapsack(int W, int wt[], int val[],
                                int idx)
    {
  
        if (idx == 0) {
            return (W / wt[0]) * val[0];
        }
  
        int notTake
            = 0 + unboundedKnapsack(W, wt, val, idx - 1);

        int take = Integer.MIN_VALUE;
        if (wt[idx] <= W) {
            take = val[idx]
                + unboundedKnapsack(W - wt[idx], wt, val,
                                    idx);
        }
        return max(take, notTake);
    }
