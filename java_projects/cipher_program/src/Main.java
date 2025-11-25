import java.util.Scanner;

public class Main
{
    public static int validChoice()
    {
        int choice;
        while(true)
        {
            Scanner input = new Scanner(System.in);
            System.out.printf("Enter your choice:%n");
            if(input.hasNextInt())
            {
                choice = input.nextInt();
                break;
            }
            else
            {
                System.out.printf("Enter only integers value!%n");
            }
        }
        return choice;
    }
    public static String vaildString()
    {
        String str;
        boolean flag = true;
        while (true)
        {
            Scanner input = new Scanner(System.in);
            str = input.nextLine();
            for (char c : str.toCharArray())
            {
                if(!Character.isLetter(c) && c != ' ')
                {
                    flag = false;
                    System.out.println("Enter only text not contain numbers or any other thing...!");
                    break;
                }
            }
            if(!flag)
            {
                flag = true;
                continue;
            }
            break;
        }
        return str;
    }
    //------------------------------------------------------------------
    public static void mainMenu()
    {
        System.out.println("*** Welcome to my program, for encryption and decryption. ***");
        System.out.printf("1)Start Program%n" + "2)Exit Program%n");
    }
    public static void CipherMenu()
    {
        System.out.println("*** Choose one cipher from the menu ***");
        System.out.printf("1- At bash cipher%n" + "2- Simple Substitution cipher%n"  + "3- XOR Cipher%n" + "4- Return to previous menu");
    }
    //------------------------------------------------------------------
    // Functions for AtBashCipher
    public static void menuAtBashCipher()
    {
        System.out.printf("Choose an option:%n" +"1- Encryption%n"+ "2- Decryption%n"+ "3- Return to previous menu%n");
    }
    public static void menuAtBashCipherEncryption()
    {
        System.out.printf("Choose an option:%n" +"1- Encryption using all letters%n"+ "2- Encryption using the middle of the letters%n"+ "3- Return to previous menu%n");
    }
    public static void menuAtBashCipherDecryption()
    {
        System.out.printf("Choose an option:%n" +"1- Decryption using all letters%n"+ "2- Decryption using the middle of the letters%n"+ "3- Return to previous menu%n");
    }
    public static StringBuilder atBashCipherAll()
    {
        System.out.println("Enter the message you want to Encrypt or Decrypt:");
        String str = vaildString();
        AtBashCipher atBashCipher = new AtBashCipher(str.toUpperCase());
        return atBashCipher.encryption();
    }
    public static StringBuilder atBashCipherHalf()
    {
        System.out.println("Enter the message you want to Encrypt or Decrypt:");
        String str = vaildString();
        AtBashCipher atBashCipher = new AtBashCipher(str.toUpperCase());
        return atBashCipher.encryptionAndDecryptionHalf();
    }
    //------------------------------------------------------------------
    // Functions for SimpleSubstitutionCipher
    public static void SimpleSubstitutionCipherMenu()
    {
        System.out.printf("Choose an option:%n" +"1- Encryption%n"+ "2- Decryption%n"+ "3- Return to previous menu%n");
    }
    public static boolean isUniqueWord(String key)
    {
        if(key.length() != 5)
        {
            return false;
        }
        for(int i = 0;i<key.length();i++)
        {
            for(int j = i+1;j<key.length();j++)
            {
                if(key.charAt(i) == key.charAt(j))
                {
                    return false;
                }
            }
        }
        return true;
    }
    public static String isValidKey()
    {
        String key;
        while(true)
        {
            key = vaildString();
            if(!isUniqueWord(key))
            {
                System.out.println("Enter key that consist from 5 unique letters...!");
                continue;
            }
            break;
        }
        return key;
    }
    public static StringBuilder simpleSubstitutionCipherEncryption()
    {
        System.out.println("Enter key for encryption:");
        String str1 = isValidKey();
        System.out.println("Enter the message you want to encrypt: ");
        String str2 = vaildString();

        SimpleSubstitutionCipher simpleSubstitutionCipher = new SimpleSubstitutionCipher(str2.toLowerCase(),str1.toLowerCase());
        return simpleSubstitutionCipher.encryption();
    }
    public static StringBuilder simpleSubstitutionCipherDecryption()
    {
        System.out.println("Enter key for decryption:");
        String str1 = isValidKey();
        System.out.println("Enter the message you want to decrypt: ");
        String str2 = vaildString();

        SimpleSubstitutionCipher simpleSubstitutionCipher = new SimpleSubstitutionCipher(str2.toLowerCase(),str1.toLowerCase());
        return simpleSubstitutionCipher.decryption();
    }
    //------------------------------------------------------------------
    // Functions for XORCipher
    public static void XORCipherMenu ()
    {
        System.out.printf("Choose an option:%n" +"1- Encryption%n"+ "2- Decryption%n"+ "3- Return to previous menu%n");
    }
    public static StringBuilder XORCipherEncryption()
    {
        System.out.println("Enter the message you want to encrypt: ");
        String str1 = vaildString();
        System.out.println("Enter key for encryption:");
        String str2 = vaildString();

        XORCipher xorCipher = new XORCipher(str1,str2);
        return xorCipher.encryption();
    }
    public static StringBuilder XORCipherDecryption()
    {
        System.out.println("Enter the message you want to decrypt: ");
        Scanner input = new Scanner(System.in);
        String str1 = input.nextLine();
        System.out.println("Enter key for decryption:");
        String str2 = vaildString();

        XORCipher xorCipher = new XORCipher(str1,str2);
        return xorCipher.decryption();
    }
    public static void printHex(StringBuilder text)
    {
        for(char c: text.toString().toCharArray())
        {
            System.out.print(String.format("%02x", (int) c) + " ");
        }
    }
    //------------------------------------------------------------------
    public static void implementOfMainMenu()
    {
        boolean flag1 = true,flag2 = true,flag3 = true,flag4 = true,flag5 = true,flag6 = true,flag7 = true;
        while(flag1)
        {
            mainMenu();
            switch (validChoice())
            {
                case 1:
                    while (flag2)
                    {
                        CipherMenu();
                        switch (validChoice())
                        {
                            case 1:
                                while(flag3)
                                {
                                    menuAtBashCipher();
                                    switch (validChoice())
                                    {
                                        case 1:
                                            while (flag4)
                                            {
                                                menuAtBashCipherEncryption();
                                                switch (validChoice())
                                                {
                                                    case 1:
                                                        System.out.println("*** Text: " + atBashCipherAll()+ " ***");
                                                        break;
                                                    case 2:
                                                        System.out.println("*** Text: " + atBashCipherHalf()+ " ***");
                                                        break;
                                                    case 3:
                                                        flag4 = false;
                                                        break;
                                                    default:
                                                        System.out.println("*** Enter a number 1 to 3 ***");
                                                }
                                            }
                                            flag4 = true;
                                            break;
                                        case 2:
                                            while (flag5)
                                            {
                                                menuAtBashCipherDecryption();
                                                switch (validChoice())
                                                {
                                                    case 1:
                                                        System.out.println("*** Text: " + atBashCipherAll() + " ***");
                                                        break;
                                                    case 2:
                                                        System.out.println("*** Text: " + atBashCipherHalf()+ " ***");
                                                        break;
                                                    case 3:
                                                        flag5 = false;
                                                        break;
                                                    default:
                                                        System.out.println("*** Enter a number 1 to 3 ***");
                                                }
                                            }
                                            flag5 = true;
                                            break;
                                        case 3:
                                            flag3 = false;
                                            break;
                                        default:
                                            System.out.println("*** Enter a number 1 to 3 ***");
                                    }
                                }
                                flag3 = true;
                                break;
                            case 2:// here cipher 2
                                while (flag6)
                                {
                                    SimpleSubstitutionCipherMenu();
                                    switch (validChoice())
                                    {
                                        case 1:
                                            System.out.println("*** Text: " + simpleSubstitutionCipherEncryption()+ " ***" );
                                            break;
                                        case 2:
                                            System.out.println("*** Text: " + simpleSubstitutionCipherDecryption()+ " ***");
                                            break;
                                        case 3:
                                            flag6 = false;
                                            break;
                                        default:
                                            System.out.println("*** Enter number from 1 to 3 ***");
                                    }
                                }
                                flag6 = true;
                                break;
                            case 3:
                                while (flag7)
                                {
                                    XORCipherMenu();
                                    switch (validChoice())
                                    {
                                        case 1:
                                            StringBuilder text = XORCipherEncryption();
                                            System.out.println("*** Text: " + text + " ***");
                                            System.out.print("*** Hexadecimal Representation: " );
                                            printHex(text);
                                            System.out.println(" ***");
                                            break;
                                        case 2:
                                            System.out.println("*** Text: " + XORCipherDecryption()+ " ***");
                                            break;
                                        case 3:
                                            flag7 = false;
                                            break;
                                        default:
                                            System.out.println("*** Enter number from 1 to 3 ***");
                                    }
                                }
                                flag7 = true;
                                break;
                            case 4:
                                flag2 = false;
                                break;
                            default:
                                System.out.println("*** Enter number from 1 to 3 ***");
                        }
                    }
                    flag2 = true;
                    break;
                case 2:
                    flag1 = false;
                    break;
                default:
                    System.out.println("*** Enter a number 1 or 2 ***");
            }
        }
    }
    //------------------------------------------------------------------
    public static void main(String []args)
    {
        implementOfMainMenu();
    }
}