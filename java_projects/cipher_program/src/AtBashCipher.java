public class AtBashCipher extends Cipher{

    // Empty constructor
    public AtBashCipher() {}
    public AtBashCipher(String Text)
    {
        super(Text);
    }
    @Override
    public StringBuilder encryption()
    {
        StringBuilder decryptedText = new StringBuilder();
        for(int i = 0;i<plainText.length();i++)
        {
            if(plainText.charAt(i) >= 'A' && plainText.charAt(i) <= 'Z')
            {
                decryptedText.append((char) ('Z' - plainText.charAt(i) + 'A'));
            }
            else if(plainText.charAt(i) == ' ')
            {
                decryptedText.append(plainText.charAt(i));
            }
        }
        return decryptedText;
    }
    @Override
    public StringBuilder decryption()
    {
        StringBuilder decryptedText = new StringBuilder();
        for(int i = 0;i<plainText.length();i++)
        {
            if(plainText.charAt(i) >= 'A' && plainText.charAt(i) <= 'Z')
            {
                decryptedText.append((char) ('Z' - plainText.charAt(i) + 'A'));
            }
            else if(plainText.charAt(i) == ' ')
            {
                decryptedText.append(plainText.charAt(i));
            }
        }
        return decryptedText;
    }
    public StringBuilder encryptionAndDecryptionHalf()
    {
        StringBuilder text = new StringBuilder();
        for(char c : plainText.toCharArray())
        {
            if(c >= 'A' && c <= 'M')
            {
                text.append((char) ('M' - c + 'A'));
            }
            else if(c >= 'N' && c <= 'Z')
            {
                text.append((char) ('Z' - c + 'N'));
            }
            else if(c == ' ')
            {
                text.append(c);
            }
        }
        return text;
    }
}