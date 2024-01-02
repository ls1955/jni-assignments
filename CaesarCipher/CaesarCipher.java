class CaesarCipher {
    private native string getInput();

    private native encrypt(string plaintext, int key);

    private native decrypt(string ciphertext, int key);

    static {
        System.loadLibrary("CaesarCipher");
    }
}
