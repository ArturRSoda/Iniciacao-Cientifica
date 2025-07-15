
const HELLO_WORLD: &str = "Hello, World!";

fn another_function(x: i32) {
    println!("The value of x is: {}", x);
}

fn five() -> i32 {
    5
}

fn to_int(s: &str) -> i32 {
    return s.trim().parse().expect("Not number");
}

fn main() {
    /*
    let mut x = 5;
    println!("The value of x is: {}", x);
    x = 6;
    println!("The value of x is {}", x);
    */

    println!("{}\n", HELLO_WORLD);

    let x = 5;
    let x = x+1;
    {
        let x = x * 2;
        println!("The value of x in the inner scope is: {}", x);
    }
    println!("The value of x is: {}", x);

    let x: u32 = "42".parse().expect("Not a number!");
    println!("The value of x is: {}", x);

    let x = 5/3;
    println!("The value of x is: {}", x);

    let x = 5./3.;

    let mut x: (i32, f64, u8) = (500, 6.4, 1);
    println!("The value of x is: {:?}", x);
    println!("The value of x.0 is: {}", x.0);

    x.0 = 200;
    println!("The value of x is: {:?}", x);
    println!("The value of x.0 is: {}", x.0);

    let mut x: [i32; 5] = [3; 5];
    println!("The value of x is: {:?}", x);
    println!("The value of x.0 is: {}", x[0]);

    x[0] = 123;
    println!("The value of x is: {:?}", x);
    println!("The value of x.0 is: {}", x[0]);

    another_function(x[0]);

    let x = {
        let x = 3;
        x + 1
    };
    println!("The value of x is: {}", x);

    let x = five();
    println!("The value of x is: {}", x);

    let x = to_int("-43");
    println!("The value of x is: {}", x);

    let x = 3;
    if x < 5 {
        println!("x is less then 5");
    } else {
        println!("x is greater then 5");
    }

    let x = if false { 1 } else if true { 2 } else { 3 };
    println!("The value of x is: {}", x);

    let mut counter = 0;
    let x = loop {
        counter += 1;
        if counter == 10 {
            break counter * 2;
        }
    };
    println!("The value of x is: {}", x);


    let mut y = 0;
    'loop_y: loop {
        let mut x = 0;
        y += 1;

        'loop_x: loop {
            x += 1;
            if x > 3 { break 'loop_y; }
            println!("    The value of x is: {}", x);
        }

        if y == 3 { continue; }
        if y > 10 { break; }
        println!("The value of y is: {}", y);
    }

    let x = [1, 2, 3, 4];

    for element in x {
        println!("The value of element is: {}", element);
    }

    let mut i = 0;
    while i < x.len() {
        println!("The value of element is: {}", x[i]);
        i += 1;
    }

    for number in (1..4).rev() {
        println!("{number}!");
    }
    println!("LIFTOFF!!!!");

    for number in (1..4) {
        println!("{number}!");
    }
    println!("LIFTOFF!!!!");

    for e in (0..x.len()).rev() {
        println!("{}", x[e]);
    }
}


