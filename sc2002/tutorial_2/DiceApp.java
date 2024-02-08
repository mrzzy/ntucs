import java.io.IOException;

class DiceApp {
  public static void main(String[] args) {
    try {
      System.out.print("Press <key> to roll the first dice");
      System.in.read();
      int first = new Dice().getValueOfDice();
      System.out.println(first);

      System.out.print("Press <key> to roll the second dice");
      System.in.read();
      int second = new Dice().getValueOfDice();
      System.out.println(second);

      System.out.printf("Your total number is %d\n", first + second);
    } catch (IOException e) {
      throw new RuntimeException(e);
    }
  }
}
