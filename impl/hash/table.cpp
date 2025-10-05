#include<includes/Types.hpp>

// returns 2^x
#define TWO_POW(v) (1 << v)
// returns 2^(x+1) - 1, i.e to mask high bit up to x bit positions
#define TWO_POW_MASK(v) ((1 << (v+1)) - 1)

// decleartion only..
template<typename T>
struct HashTableProps;

using HashDType = uint16_t; // hash data type, currently uint16_t i.e 16 bit

template<typename T>
using HashFnCb = HashDType (*)(const T&, const HashTableProps<T>&);

template<typename T>
struct HashTableProps
{
    // use table size to be power of 2 i.e 2^x
    HashDType tableSize {};

    HashFnCb<T> hashFn {};
};

// Basic Fixed Size Hash Table, size must be known in initialization with hash function (callback..) to be used..
// This is currently the hash table that follows FIFO order, i.e new value overrides the old value stored.. no probing mechanism exists..
template<class T>
class HashTable
{
    public:
    HashTable() = delete;
    HashTable(const HashTableProps<T>& htp): m_props(htp) { alloc(this, htp);   }

    ~HashTable()
    {
        delete m_entryTable;
        delete m_occupied;
    }

    HashDType Place(const T& e)
    {
        HashDType hashVal { m_props.hashFn(e, m_props) };
        m_entryTable[hashVal] = e;
        m_occupied[hashVal] = true;
        return hashVal;
    }

    // currently only read access retrieval
    const T* Retrieve(const HashDType hash) const
    {
        if (m_occupied[hash])
            return &m_entryTable[hash];
        
        return nullptr;
    }

    void Remove(const HashDType hash)
    {
        // currently actually not deleting, rather marking it as unoccupied to be override..
        if (m_occupied[hash])
            m_occupied[hash] = false;
    }

    // is the given hash entry available..
    bool IsOccupied(const HashDType hash)
    {
        return m_occupied[hash];
    }

    const HashTableProps<T>& GetHashTableProps()
    {
        return m_props;
    }

    void ClearEntries()
    {
        // warning: this marks all the table entry as available.. only flag are set, actual data will later be override
        for (auto& item: m_occupied)
        {
            item = false;
        }
    }

    private:
    // currently using different list for entry and occupied flag for ease..
    T *m_entryTable {};
    bool *m_occupied {};
    HashTableProps<T> m_props {};

    static void alloc(HashTable<T> *ht, const HashTableProps<T>& htp)
    {
        ht->m_entryTable = new T[htp.tableSize];
        ht->m_occupied = new bool[htp.tableSize];
    }
};

// This hash function takes the item and simply returns the modulo to the tableSize from htp
template<typename T>
HashDType hash_func_mod(const T& i, const HashTableProps<T>& htp)
{
    return i % htp.tableSize;
}
