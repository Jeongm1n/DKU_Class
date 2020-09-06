package Homework;

public class MergeSortClass {
	private int a[], b[];
	private int aSize;

	public MergeSortClass(int arr[], int n) {
		a = arr;
		aSize = n;
		b = new int[aSize + 1];
	}

	public int[] MergeSortCall() {
		MergeSort(1, aSize);
		return a;
	}

	public void MergeSort(int low, int high) {
		if (low < high) {
			int mid = (low + high) / 2;
			MergeSort(low, mid);
			MergeSort(mid + 1, high);
			Merge(low, mid, high);
		}
	}

	public void Merge(int low, int mid, int high) {
		int h = low, i = low, j = mid + 1, k;
		while ((h <= mid) && (j <= high)) {
			if (a[h] <= a[j]) {
				b[i] = a[h];
				h++;
			} 
			else {
				b[i] = a[j];
				j++;
			}
			i++;
		}
		if (h > mid)
			for (k = j; k <= high; k++) {
				b[i] = a[k];
				i++;
			}
		else
			for (k = h; k <= mid; k++) {
				b[i] = a[k];
				i++;
			}
		for (k = low; k <= high; k++)
			a[k] = b[k];
	}

	public static void main(String[] args) {
		int size[] = { 1000, 5000, 10000, 20000, 50000, 100000 };
		int[][] store = new int[6][];   // ������ ������ �迭
		
		for (int i = 0; i < 6; i++)
			store[i] = new int[size[i]+10];  // �迭�� ���� size

		System.out.println("MergeSort�� ��� : ");
		System.out.println(" [1000]  [5000]  [10000] [20000]  [50000]  [100000]");
		System.out.print(" ");
		for (int i = 0; i < 10; i++) {               // 10���� �����͸� �׽�Ʈ�ϱ� ���� for loop
			for (int j = 0; j < 6; j++) {            // ������ ũ�⸸ŭ 6�� ����
				for (int k = 0; k < size[j]; k++)    // �Ҵ���� ũ�⸸ŭ 
					store[j][k] = (int) (Math.random()*size[j]);  // ���� �Է�
			}
			for (int l = 0; l < 6; l++) {
				MergeSortClass merge = new MergeSortClass(store[l], size[l]);
				long start = System.nanoTime();  // �պ����� ���۽ð�
				store[l] = merge.MergeSortCall();
				long end = System.nanoTime();    // �պ����� ���� �ð�
				long execute=end-start;          // �պ����Ŀ� �ɸ� �ð�
				System.out.print(execute + "  ");
			}
			System.out.println();
			System.out.print("  ");
		}
		System.out.println("");
	}  // ����Ʈ�����а� 32164420 ������

}
