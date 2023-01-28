package ES3;

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
	int n = in.nextInt();
	
	int countTwo = 0;
	while(n % 2 == 0) {
	    countTwo++;
	    n /= 2;
	}

	String s = "";
	if(countTwo > 0)
	    s = "2 (" + countTwo + " volte) ";
	
	int nvolte = 0;
	for(int i = 3; i <= n / 2; i += 2){
	    nvolte = 0;
	    while(n % i == 0) {
		nvolte++;
		n /= i;
	    }

	    if(nvolte > 0)
		s = s + i + " (" + nvolte + " volte) ";
	}
	
	System.out.print(s);
	if(n > 2)
	    System.out.print(n + " (1 volta)");
    }
}
