pub fn main() {
    let n: usize = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        s.trim().parse().unwrap()
    };

    let ss: Vec<i64> = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        s.trim().split(' ').map(|x| { x.parse().unwrap() }).collect()
    };

    let ts: Vec<i64> = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        s.trim().split(' ').map(|x| { x.parse().unwrap() }).collect()
    };

    let mut ans = vec![std::i64::MAX / 2; n];

    for i in 0..(2 * n) {
        ans[(i + 1) % n] = std::cmp::min(ans[i % n] + ss[i % n], ts[(i + 1) % n])
    }

    for x in ans.iter() {
        println!("{}", x);
    }
}
