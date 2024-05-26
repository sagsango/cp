use std::io;

fn solve_test_case(n: usize, array: Vec<u32>) {
    // Implement your specific problem-solving logic here
    // This example simply calculates the sum of the elements in the array
    let mut arr:Vec<(i32,i32)> = Vec::new();
    let mut i:usize = 0;
    while i < n
    {
        arr.push((i as i32, array[i] as i32));
        i += 1;
    }

    arr.sort_by(|a, b| {
        a.1.cmp(&b.1).then_with(|| a.0.cmp(&b.0))
    });

    i = 0;

    while i < n
    {
        println!("[{},{}]", arr[i].0, arr[i].1);
        i += 1;
    }



    // Output the result for the current test case
}

fn main() {
    // Read the number of test cases
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let t: usize = input_line.trim().parse().unwrap();

    for _ in 0..t {
        // Read the length of the array for each test case
        let mut input_line = String::new();
        io::stdin().read_line(&mut input_line).unwrap();
        let n: usize = input_line.trim().parse().unwrap();

        // Read the elements of the array for each test case
        let mut input_line = String::new();
        io::stdin().read_line(&mut input_line).unwrap();
        let array: Vec<u32> = input_line
            .split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();

        // Solve the test case
        solve_test_case(n, array);
    }
}
