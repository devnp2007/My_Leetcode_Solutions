class MyCircularQueue {
public:
    vector<int> q;
    int f, r, s, n;

    MyCircularQueue(int k) {
        n = k;
        q.resize(k);
        f = 0;
        r = -1;
        s = 0;
    }
    
    bool enQueue(int v) {
        if (isFull()) return false;
        r = (r + 1) % n;
        q[r] = v;
        s++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        f = (f + 1) % n;
        s--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return q[f];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return q[r];
    }
    
    bool isEmpty() {
        return s == 0;
    }
    
    bool isFull() {
        return s == n;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}
/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */