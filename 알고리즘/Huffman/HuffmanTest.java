package Homework.Huffman_Decode;
public class HuffmanTest {
	public static void main(String args[]) throws Exception {
		Huffman h = new Huffman();
		String str = "";
		TreeNode root = new TreeNode();
		root = h.HuffmanTree();						// Huffman 트리 생성
		System.out.println("Huffman Code : ");		// Huffman 코드 출력
		h.HuffmanPrint(root, str);
	}
}  // 소프트웨어학과 32164420 조정민