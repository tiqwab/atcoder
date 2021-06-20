pub fn main() {
    let s = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        s.trim().to_owned()
    };

    let (a, b) = {
        let mut ws = s.split_whitespace();
        let a: f64 = ws.next().unwrap().parse().unwrap();
        let b: f64 = ws.next().unwrap().parse().unwrap();
        (a, b)
    };

    println!("{}", a * b / 100.0);
}
