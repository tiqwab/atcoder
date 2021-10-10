pub fn main() {
    let X: String = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        s.trim().to_string()
    };

    let N: usize = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        s.trim().parse().unwrap()
    };

    let mut people = vec![];
    for _ in 0..N {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        people.push(s.trim().to_string());
    }

    let mut pos = vec![0; 26];
    for (i, c) in X.chars().enumerate() {
        pos[(c as usize) - ('a' as usize)] = i;
    }

    people.sort_by(|s1, s2| {
        for (c1, c2) in s1.chars().zip(s2.chars()) {
            let p1 = pos[(c1 as usize) - ('a' as usize)];
            let p2 = pos[(c2 as usize) - ('a' as usize)];
            if p1 != p2 {
                return p1.cmp(&p2);
            }
        }
        s1.len().cmp(&s2.len())
    });

    for person in people.iter() {
        println!("{}", person);
    }
}
