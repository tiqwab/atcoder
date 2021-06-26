pub fn main() {
    let n: i64 = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        s.trim().parse().unwrap()
    };

    let xs: Vec<i32> = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        s.trim().split(' ').map(|x| x.parse().unwrap()).collect()
    };

    let mut map = std::collections::HashMap::<i32, i64>::new();
    for x in xs {
        *map.entry(x).or_insert(0) += 1;
    }

    let mut ans: i64 = 0;
    for (_k, v) in map {
        ans += (n - v) * v;
    }
    ans /= 2;
    println!("{}", ans);
}
