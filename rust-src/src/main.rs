fn flatten<T>(vec: Vec<Vec<T>>) -> Vec<T> {
    let mut new_vec: Vec<T> = Vec::new();
    for items in vec {
        for item in items {
            new_vec.push(item);
        }
    }

    new_vec
}

fn main() {
    let integers = vec![vec![1, 2], vec![3, 4], vec![5, 6]];
    let strings = vec![
        vec!["one", "two"],
        vec!["three", "four"],
        vec!["five", "six"],
    ];

    println!("{:?}", flatten(integers));
    println!("{:?}", flatten(strings));
}
