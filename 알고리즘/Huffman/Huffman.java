package Homework.Huffman_Decode;

public class Huffman {
	public TreeNode HuffmanTree() throws Exception {
		MinHeap mh = new MinHeap(27);
		Count cnt = new Count();
		Element a, b, c;
		
		cnt.countFunc();							// 알파벳 개수 카운트
		cnt.print();								// 카운트한 개수 출력
		
		for (int i = 0; i < cnt.size; i++) {
			TreeNode node = new TreeNode();
			node.symbol = cnt.alphabet[i];
			a = new Element();
			a.key = node.weight = cnt.count[i];
			a.tree = node;
			mh.insert(a);
		}
		
		for (int i = 1; i < cnt.size; i++) {		// Huffman 트리 생성
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
//////////////////// Huffman 코드 출력 함수 ////////////////////
	public void HuffmanPrint(TreeNode root, String str) {
		if (root == null)							// 빈 트리일 경우 return			
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
}     // 소프트웨어학과 32164420 조정민
