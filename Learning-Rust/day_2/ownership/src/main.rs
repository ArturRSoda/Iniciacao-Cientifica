fn main() {
    let s = String::from("hello");
    println!("{}", s);

    takes_ownership(s.clone());
    println!("{}", s);

    let x = 5;
    makes_copy(x);
    println!("{}", x);

    let y = 1;
    println!("{}", y);
    let y = add(y);
    println!("{}", y);


    let s: String = String::from("hello");
    let len: usize = calculate_length(&s);
    println!("the size of {} is {}", s, len);


    let mut s = String::from("hello");
    println!("{}", s);
    concatenate_string(&mut s, ", world!");
    println!("{}", s);


    let s = &mut String::from("hello");
    println!("{}", s);
    concatenate_string(s, ", world!");
    println!("{}", s);


    let mut s = String::from("hello");
    let r = &mut s;
    let d = r;
    println!("{}", d);
    concatenate_string(d, ", world!");
    println!("{}", d);



    let s = String::from("artur,luiz,rizzato,toru,soda");
    let fw = first_word_string(&s);
    println!("{}", fw);

    let vec = split_string(&s, ',');
    println!("{:?}", vec);
}

fn split_string(s: &str, sep: char) -> Vec<&str> {
    let mut vec = vec![];

    let bytes = s.as_bytes();
    let mut last_i = 0;
    for (i, &v) in bytes.iter().enumerate() {
        if v as char == sep {
            vec.push(&s[last_i..i]);
            last_i = i+1;
        }
    }

    vec.push(&s[last_i..]);

    vec
}


fn first_word_string(s: &String) -> &str {
    let bytes = s.as_bytes();

    for (i, &v) in bytes.iter().enumerate() {
        if v == b' ' {
            return &s[..i];
        }
    }

    return &s[..];
}

fn calculate_length(s: &String) -> usize {
    s.len()
}

fn concatenate_string(s: &mut String, c: &str) {
    s.push_str(c)
}

fn takes_ownership(s: String) {
    println!("{}", s);
}

fn makes_copy(x: i32) {
    println!("{}", x);
}

fn add(x: i32) -> i32 {
    x+1
}
