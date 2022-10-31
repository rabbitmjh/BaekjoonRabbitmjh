import java.util.*;
import java.lang.*;
import java.math.*;
public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		BigInteger n, m;
		n = input.nextBigInteger();
		m = input.nextBigInteger();
		n = n.multiply(m);
		System.out.println(n);
	}

}
