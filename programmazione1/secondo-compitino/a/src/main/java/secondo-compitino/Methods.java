public class Methods {
    public static void editArray(int[] par, int a) {
	int sum = 0;
	int prod = 1;

	for(int i = 0; i < par.length; ++i) {
	    sum += par[i];
	    prod *= par[i];
	}

	if(a > (prod-sum) && a < (prod+sum)) {
	    for(int i = 0; i < par.length; ++i) {
		if(par[i] > a) {
		    par[i] = prod + sum;
		}
	    }
	} else {
	    for(int i = 0; i < par.length; ++i) {
		if(par[i] < a) {
		    par[i] = prod - sum;
		}
	    }
	}
    }

    public static int areEqual(int[] par1, int[] par2) {
	if(par1.length == par2.length) {
	    for(int i = 0; i < par1.length; ++i) {
		if(par1[i] != par2[i])
		    return 1;
	    }
	    return 0;
	}
	return -1;
    }
}
