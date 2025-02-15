fn main() {
    let mut total = 0;
    for n in 1..1000 {
        if n % 3 == 0 {
            total += n;
            continue;
        }
        if n % 5 == 0 {
            total += n;
        }
    }
    println!("{}", total);
    assert_eq!(total, 233168);
}
