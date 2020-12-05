package Homework.Huffman_Decode;
public class MinHeap {
	Element heap[];
	int size;
	
	MinHeap(int length) {						// ������
		heap = new Element[length+1];
		for (int i = 0; i < length+1; i++) {
			heap[i] = new Element();
			heap[i].tree = new TreeNode();
		}
		size = 0;
	}
	
	public void insert(Element e) {				// ���� �ռ�
		int index = ++size;
		
		while ((index != 1) && (e.key < heap[index/2].key)) {
			heap[index] = heap[index/2];
			index /= 2;
		}
		heap[index] = e;
	}
	
	public Element remove() {					// ���� �Լ�
		int parent, child;
		Element data, tmp;
		
		if (size < 0)
			return null;
		data = heap[1];
		tmp = heap[size--];
		parent = 1;
		child = 2;
		
		while (child <= size) {
			if ((child < size) && (heap[child].key > heap[child+1].key))
				child++;
			if (tmp.key <= heap[child].key)break;
			heap[parent] = heap[child];
			parent = child;
			child *= 2;
		}
		heap[parent] = tmp;
		return data;
	}
}     // ����Ʈ�����а� 32164420 ������