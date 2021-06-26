pub fn main() {
    let s = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        s.trim().to_owned()
    };

    let n = s.parse::<i32>().unwrap();

    let mut acc = 0;
    for i in 1..100000 {
        acc += i;
        if acc >= n {
            println!("{}", i);
            break;
        }
    }
}
