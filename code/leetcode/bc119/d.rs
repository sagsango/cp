impl Solution {
    pub fn number_of_sets(n: i32, max_distance: i32, roads: Vec<Vec<i32>>) -> i32 {
       let n:usize = n as usize;
       let mut g: Vec<Vec<(i32,i32)>> = Vec::with_capacity(n as usize);
       let mut d: Vec<Vec<i32>> =  Vec::with_capacity(n as usize);
       for i in 0..n {
            let row: Vec<(i32,i32)> = Vec::new();
            g.push(row);
            let row: Vec<i32> = vec![0; n]; // Vec::with_capacity(n as usize);
            d.push(row);
        }
        
        for edge in roads{
            let (u, v, w) = (edge[0], edge[1], edge[2]);
            g[u as usize].push((v,w));
            g[v as usize].push((u,w));
        }
        
        let mut ans:i32 = 0;
        
        for mask in 0..(1u64<<n) {
            for i in 0..n {
                for j in 0..n {
                    d[i][j] = 1_000_000_000;
                }
                d[i][i] = 0;
            }
            for x in 0..n{
                for y in 0..n{
                    for z in 0..n{
                        if  mask.wrapping_shr(x as u32) & 1 != 0 &&
                            mask.wrapping_shr(y as u32) & 1 != 0 && 
                            mask.wrapping_shr(z as u32) & 1 != 0 {
                            for edge in &g[x]{
                                let (k,w) = (edge.0, edge.1);
                                let k:usize = k as usize;
                                if mask.wrapping_shr(k as u32) & 1 != 0 {
                                    
                                    if (d[x][k] > w){
                                        d[x][k] = w;
                                    }
                                    
                                    if (d[k][x] > w){
                                        d[k][x] = w;
                                    }
                                    
                                    let dk = d[y][k] + d[k][x] + d[x][z];
                                    let dx = d[y][x] + d[x][k] + d[k][z];
                                    let _d = if dk > dx {dx} else {dk};
                                    
                                    if d[y][z]  > _d{
                                        d[y][z] = _d;
                                    }
                                    if d[z][y] > _d{
                                        d[z][y] = _d;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            
            let mut ok:bool = true;
            for x in 0..n{
                for y in 0..n{
                    if  mask.wrapping_shr(x as u32) & 1 != 0 &&
                        mask.wrapping_shr(y as u32) & 1 != 0 && 
                        d[x][y] > max_distance{
                            ok = false;
                    }
                }
            }
            if ok {
                ans += 1;
            }
            
        }
        return ans;
        
    }
}
