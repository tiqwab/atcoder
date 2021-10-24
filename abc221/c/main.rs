fn convert(xs: &Vec<u32>) -> u32 {
    let mut ans = 0;
    for x in xs.iter() {
        ans *= 10;
        ans += x;
    }
    return ans;
}

pub fn main() {
    let mut s: Vec<u32>  = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        s.trim().chars().map(|x| x.to_digit(10).unwrap()).collect()
    };
    s.sort();
    s.reverse();

    let slen = s.len();

    let mut ans: u32 = 0;

    for bits in 0..(1 << slen) {
        let mut xs = vec![];
        let mut ys = vec![];

        for j in 0..slen {
            if (bits & (1 << j)) != 0 {
                xs.push(s[j]);
            } else {
                ys.push(s[j]);
            }
        }

        let xn = convert(&xs);
        let yn = convert(&ys);
        // println!("{} {}", xn, yn);
        ans = std::cmp::max(ans, xn * yn);
    }

    println!("{}", ans);
}
