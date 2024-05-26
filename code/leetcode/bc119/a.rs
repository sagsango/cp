
pub fn _count(nums1: &Vec<i32>, nums2: &Vec<i32>) -> i32 {
    let n : usize = nums1.len();
    let m : usize = nums2.len();
    let mut i : usize = 0;
    let mut c : usize = 0;
    while i < n { 
        let mut j : usize = 0;
        while j < m {
            if nums1[i] == nums2[j] {
                c += 1;
                break;
            }
            j += 1;
        }
        i += 1;
    }
    return c as i32;
}

impl Solution {
    pub fn find_intersection_values(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {

        return vec![ _count(&nums1,&nums2), _count(&nums2, &nums1)];

    }
}
