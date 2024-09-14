use std::cmp::Ordering;
use std::collections::BTreeSet;

fn main() {
    let (_n, x, y, z) = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        let ss: Vec<i64> = s.trim().split(' ').map(|x| x.parse::<i64>().unwrap())
            .collect();
        (ss[0], ss[1], ss[2], ss[3])
    };
    let scores_math = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        let ss: Vec<i64> = s.trim().split(' ').map(|x| x.parse::<i64>().unwrap())
            .collect();
        ss
    };
    let scores_english = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        let ss: Vec<i64> = s.trim().split(' ').map(|x| x.parse::<i64>().unwrap())
            .collect();
        ss
    };

    let mut ans = BTreeSet::new();

    let cmp_func: fn(&(usize, i64), &(usize, i64)) -> Ordering = |(ai, av), (bi, bv)| {
        if av != bv {
            av.cmp(bv)
        } else {
            // smaller id goes back
            bi.cmp(ai)
        }
    };

    {
        let mut ss: Vec<(usize, i64)> = scores_math.iter().cloned().enumerate().collect();
        ss.sort_by(cmp_func);
        ss.reverse();
        let ss = ss.iter().take(x as usize);
        for s in ss {
            ans.insert(s.0);
        }
    }

    {
        let mut ss: Vec<(usize, i64)> = scores_english.iter().cloned().enumerate().collect();
        ss.sort_by(cmp_func);
        ss.reverse();
        let ss: Vec<(usize, i64)> = ss.into_iter().take((x + y) as usize).filter(|a| !ans.contains(&a.0)).take(y as usize).collect();
        for s in ss {
            ans.insert(s.0);
        }
    }

    {
        let mut ss: Vec<(usize, i64)> = scores_math.iter().cloned().zip(scores_english.iter().cloned()).map(|(a, b)| a + b).enumerate().collect();
        ss.sort_by(cmp_func);
        ss.reverse();
        let ss: Vec<(usize, i64)> = ss.into_iter().take((x + y + z) as usize).filter(|a| !ans.contains(&a.0)).take(z as usize).collect();
        for s in ss {
            ans.insert(s.0);
        }
    }

    for a in ans {
        println!("{}", a + 1);
    }
}