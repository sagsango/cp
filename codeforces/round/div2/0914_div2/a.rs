use std::io;
use std::collections::HashSet;


// Function to solve each test case
fn solve_test_case() {
    // Read input for each test case
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let mut iter = input_line.split_whitespace();
    
    // Read a and b
    let a: i32 = iter.next().unwrap().parse().unwrap();
    let b: i32 = iter.next().unwrap().parse().unwrap();

    // Read position of Lunchbox's king
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let mut iter = input_line.split_whitespace();
    let x_k: i32 = iter.next().unwrap().parse().unwrap();
    let y_k: i32 = iter.next().unwrap().parse().unwrap();

    // Read position of Lunchbox's queen
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let mut iter = input_line.split_whitespace();
    let x_q: i32 = iter.next().unwrap().parse().unwrap();
    let y_q: i32 = iter.next().unwrap().parse().unwrap();

    // Perform computations and print the result for each test case
    // You can implement the logic for the problem here
    let mut pos_k:[[i32;2];8] =  [[0; 2]; 8]; 
    let mut pos_q:[[i32;2];8] =  [[0; 2]; 8];
    let mut i_k:usize = 0;
    let mut i_q:usize = 0;

    for is_king in 0..2
    {
        for A_val in 0..2
        {
            for A_sign in 0..2
            {
                for B_sign in 0..2
                {
                    let mut A = a;
                    let mut B = b;

                    if A_val == 1
                    {
                        (A, B) = (B, A);
                    }

                    if A_sign == 1
                    {
                        A = -A;
                    }

                    if B_sign == 1
                    {
                        B = -B;
                    }

                    if is_king == 1
                    {
                        pos_k[i_k][0] = x_k + A;
                        pos_k[i_k][1] = y_k + B;

                        i_k += 1;
                    }
                    else
                    {
                        pos_q[i_q][0] = x_q + A;
                        pos_q[i_q][1] = y_q + B;

                        i_q += 1;
                    }
                }
            }
        }
    }


    let mut hashset: HashSet<i64> = HashSet::new();

    let mut ans:i32 = 0;

    for i in 0..8
    {
        for j in 0..8
        {
            //println!("cmp [{},{}] == [{},{}]", pos_k[i][0], pos_k[i][1], pos_q[j][0], pos_q[j][1]);
            let key:i64 = (pos_k[i][0] as i64) * 1000000000 +  pos_k[i][1] as i64;

            if pos_k[i][0] == pos_q[j][0] && pos_k[i][1] == pos_q[j][1] && !hashset.contains(&key)
            {
                ans += 1;
                hashset.insert(key);
            }
        }
    }


    println!("{}", ans);
    // For example, you can print the positions of the knight's moves:
    //println!("Possible knight moves for a={}, b={}: ", a, b);
    // Perform computations and print the result
}

fn main() {
    // Read the number of test cases
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let t: i32 = input_line.trim().parse().unwrap();

    // Process each test case
    for _ in 0..t {
        // Call the function to solve each test case
        //println!("Testcase:");
        solve_test_case();
    }
}

