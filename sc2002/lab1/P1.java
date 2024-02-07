import java.util.Scanner;

class P1  {
  public static void main (String[] args) {
    // read a single chaater from the user ignoring case
    Scanner in = new Scanner(System.in);
    char c = in.next().toLowerCase().charAt(0);
    in.close();
    
    switch (c) {
      case 'a':
        System.out.println("Action movie fan");
        break;
      case 'c':
        System.out.println("Comedy movie fan");
        break;
      case 'd':
        System.out.println("Drama movie fan");
        break;
      default:
        System.out.println("Invalid choice");
    }
  
  }
}
