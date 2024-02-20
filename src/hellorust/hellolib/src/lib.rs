// See https://doc.rust-lang.org/book/ch11-01-writing-tests.html

pub fn add(left: usize, right: usize) -> usize {
    left + right
}

pub fn add_one(x: i32) -> i32 {
    x + 1
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = add(2, 2);
        assert_eq!(result, 4);
    }

    #[test]
    fn check_add_one(){
        let var: i32 = 41;
        let result: i32 = add_one(var);
        assert_eq!(result, 42);
    }
}