pub fn solve(n: usize, m: usize, bss: Vec<Vec<i32>>) -> bool {
    let mut yss: Vec<Vec<i32>> = vec![vec![-1; m]; n];
    let mut xss: Vec<Vec<i32>> = vec![vec![-1; m]; n];

    for (i, bs) in bss.iter().enumerate() {
        for (j, b) in bs.iter().enumerate() {
            yss[i][j] = (*b + 6) / 7;
            xss[i][j] = ((*b - 1) % 7) + 1;
        }
    }

    for i in 0..n {
        for j in 0..m {
            if i > 0 {
                if yss[i][j] != yss[i - 1][j] + 1 {
                    return false
                }
                if xss[i][j] != xss[i - 1][j] {
                    return false
                }
            }
            if j > 0 {
                if yss[i][j] != yss[i][j - 1] {
                    return false
                }
                if xss[i][j] != xss[i][j - 1] + 1 {
                    return false
                }
            }
        }
    }

    return true
}

pub fn main() {
    let (n, m): (usize, usize) = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        let xs: Vec<_> = s.trim().split(' ').map(|x| x.parse().unwrap()).collect();
        (xs[0], xs[1])
    };

    let bss: Vec<Vec<i32>> = {
        let mut acc = vec![];
        for _ in 0..n {
            let mut s = String::new();
            std::io::stdin().read_line(&mut s).unwrap();
            let xs: Vec<i32> = s.trim().split(' ').map(|x| x.parse().unwrap()).collect();
            acc.push(xs)
        }
        acc
    };

    if solve(n, m, bss) {
        println!("Yes");
    } else {
        println!("No");
    }
}
