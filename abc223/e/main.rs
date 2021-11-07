fn parse() -> (i64, i64, i64, i64, i64) {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let vs = s.trim().split(' ').map(|x| x.parse().unwrap()).collect::<Vec<i64>>();
    (vs[0], vs[1], vs[2], vs[3], vs[4])
}

fn solve(area_max_y: i64, area_max_x: i64, area1: i64, area2: i64, area3: i64) -> bool {
    // pattern 1:   |   |
    //            a | b | c
    //              |   |
    {
        let x1 = (area1 + (area_max_y - 1)) / area_max_y;
        let x2 = (area2 + (area_max_y - 1)) / area_max_y;
        let x3 = (area3 + (area_max_y - 1)) / area_max_y;
        if x1 + x2 + x3 <= area_max_x {
            return true;
        }
    }

    // pattern 2:   |   b
    //            a |-------
    //              |   c
    {
        let x1 = (area1 + (area_max_y - 1)) / area_max_y;
        let x_for_bc = area_max_x - x1;
        if x_for_bc > 0 {
            let y2 = (area2 + (x_for_bc - 1)) / x_for_bc;
            let y3 = (area3 + (x_for_bc - 1)) / x_for_bc;
            if y2 + y3 <= area_max_y {
                return true;
            }
        }
    }

    return false
}

pub fn main() {
    let (x, y, a, b, c) = parse();

    let mut ok = false;

    for (area_max_y, area_max_x) in vec![(y, x), (x, y)] {
        ok |= solve(area_max_y, area_max_x, a, b, c);
        ok |= solve(area_max_y, area_max_x, b, a, c);
        ok |= solve(area_max_y, area_max_x, c, a, b);
    }

    if ok {
        println!("Yes");
    } else {
        println!("No");
    }
}
