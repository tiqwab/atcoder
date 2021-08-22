use std::collections::{BTreeSet, HashMap};

pub fn main() {
    let (_H, _W, N) = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        let xs: Vec<usize> = s.trim().split(' ').map(|x| x.parse().unwrap()).collect();
        (xs[0], xs[1], xs[2])
    };

    let mut hs = vec![];
    let mut ws = vec![];

    for _ in 0..N {
        let (h, w) = {
            let mut s = String::new();
            std::io::stdin().read_line(&mut s).unwrap();
            let xs: Vec<i32> = s.trim().split(' ').map(|x| x.parse::<i32>().unwrap()).collect();
            (xs[0], xs[1])
        };
        hs.push(h);
        ws.push(w);
    }

    let h_map: HashMap<i32, i32> = hs.iter().cloned().collect::<BTreeSet<i32>>()
        .iter().enumerate().map(|(i, v)| {(*v, (i + 1) as i32)}).collect();

    let w_map: HashMap<i32, i32> = ws.iter().cloned().collect::<BTreeSet<i32>>()
        .iter().enumerate().map(|(i, v)| {(*v, (i + 1) as i32)}).collect();

    for i in 0..N {
        println!("{} {}", h_map.get(&hs[i]).unwrap(), w_map.get(&ws[i]).unwrap());
    }
}
