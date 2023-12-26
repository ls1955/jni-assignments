import java.util.Scanner;

class HouseLoan {
    private native float monthlyPayment(int loanAmount, float interestRate, int paymentPerYear, int numberOfYears);

    static {
        System.loadLibrary("HouseLoan");
    }

    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);

        System.out.println("Enter loan amount");
        int loanAmount = Integer.parseInt(scan.nextLine());
        System.out.println("Enter interest rate");
        float interestRate = Float.parseFloat(scan.nextLine());
        System.out.println("Enter payment per year");
        int paymentPerYear = Integer.parseInt(scan.nextLine());
        System.out.println("Enter number of year");
        int numberOfYears = Integer.parseInt(scan.nextLine());

        float monthlyPayment = new HouseLoan().calculateMonthyPayment(
            loanAmount, interestRate, paymentPerYear, numberOfYears;
        )

        System.out.println("Monthly payment: " + monthlyPayment);
    }
}
