use std::io;
fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).expect("failed to read input");
    let mut arr: [i32; 2] = [4, 5];
    let mut indx = 0;
  for byte in line.split_whitespace() {
        arr[indx] =byte.parse::<i32>().unwrap();
        indx = indx+1;

  }
  let condition = arr[1]/2 == arr[0];
  if condition
  {
    print!("Yes");
  }
  else
  {
    print!("No");
  }
}