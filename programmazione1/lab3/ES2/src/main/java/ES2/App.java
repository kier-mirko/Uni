package ES2;

import java.util.Scanner;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args )
    {
	Scanner in = new Scanner(System.in);
	String a, b, prefisso = "";

	System.out.println("Inserisci una stringa");
	a = in.nextLine();
	System.out.println("Inserisci una stringa");
	b = in.nextLine();

	for (int i = 0; i < a.length(); i++) {
	    if(a.charAt(i) == b.charAt(i))
		prefisso += a.charAt(i);
	    else
		break;
	}

	System.out.println(prefisso.length());
	in.close();
    }
}
