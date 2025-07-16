#[derive(Debug, Clone)]
struct User {
    active: Option<bool>,
    username: Option<String>,
    email: Option<String>,
    sign_in_count: Option<u64>,
}

impl User {
    fn new() -> User {
        User {
            active: None,
            username: None,
            email: None,
            sign_in_count: None,
        }
    }
}

fn main() {
    let mut user = User::new();
    //user.username = Some(String::from("user1"));

    println!("{}", user.username.unwrap_or(String::from("user_withou_name")))
}
