package Homework.Huffman_Decode;
public class HuffmanTest {
	public static void main(String args[]) throws Exception {
		Huffman h = new Huffman();
		String str = "";
		TreeNode root = new TreeNode();
		root = h.HuffmanTree();						// Huffman Ʈ�� ����
		System.out.println("Huffman Code : ");		// Huffman �ڵ� ���
		h.HuffmanPrint(root, str);
	}
}  // ����Ʈ�����а� 32164420 ������