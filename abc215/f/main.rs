fn check(mid: i32, points: &Vec<(i32, i32)>, n: usize) -> bool {
    let mut i: usize = 0;
    let mut ly: i32 = std::i32::MAX / 2;
    let mut ry: i32 = std::i32::MIN / 2;

    for j in 0..n {
        while i < j && (points[j].0 - points[i].0).abs() >= mid {
            ly = std::cmp::min(ly, points[i].1);
            ry = std::cmp::max(ry, points[i].1);
            i += 1;
        }
        if points[j].1 - ly >= mid {
            return true;
        }
        if ry - points[j].1 >= mid {
            return true;
        }
    }

    return false;
}

pub fn main() {
    let n: usize = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        s.trim().parse().unwrap()
    };

    let mut points: Vec<(i32, i32)> = vec![];
    for _ in 0..n {
        let point: (i32, i32) = {
            let mut s = String::new();
            std::io::stdin().read_line(&mut s).unwrap();
            let point: Vec<i32> = s.trim().split(' ').map(|x| { x.parse().unwrap() }).collect();
            (point[0], point[1])
        };
        points.push(point)
    }
    points.sort();

    let mut left: i32 = 0;
    let mut right: i32 = std::i32::MAX / 2;
    while right - left > 1 {
        let mid = left + (right - left) / 2;
        if check(mid, &points, n) {
            left = mid;
        } else {
            right = mid;
        }
    }

    println!("{}", left);
}
