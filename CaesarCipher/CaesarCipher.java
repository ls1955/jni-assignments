class CaesarCipher {
    private native String getInput();

    private native String encrypt(String plaintext, int key);

    private native String decrypt(String ciphertext, int key);

    static {
        System.loadLibrary("CaesarCipher");
    }
}
