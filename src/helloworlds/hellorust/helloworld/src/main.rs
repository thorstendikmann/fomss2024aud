use hellolib;

fn main() {
    println!("Hello, world!");

    let num = 10;
    println!("Hello, world! {num} plus one is {}!", hellolib::add_one(num));
}
