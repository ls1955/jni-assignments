import java.util.Scanner;

class CaesarCipher {
    private native String getInput();

    private native String encrypt(String plaintext, int key);

    private native String decrypt(String ciphertext, int key);

    static {
        System.loadLibrary("CaesarCipher");
    }

    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        CaesarCipher cipher = new CaesarCipher();

        System.out.println("Enter plaintext: ");
        String input = cipher.getInput();
        System.out.println("Enter key to encrypt plaintext: ");
        int key = Integer.parseInt(scan.nextLine());

        String ciphertext = encrypt(input, key);
        System.out.println("Ciphertext: " + ciphertext);

        System.out.println("Enter ciphertext: ");
        input = cipher.getInput();
        System.out.println("Enter key to decrypt ciphertext: ");
        key = Integer.parseInt(scan.nextLine());

        String plaintext = decrypt(ciphertext, key);
        System.out.println("Plaintext: " + plaintext);
    }
}
