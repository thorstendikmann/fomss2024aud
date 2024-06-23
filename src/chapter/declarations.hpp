/*
This file contains declarations as a reference for exercises and exams.
It will not be used in source code elsewhere!
*/

#ifndef size_t
typedef unsigned long size_t;
#endif

// Array

typedef struct Array
{
    /** Maximum capacity. */
    int capacity;
    /** Current size. */
    int size;
    /** Memory location of the first element. */
    char *elements;
} Array;

void array_init(Array *a, int capacity);
void array_destroy(Array *a);
void array_insert(Array *a, int idx, char value);
void array_push_back(Array *a, char value);
char array_remove(Array *a, int idx);
char array_pop_back(Array *a);
int array_find(Array *a, char c);
char *array_at(const Array *a, int idx);

// LinkedList

typedef struct node
{
    struct node *next;
    char *value;
} node;

typedef struct LinkedList
{
    node *head;
    node *tail;
} LinkedList;

node *linkedlist_create_node(void);
void linkedlist_destroy_node(node *n);
void linkedlist_init(LinkedList *l);
void linkedlist_destroy(LinkedList *l);
size_t linkedlist_size(const LinkedList *l);
node *linkedlist_at(LinkedList *l, size_t index);
node *linkedlist_insert(LinkedList *l, size_t index, char value);
node *linkedlist_insert_after(LinkedList *l, node *item, char value);
node *linkedlist_push_front(LinkedList *l, char value);
node *linkedlist_push_back(LinkedList *l, char value);
void linkedlist_remove(LinkedList *l, node *item);
char linkedlist_remove_after(LinkedList *l, node *item);
char linkedlist_pop_front(LinkedList *l);
char linkedlist_pop_back(LinkedList *l);
node *linkedlist_find(LinkedList *l, char value);

// Stack & Queue

class Stack
{
public:
    Stack();
    ~Stack();

    void push(const char element);
    char pop();
    char top();

private:
    LinkedList *l;
};

class Queue
{
public:
    Queue();
    ~Queue();

    void enqueue(const char element);
    char dequeue();

private:
    LinkedList *l;
};

// TreeArray

typedef struct TreeArray
{
    size_t max_depth;
    char *elements;
} TreeArray;

void tree_initialize(TreeArray *t, size_t max_depth);
void tree_destroy(TreeArray *t);

size_t tree_set_left(TreeArray *t, char value, size_t parent);
size_t tree_set_right(TreeArray *t, char value, size_t parent);

void tree_print_dfs_preorder(TreeArray *t, size_t position);
void tree_print_dfs_postorder(TreeArray *t, size_t position);
void tree_print_dfs_inorder(TreeArray *t, size_t position);

// TreePtr

typedef struct TreePtr
{
    struct TreePtr *left;
    struct TreePtr *right;
    char value;
} TreePtr;

void tree_initialize(TreePtr *t);
void tree_destroy(TreePtr *t);

void tree_set(TreePtr *node, char value);
TreePtr *tree_set_left(TreePtr *parent, char value);
TreePtr *tree_set_right(TreePtr *parent, char value);

char tree_remove_right(TreePtr *node);
char tree_remove_left(TreePtr *node);

// BinTree

template <typename T>
class BinTree
{
    typedef BinTree<T> node;

public:
    explicit BinTree(const T &val);
    virtual ~BinTree();

    BinTree<T> *addLeft(const T &val);
    BinTree<T> *addRight(const T &val);

    std::string traverseDFS_preorder() const;
    std::string traverseDFS_postorder() const;
    std::string traverseDFS_inorder() const;
    std::string traverseBFS() const;

    node *left;
    node *right;
    T value;
};

// BinSearchTree

template <typename T>
class BinSearchTree : public BinTree<T>
{
    typedef BinSearchTree<T> node;

public:
    explicit BinSearchTree(const T &val);
    virtual ~BinSearchTree();

    virtual BinTree<T> *insert(const T &val) override;

protected:
    virtual BinTree<T> *getNewNode(const T &val) override;
};

// AVLTree

template <typename T>
class AVLTree : public BinSearchTree<T>
{
    typedef AVLTree<T> node;

public:
    explicit AVLTree(T val);
    virtual ~AVLTree();

    virtual BinTree<T> *balancedInsert(const T &val) override;
    BinTree<T> *rightRotate(BinTree<T> *y);
    BinTree<T> *leftRotate(BinTree<T> *x);

protected:
    virtual BinTree<T> *getNewNode(const T &val) override;
};

// Sorting

// Für die Sortierverfahren wird ein im Vergleich zu oben abgewandeltes Array zur Speicherung von Integer- anstatt Character-Werten verwendet.

typedef struct Array
{
    size_t capacity;
    size_t size;
    int *elements;  // char -> int
} Array;

void array_swap(Array *a, size_t i, size_t j);

void array_sort_selectionsort(Array *a);
void array_sort_insertionsort(Array *a);
void array_sort_bubblesort(Array *a);

void array_sort_heapsort(Array *a);
void heapify(Array *a, int N, int i);

void array_sort_mergesort(Array *a, size_t l, size_t r);
void merge(Array *a, size_t l, size_t m, size_t r);

void array_sort_quicksort(Array *a, int l, int r);
int partition(Array *a, int l, int r)