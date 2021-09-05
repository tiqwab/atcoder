pub fn main() {
    let n: i64 = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        s.trim().parse().unwrap()
    };

    let mut ans = 0;
    let mut acc = 2;
    while acc <= n {
        ans += 1;
        acc *= 2;
    }

    println!("{}", ans);
}
