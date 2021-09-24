fn parse_line() -> (i32, i32) {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let xs: Vec<_> = s.trim().split(' ').map(|x| x.parse().unwrap()).collect();
    (xs[0], xs[1])
}

pub fn main() {
    let (l, q): (i32, i32) = parse_line();

    let mut se = std::collections::BTreeSet::new();
    se.insert(0);
    se.insert(l);

    for _ in 0..q {
        let (c, x): (i32, i32) = parse_line();
        if c == 1 {
            se.insert(x);
        } else {
            let l = se.range(..x).next_back().unwrap();
            let r = se.range(x..).next().unwrap();
            println!("{}", r - l);
        }
    }
}
