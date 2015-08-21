
class BinaryMinHeap{
private:
	int *data;
	int headSize;
	int arraySize;

	int getLeftChildIndex(int nodeIndex){
		return 2*nodeIndex+1;
	}
	int getRightChildIndex(int nodeIndex){
		return 2*nodeIndex+2;
	}
	int getParentIndex(int nodeIndex){
		return (nodeIndex-1)/2;
	}
	

public:
	BinaryMinHeap(int size){
		data = new int[size];
		heapSize = 0;
		arraySize = size;
	}
	int getMinimum(){
		if(isEmpty()){
			throw string("Heap is empty");
		}else{
			return data[0];
		}
	}
	boolean isEmpty(){
		return (heapSize == 0);
	}
	void siftUp(int);
	void insert(int);
	void siftDown(int);
	void removeMin();

	~BinaryMinHeap(){
		delete[] data;
	}
};

void BinaryMinHeap::siftUp(int nodeIndex){
	int parentIndex, tmp;
	if(nodeIndex != 0){
		parentIndex = getParentIndex(nodeIndex);
		if(data[parentIndex] > data[nodeIndex]){
			tmp = data[parentIndex];
			data[parentIndex] = data[nodeIndex];
			data[nodeIndex] = tmp;
			siftUp(parentIndex);
		}
	}
}

void BinaryMinHeap::insert(int value){
	if(heapSize == arraySize){
		throw string("Heap's underlying storage is overflow");
	}else{
		data[heapSize] = value;
		siftUp(heapSize);
		++heapSize;
	}
}

void BinaryMinHeap::siftDown(int nodeIndex){
	int leftChildIndex, rightChildIndex, minIndex, tmp;
	leftChildIndex = getLeftChildIndex(nodeIndex);
	rightChildIndex = getRightChildIndex(nodeIndex);
	if(rightChildIndex >= heapSize){
		if(leftChildIndex >= heapSize){
			return;
		}
		else{
			minIndex = leftChildIndex;
		}
	}else{
		if(data[leftChildIndex] <= data[rightChildIndex]){
			minIndex = leftChildIndex;
		}else{
			minIndex = rightChildIndex;
		}
	}
	if(data[nodeIndex] > data[minIndex]){
		tmp = data[minIndex];
		data[minIndex] = data[nodeIndex];
		data[nodeIndex] = tmp;
		siftDown(minIndex);
	}
}

void BinaryMinHeap::removeMin(){
	if(isEmpty()){
		throw string("Heap is empty");
	}
	else{
		data[0] = data[--heapSize];
		if(heapSize > 0){
			siftDown(0);
		}
	}


}















