#[derive(Debug)]
enum IpAddr {
    v4 {addr: String},
}

impl IpAddr {
    fn print(&self) {
        println!("something");
    }
}

enum Coin {
    Penny,
    Nickel,
    Dime,
    Quarter,
}

fn value_in_cents(coin: &Coin) -> u8 {
    match coin {
        Coin::Penny => 1,
        Coin::Nickel => 5,
        Coin::Dime => 10,
        Coin::Quarter => 25,
    }
}

fn add_one(x: &Option<i32>) {
    match x {
        None => None,
        Some(x) => Some(x+1),
    };
}

fn add_one_2(x: &mut i32) {
    *x+1;
}

fn add_string(s: &mut String) {
    s.push_str(", added");
}

fn main() {
    let addr = IpAddr::v4 {addr: String::from("1.1.1.1.1")};

    addr.print();

    let n1: i32 = 1;
    let n2: Option<i32> = Some(2);

    let n3 = n1 + n2.unwrap();
    println!("{}", n3);

    let coin = Coin::Nickel;
    let v = value_in_cents(&coin);
    let v2 = value_in_cents(&coin);
    println!("{}", v);

    let x: Option<i32> = Some(2);
    add_one(&x);
    match x {
        None => println!("x has no value!"),
        Some(x) => println!("x: {}", x),
    };

    let mut x2 = 2;
    add_one_2(&mut x2);
    println!("{}", x2);

    let mut s1 = String::from("Here");
    add_string(&mut s1);
    println!("{}", s1);
}
