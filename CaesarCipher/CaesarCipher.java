class CaesarCipher {
    private native string getInput();

    private native string encrypt(string plaintext, int key);

    private native string decrypt(string ciphertext, int key);

    static {
        System.loadLibrary("CaesarCipher");
    }
}
