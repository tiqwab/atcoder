const CHOKUDAI: &str = "chokudai";
const MOD: u64 = 1000 * 1000 * 1000 + 7;

pub fn main() {
    let s = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        s.trim().to_string()
    };

    let n = s.len();

    let mut dp: Vec<Vec<u64>> = vec![vec![0; n + 1]; CHOKUDAI.len() + 1];

    for p in dp[0].iter_mut() {
        *p = 1;
    }

    for i in 1..(dp.len()) {
        let c1: char = CHOKUDAI.chars().nth(i - 1).unwrap();
        for (j, c2) in s.chars().enumerate() {
            if c1 != c2 {
                dp[i][j + 1] = dp[i][j];
            } else {
                dp[i][j + 1] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }
        }
    }

    #[cfg(debug)]
    {
        for row in dp.iter() {
            for col in row.iter() {
                print!("{} ", col);
            }
            println!("");
        }
        println!("");
    }

    println!("{}", dp[CHOKUDAI.len()][n]);
}
