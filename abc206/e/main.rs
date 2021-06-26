pub fn main() {
    let [l, r] = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        let v: Vec<i64> = s.trim().split(' ').map(|x| x.parse().unwrap()).collect();
        [v[0], v[1]]
    };

    let mut ans: i64 = 0;

    let mut arr = vec![0 as i64; (r + 1) as usize];

    for x in (2..=r).rev() {
        let mut acc: i64 = r / x - (l - 1) / x;
        acc = acc * (acc - 1) / 2;
        let mut y = x * 2;
        while y <= r {
            acc -= arr[y as usize];
            y += x;
        }
        arr[x as usize] = acc;
        ans += acc;
    }

    for x in std::cmp::max(l, 2)..r {
        ans -= r / x - 1;
    }

    ans *= 2;
    println!("{}", ans);
}
