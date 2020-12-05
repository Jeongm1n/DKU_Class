package Homework.Huffman_Decode;
import java.io.FileReader;

public class Count {
	Huffman h = new Huffman();
	int i, size;
	char alphabet[] = new char[27];					// 알파벳 A~Z 저장하는 배열
	int count[] = new int[27];						// 각 알파벳 빈도수 저장하는 배열
	
	Count() {
		for (i = 0; i < 26; i++)
			alphabet[i] = (char)(i+97);
		alphabet[i] = ' ';
		
		for (i = 0; i < 27; i++)
			count[i] = 0;
		size = alphabet.length;
	}
	
	public void countFunc() throws Exception {		// file을 불러와서 count
		String path = "C:\\Users\\USER\\Desktop\\조정민\\수업자료\\3-1\\알고리즘\\과제\\과제#3\\Text3.txt";					// 파일 위치 설정
		FileReader fr = new FileReader(path);		// 파일 open
		
		i = 0;
		while((i = fr.read()) != -1) {
			char ch = (char)i;
			
			if (ch >= 97 && ch <= 122)
				count[i-97]++;
			else if (ch == 32)
				count[size-1]++;
			else
				continue;
		}
		fr.close();
		
		int tmp = 0;
		for (int j = 0; j < count.length-tmp; j++) {
			if (count[j] == 0) {
				for (int k = j; k < count.length-1; k++) {
					count[k] = count[k+1];
					alphabet[k] = alphabet[k+1];
				}
				j--;
				tmp++;
			}
		}
		size = size - tmp;
	}
	
	public void print() {							// 출력함수
		for (i = 0; i < size; i++)					// 문자 출력
			System.out.printf("%5c", alphabet[i]);
		System.out.println();
		for (i = 0; i < size; i++)					// 빈도수 출력
			System.out.printf("%5d", count[i]);
		System.out.println();
	}
}   // 소프트웨어학과 32164420 조정민
