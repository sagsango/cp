Interval:
  - https://atcoder.jp/contests/abc360/tasks/abc360_f
    for given l how we will find the ans?

    
    init: // we will discuss later!
      precalculated_rdp[i] = all the intervals which starts before i and end after i; 

    // start reading from here:
    for l:
      for all interval where l[i] < l:
          r_dp[r[i]+1..inf] += 1; // what r should we choose so that the interval will interset with [l,r]
          precalculated_rdp[i] = all the intervals which starts before i and end after i; // already done
          now ans at this l will be some r where
          r_dp[r] +  precalculated_rdp[r] - (intervals which have l[i] <= l && r[i] >= i; this will be represneted by to_remove_dp); which is in line 
          to_remove_dp[0..r[i]] -= 1; // what are the intervals which are having l[i] < l && r < r[i]
          so here ans will be:
             r_dp[r] +  precalculated_rdp[r] - to_remve_dp[r]
             we have to choose the max one which we can do with the help of the rage update and point max query data structure.

