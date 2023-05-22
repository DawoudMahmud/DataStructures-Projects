#ifndef ZIPTREE_H
#define ZIPTREE_H


#include <iostream>
#include <random>
#include <utility>
// explanations for public member functions are provided in project2.h
// each file that uses a WAVL tree should #include this file


template <typename KeyType, typename ValType>
class ZipTree
{
public:
	// DO NOT MODIFY METHOD SIGNATURES BELOW THIS LINE
	ZipTree();
	~ZipTree();
	static unsigned getRandomRank();
	void insert(const KeyType& key, const ValType& val, unsigned rank = getRandomRank());
	void remove(const KeyType& key);
	ValType find(const KeyType& key);
	unsigned getSize();
	int getHeight();
	unsigned getDepth(const KeyType& key);
	// DO NOT MODIFY METHOD SIGNATURES ABOVE THIS LINE
   
    unsigned size = 0;
    unsigned depth = 0;
    struct Node
    {
        ValType value;
        KeyType key;
        unsigned rank;
        int height = 0;
        Node *left = nullptr;
        Node *right = nullptr;
        
        Node(KeyType keyt, ValType valt)
        {
            key = keyt;
            value = valt;
        }
    };
    Node *root = NULL;
    Node *insertHelp(Node* &start, Node* n, unsigned rank)
    {
        if(start == nullptr)
        {
            n->left = NULL;
            n->right = NULL;
            n->rank = rank;
            start = n;
            return n;
        }
        if(start->key > n->key)
        {
            if(insertHelp(start->left, n, rank) == n)
            {
                if(start->rank > n->rank) start->left = n;
                else{
                    start->left = n->right;
                    n->right = start;
                    return n;
                }
            }
        }
        else
        {
            if (insertHelp(start->right, n, rank) == n)
            {
                if (n->rank <= start->rank) start->right = n;
                else {
                    start->right = n->left;
                    n->left = start;
                    return n;
                }
            }
        }
        return start;
    }
    int getHeightHelp(Node* start)
    {
        if (start == NULL)
            return 0;
        else {
            int left = getHeightHelp(start->left);
            int right = getHeightHelp(start->right);
            return left < right ? right + 1 : left + 1;
        }
    }
    int getDepthHelp(Node* start, KeyType key)
    {
        if (start == NULL || start->key == key)
            return 0;
        
        return start->key < key ? getDepthHelp(start->right,key) + 1 : getDepthHelp(start->left,key) + 1;
    }
    Node* search(Node* start, KeyType key)
    {
        {
            if (start == NULL) return 0;
            if(key == start->key) return start;
            return key < start->key ? search(start->left,key) : search(start->right,key);
        }
    }
    
private:
    

};



template <typename KeyType, typename ValType>
ZipTree<KeyType, ValType>::ZipTree()
{

}

template <typename KeyType, typename ValType>
ZipTree<KeyType, ValType>::~ZipTree()
{
    
}


template <typename KeyType, typename ValType>
unsigned ZipTree<KeyType, ValType>::getRandomRank()
{
    static std::default_random_engine generator(time(0));
    std::geometric_distribution<int> distribution(0.5);

    int number = distribution(generator);
    return number;
}

template <typename KeyType, typename ValType>
void ZipTree<KeyType, ValType>::insert(const KeyType& key, const ValType& val, unsigned rank)
{
    size++;
    Node* to_add = new Node(key, val);
    
    root = insertHelp(root, to_add, rank);

}

template <typename KeyType, typename ValType>
void ZipTree<KeyType, ValType>::remove(const KeyType& key)
{
	
}

template <typename KeyType, typename ValType>
ValType ZipTree<KeyType, ValType>::find(const KeyType& key)
{
    return search(root, key)->value;
}

template <typename KeyType, typename ValType>
unsigned ZipTree<KeyType, ValType>::getSize()
{
    return size;
}

template <typename KeyType, typename ValType>
int ZipTree<KeyType, ValType>::getHeight()
{
    return getHeightHelp(root) - 1;
}

template <typename KeyType, typename ValType>
unsigned ZipTree<KeyType, ValType>::getDepth(const KeyType& key)
{
    return getDepthHelp(root,key);
}

#endif

