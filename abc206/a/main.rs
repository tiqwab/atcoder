pub fn main() {
    let s = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        s.trim().to_owned()
    };

    let n = s.parse::<i32>().unwrap();

    if 108 * n < 20600 {
        println!("Yay!");
    } else if 108 * n < 20700 {
        println!("so-so");
    } else {
        println!(":(");
    }
}
