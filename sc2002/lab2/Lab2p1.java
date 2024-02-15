import java.util.Random;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Lab2p1 {
  private static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    int choice;
    do {
      System.out.println("Perform the following methods:");
      System.out.println("1: multiplication test");
      System.out.println("2: quotient using division by subtraction");
      System.out.println("3: remainder using division by subtraction");
      System.out.println("4: count the number of digits");
      System.out.println("5: position of a digit");
      System.out.println("6: extract all odd digits");
      System.out.println("7: quit");
      choice = sc.nextInt();
      switch (choice) {
        case 1:
          mulTest();
          break;
        case 2:
          System.out.println("m: ");
          int m = sc.nextInt();
          System.out.println("n: ");
          int n = sc.nextInt();

          System.out.println((divide(m, n)));
          break;
        case 3:
          System.out.println("m: ");
          m = sc.nextInt();
          System.out.println("n: ");
          n = sc.nextInt();
          System.out.println(modulus(m, n));
          break;
        case 4:
          System.out.println("integer:  ");
          System.out.println(countDigits(sc.nextInt()));
          break;
        case 5:
          System.out.println("n: ");
          n = sc.nextInt();
          System.out.println("digit: ");
          int digit = sc.nextInt();
          System.out.println(position(n, digit));
          break;
        case 6:
          System.out.println("integer:  ");
          System.out.println(extractOddDigits(sc.nextInt()));
          break;
        case 7:
          System.out.println("Program terminating ....");
      }
    } while (choice < 7);
    sc.close();
  }

  /* add method code here */
  public static void mulTest() {
    Random random = new Random();
    int nCorrect = 0;

    for (int i = 0; i < 5; i++) {
      int x = random.nextInt(0, 10);
      int y = random.nextInt(0, 10);
      System.out.printf("How much is %d times %d? ", x, y);
      int answer = sc.nextInt();
      if (x * y == answer) {
        nCorrect++;
      }
    }

    System.out.printf("%d out of 5 answers are correct.\n", nCorrect);
  }

  public static int divide(int m, int n) {
    return divideRemainder(m, n).quotient();
  }

  public static int modulus(int m, int n) {
    return divideRemainder(m, n).remainder();
  }

  private static int countDigits(int n) {
    if (n <= 0) {
      throw new IllegalArgumentException("Negative integers are not supported.");
    }
    return Integer.valueOf(n).toString().length();
  }

  private static DivisionResult divideRemainder(int m, int n) {
    int i = 0;
    while (m >= n) {
      m -= n;
      i++;
    }

    return new DivisionResult(i, m);
  }

  public static int position(int n, int digit) {
    String nString = Integer.valueOf(n).toString();
    int index = nString.lastIndexOf(Integer.valueOf(digit).toString());
    return (index == -1) ? -1 : nString.length() - index;
  }

  public static int extractOddDigits(int n) {
    if (n <= 0) {
      throw new IllegalArgumentException("Negative integers are not supported.");
    }

    String oddNumber = Integer.valueOf(n).toString().chars()
        .mapToObj(Character::toString)
        .filter(d -> Integer.valueOf(d) % 2 != 0)
        .collect(Collectors.joining());
    return (oddNumber.length() <= 0) ? -1 : Integer.valueOf(oddNumber);
  }

  private record DivisionResult(int quotient, int remainder) {
  };
}
