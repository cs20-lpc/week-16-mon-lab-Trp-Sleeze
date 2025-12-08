template <typename T>
void MinHeap<T>::siftUp(int i) {
    while (i > 0) {
        int p = parent(i);

        if (data[p] <= data[i])
            break;

        swap(data[p], data[i]);
        i = p;
    }
}

template <typename T>
void MinHeap<T>::siftDown(int i) {
    int n = data.size();

    while (true) {
        int l = left(i);
        int r = right(i);
        int m = i;

        if (l < n && data[l] < data[m])
            m = l;

        if (r < n && data[r] < data[m])
            m = r;

        if (m == i)
            break;

        swap(data[i], data[m]);
        i = m;
    }
}

template <typename T>
void MinHeap<T>::insert(const T& value) {
    data.push_back(value);
    siftUp(data.size() - 1);
}

template <typename T>
T MinHeap<T>::removeRoot() {
    if (empty())
        throw runtime_error("heap empty");

    T v = data[0];
    data[0] = data.back();
    data.pop_back();

    if (!empty())
        siftDown(0);

    return v;
}

template <typename T>
void MinHeap<T>::removeAt(int index) {
    if (index < 0 || index >= size())
        throw runtime_error("bad index");

    data[index] = data.back();
    data.pop_back();

    if (index < size()) {
        siftUp(index);
        siftDown(index);
    }
}
