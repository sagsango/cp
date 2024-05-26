
fn ok(x:usize, y:usize) -> bool {
    let x_i:i32 = x as i32;
    let y_i:i32 = y as i32;
    if (x == y) || (x_i + 1 == y_i) || (y_i + 1 == x_i) {
        return false;
    }
    return true;
}

fn idx(c:char) -> usize {
    return (c as usize) - ('a' as usize);
}

impl Solution {
    pub fn remove_almost_equal_characters(word: String) -> i32 {
        
    
        let mut arr:Vec<char> = word.chars().collect();
        let n:usize = arr.len();
        let mut dp:[[i32;26];100] = [[1_000_000_000;26];100];
        
        for j in 0..26 {
            dp[0][j] = 1;
            if j == idx(arr[0]) {
                dp[0][j] = 0;
            }
        }
        
        
        for i in 0..(n-1) {
            for j in 0..26 {
                for k in 0..26 {
                    if ok(j,k) {
                        let tmp = dp[i][j] + if k  !=  idx(arr[i+1]) {1}  else {0};
                        if tmp < dp[i+1][k] {
                            dp[i+1][k] = tmp;
                        }
                    }
                }
            }
        }
        
        
        let mut ans:i32 = 1_000_000_000;
        for j in 0..26 {
            if ans > dp[n-1][j] {
                ans = dp[n-1][j];
            }
        }
        
        return ans;
        
    }
}
