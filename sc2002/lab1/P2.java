import java.util.Scanner;

class P2 {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int salary = s.nextInt();
    int merit = s.nextInt();
    s.close();

    char grade = ' ';
    if (salary >= 500 && salary < 600) {
      grade = 'C';
    } else if (salary >= 600 && salary < 650) {
      grade = (merit < 10) ? 'C' : 'B';
    } else if (salary >= 650 && salary < 700) {
      grade = 'B';
    } else if (salary >= 700 && salary < 800) {
      grade = (merit < 20) ? 'B' : 'A';
    } else if (salary >= 800 && salary < 900) {
      grade = 'A';
    }

    System.out.println("Grade: " + grade);
  }
}
