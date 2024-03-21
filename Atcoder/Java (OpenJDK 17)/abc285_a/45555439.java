import java.util.*;

class Main
{
  public static void main(String[] args)
  {
    Scanner scanner = new Scanner(System.in);
    int one = scanner.nextInt();
    int two = scanner.nextInt();
    if(two/2 == one)
      System.out.print("Yes");
    else
      System.out.print("No");
  }
}