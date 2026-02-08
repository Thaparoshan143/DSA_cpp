#include<includes/Types.hpp>

// decleartion only..
template<typename K, typename H>
struct OpenHashTableProps;

using HashDType = uint16_t; // hash data type, currently uint16_t i.e 16 bit

template<typename K, typename H>
using HashFnCb = HashDType (*)(const K&, const OpenHashTableProps<K, H>&);

template<typename K, typename H>
struct OpenHashTableProps
{
    // use table size to be power of 2 i.e 2^x
    HashDType tableSize {};

    HashFnCb<K, H> hashFn {};
};

// this is container for each hash table entry
template<typename K, typename V>
struct HashTableNode
{
    Pair<K, V> keyVal {};
    HashTableNode *next {}; // linked list based next container for collision resolution
};

// Basic Fixed Size Hash Table, size must be known in initialization with hash function (callback..) to be used..
// This is currently the hash table that follows FIFO order, i.e new value overrides the old value stored.. no probing mechanism exists..
template<typename K, typename V, typename H = HashDType>
class HashTable
{
    public:
    HashTable() = delete;
    HashTable(const OpenHashTableProps<K, H>& htp): m_props(htp) { alloc(this, htp);   }

    ~HashTable() 
    {
        // cleanup..
        ClearEntries();
    }

    // give key and value for placement in hashtable
    H Place(const Pair<K, V>& kv)
    {
        const H hash { m_props.hashFn(kv.first, m_props) };

        // if no item is yet placed simply add new block..
        HashTableNode<K, V> *temp = new HashTableNode<K, V>;
        temp->keyVal = kv;
        temp->next = nullptr; // this might not be required.. (if initialization garuntee nullptr)

        if (!m_tableEntry[hash]) 
        {
            m_tableEntry[hash] = temp;
        }
        else 
        {
            HashTableNode<K, V> *last = getLastNode(m_tableEntry[hash]);
            last->next = temp;
        }

        std::cout << "key: " << kv.first << " || Hash: " << hash << std::endl;
        return hash;
    }

    const Pair<K, V>* Retrieve(const K& k) const 
    {
        const H hash { m_props.hashFn(k, m_props) };

        if (!m_tableEntry[hash])
            return nullptr;
        
        HashTableNode<K, V> *entry = m_tableEntry[hash];
        
        while (entry)
        {
            // check if the entry has same key or not..
            if (entry->keyVal.first == k)
            {
                return &entry->keyVal;
            }
            entry = entry->next;
        }

        return nullptr;
    }

    // for given hash return how many are in entry..
    uint GetEntryCountByHash(const H& hash)
    {
        uint count {};
        auto temp = m_tableEntry[hash];
        if (temp)
        {
            while(temp)
            {
                count++;
                temp = temp->next;
            }
        }
        return count;
    }

    // for given key, hashing the key return how many are in entry..
    uint GetEntryCountByKey(const K& k)
    {
        const H hash { m_props.hashFn(k, m_props) };

        uint count {};
        auto temp = m_tableEntry[hash];
        if (temp)
        {
            while(temp)
            {
                count++;
                temp = temp->next;
            }
        }
        return count;
    }

    const OpenHashTableProps<K, H>& GetOpenHashTableProps() {   return m_props; }

    void ClearEntries()
    {
        for (auto& item: m_tableEntry)
        {
            if (!item)
                continue;
            else if (!item->next)
            {
                delete item;
                item = nullptr;
            }
            else 
            {
                auto temp = item;
                while(temp)
                {
                    auto tempNext = temp->next;
                    delete temp;
                    temp = tempNext;
                }
                item = nullptr;
            }
        }
    }

    private:
    // not used but, optionally we can use flag param.. to indicate wheather the container is used or marked deleted..
    Vec<HashTableNode<K, V>*> m_tableEntry {};
    OpenHashTableProps<K, H> m_props {};

    // this traverse through linked list and get the last node..
    HashTableNode<K, V>* getLastNode(HashTableNode<K, V> *node)
    {
        while(node->next)
        {
            // std::cout << "Traversal: " << node << std::endl;
            node = node->next;
        }
        return node;
    }

    static void alloc(HashTable<K, V, H> *ht, const OpenHashTableProps<K, H>& htp)
    {
        // create the preallocated space..
        ht->m_tableEntry.reserve(htp.tableSize);
        for (int i=0;i<htp.tableSize;++i)
        {
            ht->m_tableEntry.push_back(nullptr);
        }
    }
};

// This hash function takes the key (string only) and simply returns the key size modulo to the tableSize from htp
template<typename K, typename H = HashDType>
static HashDType hash_func_mod(const K& k, const OpenHashTableProps<K, H>& htp)
{
    return k.size() % htp.tableSize; // assuming k to be string type
}

// This hash function takes the key (string), adds its ascii value and simply returns the value modulo to the tableSize from htp
template<typename K, typename H = HashDType>
static HashDType hash_func_ascii_mod(const K& k, const OpenHashTableProps<K, H>& htp)
{
    uint strVal {};

    // iterating over character..
    for (const auto& c: k)
    {
        strVal += static_cast<uint>(c);
    }

    return strVal % htp.tableSize;
}
