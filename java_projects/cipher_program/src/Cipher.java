public abstract class Cipher {
    protected String plainText;

    public Cipher(){}
    public Cipher(String plainText)
    {
        this.plainText = plainText;
    }
    public abstract StringBuilder encryption();
    public abstract StringBuilder decryption();
}