import java.util.Arrays;

class Plane {
    private PlaneSeat seats[] = new PlaneSeat[12];
    private int numEmptySeat = 12;

    public Plane() {
        for(int i = 0; i < seats.length; i ++) {
            seats[i] = new PlaneSeat(i+1);
        }
    }

    private PlaneSeat[] sortSeats() {
        PlaneSeat[] sortedSeats = seats.clone();
        Arrays.sort(sortedSeats, (PlaneSeat s1, PlaneSeat s2) -> s1.getCustomerId() - s2.getCustomerId());
        return sortedSeats;
    }

    public void showNumberEmptySeats() {
        System.out.println(this.numEmptySeat);
    }

    public void showEmptySeats() {
        for (PlaneSeat seat : seats) {
            if (!seat.isOccupied()) {
                System.out.printf("seatId = %d\n", seat.getSeatId());
            }
        }
    }

    public void showAssignedSeats(boolean bySeatId) {
        for (PlaneSeat seat : (bySeatId) ? seats : this.sortSeats()) {
            if(seat.isOccupied()) {
                System.out.printf("seatId = %d, customerId = %d\n", seat.getSeatId(), seat.getCustomerId());
            }
        }
    }

    public void assignSeat(int seatId, int customerId) {
        // warn if seat is already occupied
        if (seats[seatId - 1].isOccupied()) {
            System.out.println("Warning: Seat is already occupied");
            return;
        }

        seats[seatId - 1].assign(customerId);
        numEmptySeat--;
    }

    public void unAssignSeat(int seatId) {
        if (seats[seatId - 1].isOccupied()) {
            seats[seatId - 1].unAssign();
            numEmptySeat--;
        }
    }

}
