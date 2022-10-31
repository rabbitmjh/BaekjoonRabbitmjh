import java.util.*;
import java.lang.*;
public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String a, b, ans = "";
		a = input.next();
		b = input.next();

		int sum = 0, carry = 0;
		int aLength = a.length();
		int bLength = b.length();
		
		while(true){
			int add = 0, aInt = 0, bInt = 0;
			if(aLength>0) {
				aInt = a.charAt(aLength - 1) - 48;
			}
			if(bLength>0) {
				bInt = b.charAt(bLength - 1) - 48;
			}
			sum = aInt + bInt + carry;
			add = sum % 10;
			carry = sum / 10;
			ans = ans + Integer.toString(add);
			aLength--;
			bLength--;
			if(aLength <= 0&&bLength <= 0) break;
		}
		if(carry == 1)ans = ans + Integer.toString(carry);
		for(int i = ans.length() - 1; i >= 0; i--) {
			System.out.printf("%c",ans.charAt(i));
		}
		input.close();
	}

}
