fn assign_color(cur: i32, color: i32, colors: &mut Vec<i32>, edges: &Vec<Vec<i32>>) {
    if colors[cur as usize] != -1 {
        return;
    }
    colors[cur as usize] = color;
    for next in edges[cur as usize].iter() {
        if colors[*next as usize] == -1 {
            assign_color(*next, color ^ 1, colors, edges);
        }
    }
}

pub fn main() {
    let (n, q) = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        let xs: Vec<i32> = s.trim().split(' ').map(|x| x.parse::<i32>().unwrap()).collect();
        (xs[0], xs[1])
    };

    let mut edges: Vec<Vec<i32>> = vec![vec![]; n as usize];
    for _ in 0..(n - 1) {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        let xs: Vec<usize> = s.trim().split(' ').map(|x| {
            (x.parse::<usize>().unwrap()) - 1
        }).collect();
        edges[xs[0]].push(xs[1] as i32);
        edges[xs[1]].push(xs[0] as i32);
    }

    let mut colors = vec![-1; n as usize];
    assign_color(0, 0, &mut colors, &edges);

    #[cfg(debug)]
    println!("{:?}", colors);

    for _ in 0..q {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        let xs: Vec<usize> = s.trim().split(' ').map(|x| {
            (x.parse::<usize>().unwrap()) - 1
        }).collect();
        let (c, d) = (xs[0], xs[1]);
        if colors[c] == colors[d] {
            println!("Town");
        } else {
            println!("Road");
        }
    }
}
