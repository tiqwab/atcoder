pub fn main() {
    let s: String = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        s.trim().to_owned()
    };

    let k: i32 = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        s.trim().parse().unwrap()
    };

    let mut acc_dot = vec![0; s.len() + 1];
    for (i, c) in s.chars().enumerate() {
        acc_dot[i + 1] = acc_dot[i];
        if c == '.' {
            acc_dot[i + 1] += 1;
        }
    }

    let mut ans = 0;
    let mut l = 0;
    let mut r = 0;
    while l < s.len() {
        while r + 1 < s.len() && acc_dot[r + 1] - acc_dot[l] <= k {
            r += 1;
        }
        ans = std::cmp::max(ans, r - l);
        l += 1;
    }
    println!("{}", ans);
}
