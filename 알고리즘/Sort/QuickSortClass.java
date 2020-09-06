package Homework;

public class QuickSortClass {
	private	int a[];
    private int aSize ;
    
    public QuickSortClass(int arr[], int n){  
    	a = arr;                             
    	aSize = n;
		a[n+1] = Integer.MAX_VALUE ;         

     }
    
    public int[] QuickSortCall() {
    	QuickSort(1, aSize);
    	return a ;
    }
    	
	 void QuickSort(int p, int q){
	       if (p < q) { 
	            int j = Partition(a, p, q+1);

	            QuickSort(p, j-1);
	            QuickSort(j+1,q);
	         
	       }
	   }
	 int Partition(int a[], int m, int p){
	       int v=a[m]; int i=m, j=p;
	       do {
	              do i++;
	              while (a[i] < v);
	              do j--;
	              while (a[j] > v);
	              if (i < j) Interchange(a, i, j);
	          } while (i < j);
	          a[m] = a[j]; a[j] = v; return(j);
	   }
	 
	 void Interchange(int a[], int i, int j){
		 int temp = a[i];
		 a[i] = a[j];
		 a[j] = temp;
	 }
	public static void main(String[] args) {
		int size[] = { 1000, 5000, 10000, 20000, 50000, 100000 };
		int[][] store = new int[6][];        // ������ ������ �迭

		for (int i = 0; i < 6; i++)
			store[i] = new int[size[i]+10];  // �迭�� ���� size

		System.out.println("QuickSort�� ��� : ");
		System.out.println(" [1000]  [5000]  [10000] [20000]  [50000]  [100000]");
		System.out.print(" ");
		for (int i = 0; i < 10; i++) {             // 10���� �����͸� �׽�Ʈ�ϱ� ���� for loop
			for (int j = 0; j < 6; j++) {          // ������ ũ�⸸ŭ 6�� ����
				for (int k = 0; k < size[j]; k++)  // �Ҵ���� ũ�⸸ŭ
					store[j][k] = (int) (Math.random()*size[j]); // ���� �Է�
			}
			for (int l= 0; l < 6; l++) {
				QuickSortClass quick = new QuickSortClass(store[l], size[l]);
				long start = System.nanoTime();    // ������ ���۽ð�
				store[l] = quick.QuickSortCall();
				long end = System.nanoTime();      // ������ ���� �ð�
				long execute=end-start;            // �����Ŀ� �ɸ� �ð�
				System.out.print(execute + "  ");
			}
			System.out.println();
			System.out.print("  ");
		}
		System.out.println("");
	}  // ����Ʈ�����а� 32164420 ������

}
