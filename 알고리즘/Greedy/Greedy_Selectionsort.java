package Homework;

public class Greedy_Selectionsort {
	static void GreedySort(int a[], int n) {
		int temp;
		for (int i = 0; i < n - 1; i++) { // 효율성을 위해 n-1번만큼 반복
			int min = a[i]; // 남은 원소 중에서 최소값을 찾기 위한 기준
			int index = i;  // 남은 원소 중에서 최소 원소의 인덱스를 저장할 변수
			for (int j = i; j < n; j++) {  // 남은 원소들 비교
				if (min > a[j]) {
					min = a[j];
					index = j;
				}
			}
			temp = a[i];
			a[i] = min;       // 남은 원소 중에서 가장 작은 원소를
			a[index] = temp;  // 맨 앞의 원소와 교환

		}
		System.out.println("정렬 후 데이터");
		for (int i = 0; i < n; i++)
			System.out.print(a[i] + " ");
	}

	public static void main(String[] args) {
		int[] arr = { 10,9,8,7,6,5,4,3,2,1 }; // 정렬할 데이터 초기화
		System.out.println("정렬 전 데이터");
		for (int i = 0; i < 10; i++)
			System.out.print(arr[i] + " ");
		System.out.println();
		GreedySort(arr, 10);
	} 
} // 소프트웨어학과 32164420 조정민
