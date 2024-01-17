import java.util.Scanner;

class HouseLoan {
    private native float calculateMonthlyPayment(int loanAmount, float interestRate, int paymentPerYear, int numberOfYears);

    private native void printAmortizationTable(int loanAmount, float interestRate, float monthlyPayment);

    private native double calculatePrincipalPayment(float monthlyPayment, float interest);

    static {
        System.loadLibrary("HouseLoan");
    }

    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);

        // Montly payment section
        System.out.println("Enter loan amount");
        int loanAmount = Integer.parseInt(scan.nextLine());
        System.out.println("Enter interest rate");
        float interestRate = Float.parseFloat(scan.nextLine());
        System.out.println("Enter payment per year");
        int paymentPerYear = Integer.parseInt(scan.nextLine());
        System.out.println("Enter number of year");
        int numberOfYears = Integer.parseInt(scan.nextLine());

        HouseLoan houseLoan = new HouseLoan();

        float monthlyPayment = houseLoan.calculateMonthlyPayment(
            loanAmount, interestRate, paymentPerYear, numberOfYears
        );

        System.out.println("Monthly payment: " + monthlyPayment);

        // Amortization table section
        houseLoan.printAmortizationTable(loanAmount, interestRate, monthlyPayment);
    }
}
