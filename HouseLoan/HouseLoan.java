import java.util.Scanner;

class HouseLoan {
    private native double calculateMonthlyPayment(int loanAmount, double interestRate, int paymentPerYear, int numberOfYears);

    private native void printAmortizationTable(int loanAmount, double interestRate, double monthlyPayment);

    private native double calculatePrincipalPayment(double monthlyPayment, double interest);

    static {
        System.loadLibrary("HouseLoan");
    }

    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);

        // Montly payment section
        System.out.println("Enter loan amount");
        int loanAmount = Integer.parseInt(scan.nextLine());
        System.out.println("Enter interest rate");
        double interestRate = Double.parseDouble(scan.nextLine());
        System.out.println("Enter payment per year");
        int paymentPerYear = Integer.parseInt(scan.nextLine());
        System.out.println("Enter number of year");
        int numberOfYears = Integer.parseInt(scan.nextLine());

        HouseLoan houseLoan = new HouseLoan();

        double monthlyPayment = houseLoan.calculateMonthlyPayment(
            loanAmount, interestRate, paymentPerYear, numberOfYears
        );

        System.out.println("Monthly payment: " + String.format("%.2f",monthlyPayment));

        houseLoan.printAmortizationTable(loanAmount, interestRate, monthlyPayment);
    }
}
