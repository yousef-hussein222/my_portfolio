public class XORCipher extends Cipher{
    private String key;
    private int toDec(StringBuilder hex)
    {
        return Integer.parseInt(hex.toString(),16);
    }

    public XORCipher(){}
    public XORCipher(String plainText,String key)
    {
        super(plainText);
        this.key = key;
    }
    @Override
    public StringBuilder encryption()
    {
        StringBuilder encryptedText = new StringBuilder();
        int index = 0;
        for (char c : plainText.toCharArray())
        {
            char new_char  = (char) (c ^ key.charAt(index));
            encryptedText.append(new_char);
            index++;
            if (index == key.length())
            {
                index = 0;
            }
        }
        return encryptedText;
    }
    @Override
    public StringBuilder decryption()
    {
        StringBuilder decryptedText = new StringBuilder();
        StringBuilder newText = new StringBuilder();
        for(char c:plainText.toCharArray())
        {
            if(c != ' ')
            {
                newText.append(c);
            }
        }
        int index = 0;
        for (int i = 0;i<newText.length();i+=2)
        {
            StringBuilder hex = new StringBuilder();
            hex.append(newText, i, i+2);
            int dec = toDec(hex);
            char new_char  = (char) (dec ^ key.charAt(index));
            decryptedText.append(new_char);
            index++;
            if (index == key.length())
            {
                index = 0;
            }
        }
        return decryptedText;
    }
}