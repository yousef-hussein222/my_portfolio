import java.util.Map;
import java.util.TreeMap;
import java.util.TreeSet;

public class SimpleSubstitutionCipher extends Cipher {
    private String key;
    private TreeSet<Character>set;
    private TreeMap<Character,Character>map;

    // Empty Constructor
    public SimpleSubstitutionCipher(){}

    public SimpleSubstitutionCipher(String plainText,String key)
    {
        super(plainText);
        this.key = key;
        set = new TreeSet<>();
        map = new TreeMap<>();
        char c = 'a';
        for(int i = 0;i<26;i++)
        {
            set.add(c);
            map.put(c,c);
            c++;
        }
        for(char i : key.toCharArray())
        {
            set.remove(i);
        }
        c = 'a';
        for(char x : key.toCharArray())
        {
            map.put(c,x);
            c++;
        }
        c = 'f';
        for(char z : set)
        {
            map.put(c,z);
            c++;
        }
    }
    @Override
    public StringBuilder encryption()
    {
        StringBuilder encryptedText = new StringBuilder();
        for(char y: plainText.toCharArray())
        {
            if(y != ' ')
            {
                encryptedText.append(map.get(y));
            }
            else
            {
                encryptedText.append(y);
            }
        }
        return encryptedText;
    }
    @Override
    public StringBuilder decryption()
    {
        StringBuilder decryptedText = new StringBuilder();
        TreeMap<Character,Character>mp = new TreeMap<>();
        for(Map.Entry<Character,Character> entry : map.entrySet())
        {
            mp.put(entry.getValue(),entry.getKey());
        }
        for(char y: plainText.toCharArray())
        {
            if(y != ' ')
            {
                decryptedText.append(mp.get(y));
            }
            else
            {
                decryptedText.append(y);
            }
        }
        return decryptedText;
    }
}