use std::collections::HashMap;

struct MyBox{
    mp:HashMap<i32,i32>,
    k:i32,
}


impl MyBox{
    pub fn new(n:&i32) -> Self {
        let mp:HashMap<i32,i32> = HashMap::new();
        let k = *n;
        return Self{mp, k};
    }
    
    pub fn insert(&mut self, key:i32) -> bool {
        let mut f:i32 = 0;
        let val:i32;
        match self.mp.get(&key) {
            Some(&val) => { 
                f = val;
            },
            None => {
                
            }
        }
        if f + 1 <= self.k {
            f += 1;
            self.mp.insert(key,f);
            return true;
        }
        return false;
    }
    
    pub fn remove(&mut self, key:i32) -> () {
        let mut f:i32 = 0;
        let val:i32;
        match self.mp.get(&key) {
            Some(&val) => { 
                f = val;
            },
            None => {
                
            }
        }
        f -= 1;
        self.mp.insert(key,f);
    }
}


impl Solution {
    
    pub fn max_subarray_length(nums: Vec<i32>, k: i32) -> i32 {
        let mut o:MyBox = MyBox::new(&k);
        let n:usize = nums.len();
        let mut l:usize = 0;
        let mut r:usize = 0;
        let mut ans:usize = 0;
        
        
        while l < n {
            while r < n && o.insert(nums[r]) {
                r += 1;
            }
            if ans < r - l {
                ans = r - l;
            }
            
            o.remove(nums[l]);
            l += 1;
        }
        
        
        return ans as i32;
        
    }
}
