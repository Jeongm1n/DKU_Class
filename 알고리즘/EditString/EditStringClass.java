package Homework4;
import java.util.Stack;

public class EditStringClass {
	   private int cost[][];               // 비용을 저장하기 위한 2차원 배열
	   private char edit[][];              // 연산을 저장하기 위한 2차원 배열
	   private int Lx, Ly;                 // 문자열 x와 문자열 y의 길이를 저장하기 위한 변수
	   private int VI, VD, VC, Vmin;       // 각 연산에 대한 비용을저장 및 최소값 저장을 위한 변수

	   public EditStringClass(int n, int m, String x, String y) {
	      if (x.equals(y)) {
	         System.out.println("Both strings are the same."); // 두 문자열이 같을 경우 종료
	         return;
	      }

	      Lx = n; 
	      Ly = m;

	      cost = new int[Lx + 1][Ly + 1];                // 비용배열 동적할당
	      edit = new char[Lx + 1][Ly + 1];               // 연산배열 동적할당

	      cost[0][0] = 0;                                // 연산이 적용되지 않으므로 첫번째는 0
	      edit[0][0] = '-';

	      for (int i = 1; i <= Lx; i++) {                // 첫 번째 열은 삭제연산만 적용
	         cost[i][0] = cost[i - 1][0] + 1;
	         edit[i][0] = 'D';
	      }
	      for (int j = 1; j <= Ly; j++) {                // 첫번째 행은 삽입연산만 적용
	         cost[0][j] = cost[0][j - 1] + 1;
	         edit[0][j] = 'I';
	      }

	      for (int i = 1; i <= Lx; i++) {
	         for (int j = 1; j <= Ly; j++) {
	            if (x.charAt(i - 1) == y.charAt(j - 1)) {// 비용없이 문자열을 변경할 수 있는지 확인
	               cost[i][j] = cost[i - 1][j - 1];
	               edit[i][j] = 'C';
	            } else {                                 // 최소 비용이 발생하는 경우 찾기
	               VC = cost[i - 1][j - 1] + 2;          // 교체 비용 +2
	               VD = cost[i - 1][j] + 1;              // 삭제 비용 +1
	               VI = cost[i][j - 1] + 1;              // 삽입 비용 +1

	               if (VC <= VD && VC <= VI) {           // 교체 비용이 가장 작은 경우
	                  Vmin = VC;
	                  edit[i][j] = 'C';
	               } else if (VD <= VC && VD <= VI) {    // 삭제 비용이 가장 작은 경우
	                  Vmin = VD;
	                  edit[i][j] = 'D';
	               } else if (VI <= VC && VI <= VD) {    // 삽입 비용이 가장 작은 경우
	                  Vmin = VI;
	                  edit[i][j] = 'I';
	               }
	               cost[i][j] = Vmin;                    // 최소비용을 cost[i][j]에 저장
	            }
	         }
	      }
	      System.out.println("<cost>");                  // cost 그래프 출력
	      System.out.print("   ");
	      for (int i = 0; i <= Ly; i++) {                // Y의 길이 = 열의 개수
	         System.out.print(i + "  ");
	      }
	      System.out.println();

	      for (int i = 0; i <= Lx; i++) {
	         System.out.print(i + "  ");                 // X의 길이 = 행의 개수
	         for (int j = 0; j <= Ly; j++) {
	            System.out.print(cost[i][j] + "  ");
	         }
	         System.out.println();
	      }

	      System.out.println();
	      System.out.println("<edit>");                  // edit 그래프 출력
	      System.out.print("   ");
	      for (int i = 0; i <= Ly; i++) {                // Y의 길이 = 열의 개수
	         System.out.print(i + "  ");
	      }
	      System.out.println();
	      for (int i = 0; i <= Lx; i++) {
	         System.out.print(i + "  ");                 // X의 길이 = 행의 개수
	         for (int j = 0; j <= Ly; j++) {
	            System.out.print(edit[i][j] + "  ");
	         }
	         System.out.println();
	      }
	      findpath(edit);
	   }

	   private void findpath(char edit[][]) {            // 경로 출력 함수
	      int i = Lx;
	      int j = Ly;
	      Stack st = new Stack();                        // 스택 선언
	      while (i >= 0 && j >= 0) { 
	         st.push("(" + i + "," + j + ")");

	         if (edit[i][j] == 'C') {                    // edit[i][j]가 교체면 i,j값 모두 감소
	            i--;
	            j--;
	         } else if (edit[i][j] == 'D') {             // edit[i][j]가 삭제면 i값 감소
	            i--;
	         } else                                      // edit[i][j]가 삽입이면 i값 감소
	            j--;
	      }
	      System.out.println();
	      System.out.print("Path : " + st.pop());
	      while (!st.isEmpty()) {                        // pop하여 경로 순서대로 출력
	         System.out.print(" -> " + st.pop());
	      }
	   }

}
