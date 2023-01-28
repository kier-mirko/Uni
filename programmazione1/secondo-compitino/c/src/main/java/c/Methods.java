public class Methods {
    public static void occorrenzeElementi(int[] num, int a, int b) {
	for(int i = 0; i < num.length; ++i) {
	    if(num[i] < a)
		num[i] = b;
	    else if(num[i] > b)
		num[i] = a;
	}
    }

    public static int[] modificaElementi(int[] num, int[] copy) {
	int[] union = new int[num.length+copy.length];

	for(int i = 0, j = 0, k = 0; i < union.length; i += 2, ++j, ++k) {
	    union[i] = num[j];
	    union[i+1] = copy[k];
	}
	return union;
    }
}
