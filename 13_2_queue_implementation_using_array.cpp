class Queue {

	int front, rear;
	vector<int> arr;

public:
	Queue()
	{
        //T= O(1) for all thr operations, S= O(N) for storing whole of the queue
		front = 0;
		rear = 0;
		arr.resize(100001);
	}

	// Enqueue (add) element 'e' at the end of the queue.
	void enqueue(int e)
	{
		// Write your code here.
		arr[rear]=e;
		rear++;
	}

	// Dequeue (retrieve) the element from the front of the queue.
	int dequeue()
	{
		// Write your code here.
		if(rear == front) return -1;
		return arr[front++];
	}
};