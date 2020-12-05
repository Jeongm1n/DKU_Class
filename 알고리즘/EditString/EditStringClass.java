package Homework4;
import java.util.Stack;

public class EditStringClass {
	   private int cost[][];               // ����� �����ϱ� ���� 2���� �迭
	   private char edit[][];              // ������ �����ϱ� ���� 2���� �迭
	   private int Lx, Ly;                 // ���ڿ� x�� ���ڿ� y�� ���̸� �����ϱ� ���� ����
	   private int VI, VD, VC, Vmin;       // �� ���꿡 ���� ��������� �� �ּҰ� ������ ���� ����

	   public EditStringClass(int n, int m, String x, String y) {
	      if (x.equals(y)) {
	         System.out.println("Both strings are the same."); // �� ���ڿ��� ���� ��� ����
	         return;
	      }

	      Lx = n; 
	      Ly = m;

	      cost = new int[Lx + 1][Ly + 1];                // ���迭 �����Ҵ�
	      edit = new char[Lx + 1][Ly + 1];               // ����迭 �����Ҵ�

	      cost[0][0] = 0;                                // ������ ������� �����Ƿ� ù��°�� 0
	      edit[0][0] = '-';

	      for (int i = 1; i <= Lx; i++) {                // ù ��° ���� �������길 ����
	         cost[i][0] = cost[i - 1][0] + 1;
	         edit[i][0] = 'D';
	      }
	      for (int j = 1; j <= Ly; j++) {                // ù��° ���� ���Կ��길 ����
	         cost[0][j] = cost[0][j - 1] + 1;
	         edit[0][j] = 'I';
	      }

	      for (int i = 1; i <= Lx; i++) {
	         for (int j = 1; j <= Ly; j++) {
	            if (x.charAt(i - 1) == y.charAt(j - 1)) {// ������ ���ڿ��� ������ �� �ִ��� Ȯ��
	               cost[i][j] = cost[i - 1][j - 1];
	               edit[i][j] = 'C';
	            } else {                                 // �ּ� ����� �߻��ϴ� ��� ã��
	               VC = cost[i - 1][j - 1] + 2;          // ��ü ��� +2
	               VD = cost[i - 1][j] + 1;              // ���� ��� +1
	               VI = cost[i][j - 1] + 1;              // ���� ��� +1

	               if (VC <= VD && VC <= VI) {           // ��ü ����� ���� ���� ���
	                  Vmin = VC;
	                  edit[i][j] = 'C';
	               } else if (VD <= VC && VD <= VI) {    // ���� ����� ���� ���� ���
	                  Vmin = VD;
	                  edit[i][j] = 'D';
	               } else if (VI <= VC && VI <= VD) {    // ���� ����� ���� ���� ���
	                  Vmin = VI;
	                  edit[i][j] = 'I';
	               }
	               cost[i][j] = Vmin;                    // �ּҺ���� cost[i][j]�� ����
	            }
	         }
	      }
	      System.out.println("<cost>");                  // cost �׷��� ���
	      System.out.print("   ");
	      for (int i = 0; i <= Ly; i++) {                // Y�� ���� = ���� ����
	         System.out.print(i + "  ");
	      }
	      System.out.println();

	      for (int i = 0; i <= Lx; i++) {
	         System.out.print(i + "  ");                 // X�� ���� = ���� ����
	         for (int j = 0; j <= Ly; j++) {
	            System.out.print(cost[i][j] + "  ");
	         }
	         System.out.println();
	      }

	      System.out.println();
	      System.out.println("<edit>");                  // edit �׷��� ���
	      System.out.print("   ");
	      for (int i = 0; i <= Ly; i++) {                // Y�� ���� = ���� ����
	         System.out.print(i + "  ");
	      }
	      System.out.println();
	      for (int i = 0; i <= Lx; i++) {
	         System.out.print(i + "  ");                 // X�� ���� = ���� ����
	         for (int j = 0; j <= Ly; j++) {
	            System.out.print(edit[i][j] + "  ");
	         }
	         System.out.println();
	      }
	      findpath(edit);
	   }

	   private void findpath(char edit[][]) {            // ��� ��� �Լ�
	      int i = Lx;
	      int j = Ly;
	      Stack st = new Stack();                        // ���� ����
	      while (i >= 0 && j >= 0) { 
	         st.push("(" + i + "," + j + ")");

	         if (edit[i][j] == 'C') {                    // edit[i][j]�� ��ü�� i,j�� ��� ����
	            i--;
	            j--;
	         } else if (edit[i][j] == 'D') {             // edit[i][j]�� ������ i�� ����
	            i--;
	         } else                                      // edit[i][j]�� �����̸� i�� ����
	            j--;
	      }
	      System.out.println();
	      System.out.print("Path : " + st.pop());
	      while (!st.isEmpty()) {                        // pop�Ͽ� ��� ������� ���
	         System.out.print(" -> " + st.pop());
	      }
	   }

}
