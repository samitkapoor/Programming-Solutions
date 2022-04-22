class MyHashMap
{
public:
    vector<int> keys;
    vector<int> values;

    MyHashMap()
    {
        keys = {};
        values = {};
    }

    void put(int key, int value)
    {
        int x = -1;

        for (int i = 0; i < (int)keys.size(); i++)
        {
            if (keys[i] == key)
                x = i;
        }

        if (x == -1)
        {
            keys.push_back(key);
            values.push_back(value);
        }
        else
        {
            values[x] = value;
        }
    }

    int get(int key)
    {
        int x = -1;
        for (int i = 0; i < (int)keys.size(); i++)
        {
            if (keys[i] == key)
            {
                x = i;
            }
        }

        if (x == -1)
            return -1;
        return values[x];
    }

    void remove(int key)
    {
        int x = -1;
        for (int i = 0; i < (int)keys.size(); i++)
        {
            if (keys[i] == key)
            {
                x = i;
            }
        }

        if (x != -1)
        {
            keys.erase(keys.begin() + x);
            values.erase(values.begin() + x);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */