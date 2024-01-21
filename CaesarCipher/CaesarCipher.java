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

        String ciphertext = cipher.encrypt(input, key);
        System.out.println("Ciphertext: " + ciphertext);

        String plaintext = cipher.decrypt(ciphertext, key);
        System.out.println("Original text: " + plaintext);
    }
}
