package Homework;

public class Greedy_Selectionsort {
	static void GreedySort(int a[], int n) {
		int temp;
		for (int i = 0; i < n - 1; i++) { // ȿ������ ���� n-1����ŭ �ݺ�
			int min = a[i]; // ���� ���� �߿��� �ּҰ��� ã�� ���� ����
			int index = i;  // ���� ���� �߿��� �ּ� ������ �ε����� ������ ����
			for (int j = i; j < n; j++) {  // ���� ���ҵ� ��
				if (min > a[j]) {
					min = a[j];
					index = j;
				}
			}
			temp = a[i];
			a[i] = min;       // ���� ���� �߿��� ���� ���� ���Ҹ�
			a[index] = temp;  // �� ���� ���ҿ� ��ȯ

		}
		System.out.println("���� �� ������");
		for (int i = 0; i < n; i++)
			System.out.print(a[i] + " ");
	}

	public static void main(String[] args) {
		int[] arr = { 10,9,8,7,6,5,4,3,2,1 }; // ������ ������ �ʱ�ȭ
		System.out.println("���� �� ������");
		for (int i = 0; i < 10; i++)
			System.out.print(arr[i] + " ");
		System.out.println();
		GreedySort(arr, 10);
	}
} // ����Ʈ�����а� 32164420 ������
