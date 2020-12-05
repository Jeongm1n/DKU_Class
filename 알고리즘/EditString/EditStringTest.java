package Homework4;
import java.util.Scanner;

public class EditStringTest {
	   public static void main(String[] args) {
		      String X;
		      String Y;
		      int n, m;
		      Scanner sc = new Scanner(System.in);

		      System.out.println("Input your two string length");
		      System.out.print("Length of X : ");
		      n = sc.nextInt();
		      System.out.print("Length of Y : ");
		      m = sc.nextInt();
		      System.out.print("Input your X string : ");
		      X = sc.next();
		      System.out.print("Input your Y string : ");
		      Y = sc.next();
		      System.out.println();

		      EditStringClass ec = new EditStringClass(n, m, X, Y);
		   }

}
