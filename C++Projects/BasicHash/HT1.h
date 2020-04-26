// The HashEntry class (in file HT1.h)
class HashEntry {
private:
	int key;
	int value;
public:
	HashEntry(int key, int value) {
		this->key = key;
		this->value = value;
	}
	int getKey() { return key; }
	int getValue() { return value; }
};

// The Hash Table itself (also in file HT1.h)
const int TABLE_SIZE = 128;
class HashMap {
private:
	HashEntry **table;
	int nextProbe(int hv, int i)
	{
		int retval = 0;
		//p(i) = h(K) + (–1)i–1((i + 1) / 2)2		cout << "In next Prove...(hv,i) " << hv << " , " << i << endl;		if (i == 0)
			retval = hv;
		else if (i % 2 == 1)
		{
			retval = hv + (i + 1)*(i + 1) / 4;
		}
		else
		{
			retval = hv - (i + 1)*(i + 1) / 4;
		}
		return retval;
	}
public:
	int countProbes = 0;
	HashMap() {
		table = new HashEntry*[TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; i++)
			table[i] = nullptr;
	}
	int get(int key) {
		int hash = (key % TABLE_SIZE);
		//int i = 0;
		while (++countProbes && table[hash] != nullptr && table[hash]->getKey() != key)
		{
			//hash = (hash + 1) % TABLE_SIZE;	//linear probe
			hash = nextProbe(hash, countProbes);			//Quadratic next?
			hash = (hash < 0) ? hash + TABLE_SIZE : hash - TABLE_SIZE;
		}
		if (table[hash] == nullptr)
			return -1;
		else
			return table[hash]->getValue();
	}
	void put(int key, int value) {
		int hash = (key % TABLE_SIZE); //Way too simple hash function
		while (++countProbes && table[hash] != nullptr && table[hash]->getKey() != key)
			hash = (hash + 1) % TABLE_SIZE;
		if (table[hash] != nullptr) // Key-value pairs are unique
			delete table[hash];
		table[hash] = new HashEntry(key, value);
	}
	~HashMap() {
		for (int i = 0; i < TABLE_SIZE; i++)
			if (table[i] != nullptr)
				delete table[i];
		delete[] table;
	}
	HashEntry* operator[](const int i)
	{
		return table[i];
	}
};
