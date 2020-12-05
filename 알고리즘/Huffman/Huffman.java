package Homework.Huffman_Decode;

public class Huffman {
	public TreeNode HuffmanTree() throws Exception {
		MinHeap mh = new MinHeap(27);
		Count cnt = new Count();
		Element a, b, c;
		
		cnt.countFunc();							// ���ĺ� ���� ī��Ʈ
		cnt.print();								// ī��Ʈ�� ���� ���
		
		for (int i = 0; i < cnt.size; i++) {
			TreeNode node = new TreeNode();
			node.symbol = cnt.alphabet[i];
			a = new Element();
			a.key = node.weight = cnt.count[i];
			a.tree = node;
			mh.insert(a);
		}
		
		for (int i = 1; i < cnt.size; i++) {		// Huffman Ʈ�� ����
			a = new Element();
			b = new Element(mh.remove());
			c = new Element(mh.remove());
			TreeNode p = new TreeNode(b.tree, c.tree);
			a.key = p.weight = b.key + c.key;
			a.tree = p;
			mh.insert(a);
		}
		a = new Element(mh.remove());
		return a.tree;
	}
//////////////////// Huffman �ڵ� ��� �Լ� ////////////////////
	public void HuffmanPrint(TreeNode root, String str) {
		if (root == null)							// �� Ʈ���� ��� return			
			return;
		else if (root.leftChild == null && root.rightChild == null)
			System.out.println(root.symbol + ": " + str);
		else {
			String code = str;
			code += "0";
			HuffmanPrint(root.leftChild, code);
			code = str;
			code += "1";
			HuffmanPrint(root.rightChild, code);
		}
	}
}     // ����Ʈ�����а� 32164420 ������
