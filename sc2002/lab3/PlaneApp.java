import java.util.Scanner;

class PlaneApp {
    private static void printMenu() {
        System.out.print("(0) Exit \n" +
                "(1) Show the number of empty seats \n" +
                "(2) Show the list of empty seats \n" +
                "(3) Show the list of customers together with their seat numbers in the order of the seat numbers \n"
                +
                "(4) Show the list of customers together with their seat numbers in the order of the customer ID \n"
                +
                "(5) Assign a customer to a seat \n" +
                "(6) Remove a seat assignment\n");
    }

    private static void run(Scanner scanner) {
        Plane plane = new Plane();
        int customerId = 0;
        int seatId = 0;

        while (true) {
            printMenu();
            switch (scanner.nextInt()) {
                case 0:
                    return;
                case 1:
                    plane.showNumberEmptySeats();
                    break;
                case 2:
                    plane.showEmptySeats();
                    break;
                case 3:
                    plane.showAssignedSeats(true);
                    break;
                case 4:
                    plane.showAssignedSeats(false);
                    break;
                case 5:
                    System.out.print("seatId = ");
                    seatId = scanner.nextInt();
                    System.out.print("customerId = ");
                    customerId = scanner.nextInt();
                    plane.assignSeat(seatId, customerId);
                    break;
                case 6:
                    System.out.print("seatId = ");
                    seatId = scanner.nextInt();
                    plane.unAssignSeat(seatId);
                    break;
                default:
                    System.out.println("Unsupported option");
            }

        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        run(scanner);
        scanner.close();
    }
}
