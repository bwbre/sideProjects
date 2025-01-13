
template < typename T >
class List 
{
    const int size = 40;

public: 
    List();
    List(int newMax);
    ~List();
    List(const List<T> & listBeingCopied);
    List<T>& operator=(const List<T> & listBeingCopied);

    bool Insert(int pos, int insertedData);
    bool Remove(int pos);

    void Print() const;

private:
    // pointer to the list
    T *data;
    // current size -- number of positions filled
    int size;
    // current max size of list
    int maxSize;

    void Resize(int newSize);
    void Clone(const List<T> &) const;
    void Shift();
};


















