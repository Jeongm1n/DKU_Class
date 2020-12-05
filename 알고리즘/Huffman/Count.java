package Homework.Huffman_Decode;
import java.io.FileReader;

public class Count {
	Huffman h = new Huffman();
	int i, size;
	char alphabet[] = new char[27];					// ���ĺ� A~Z �����ϴ� �迭
	int count[] = new int[27];						// �� ���ĺ� �󵵼� �����ϴ� �迭
	
	Count() {
		for (i = 0; i < 26; i++)
			alphabet[i] = (char)(i+97);
		alphabet[i] = ' ';
		
		for (i = 0; i < 27; i++)
			count[i] = 0;
		size = alphabet.length;
	}
	
	public void countFunc() throws Exception {		// file�� �ҷ��ͼ� count
		String path = "C:\\Users\\USER\\Desktop\\������\\�����ڷ�\\3-1\\�˰���\\����\\����#3\\Text3.txt";					// ���� ��ġ ����
		FileReader fr = new FileReader(path);		// ���� open
		
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
	
	public void print() {							// ����Լ�
		for (i = 0; i < size; i++)					// ���� ���
			System.out.printf("%5c", alphabet[i]);
		System.out.println();
		for (i = 0; i < size; i++)					// �󵵼� ���
			System.out.printf("%5d", count[i]);
		System.out.println();
	}
}   // ����Ʈ�����а� 32164420 ������
