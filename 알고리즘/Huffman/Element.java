package Homework.Huffman_Decode;

public class Element {
	TreeNode tree;
	int key;
	
	Element() {					// ������
		tree = null;			// tree �ʱ�ȭ
		key = 0;
	}
	Element(Element e) {		// �Ű����� ���� ������
		tree = e.tree;
		key = e.key;
	}
}    // ����Ʈ�����а� 32164420 ������
