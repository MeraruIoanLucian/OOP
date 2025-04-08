#ifndef TREE_H
#define TREE_H

template<typename T>
class TreeNode {
public:
    T value;
    TreeNode<T>** children;
    TreeNode<T>* parent;
    int childCount;
    int capacity;

    TreeNode(const T& val) : value(val), childCount(0), capacity(2), parent(nullptr) {
        children = new TreeNode<T>*[capacity];
    }

    void detach_child(TreeNode<T>* child)
    {
        int pos = -1;
        for (int i = 0; i < childCount; i++)
        {
            if (child == children[i])
            {
                pos = i;
                break;
            }
        }
        if (pos >= 0)
        {
            for (int i = pos; i < childCount-1; i++)
            {
                children[i] = children[i+1];
            }
            childCount--;
        }
    }

    ~TreeNode() {
        std::cout << "Am intrat in destructor" ;
        std::cout << childCount <<std::endl;
        for (int i = 0; i < childCount; i++) {
            std::cout << " " << children[i]->value << std::endl;
            delete children[i];
        }
    }

    void addChild(TreeNode<T>* child) {
        if(childCount == capacity) {
            int newCapacity = capacity * 2;
            TreeNode<T>** newChildren = new TreeNode<T>*[newCapacity];
            for (int i = 0; i < childCount; i++) {
                newChildren[i] = children[i];
            }
            delete[] children;
            children = newChildren;
            capacity = newCapacity;
        }
        children[childCount++] = child;
        child->parent = this;
    }

    void insertChild(TreeNode<T>* child, int index) {
        if(index < 0 || index > childCount)
            index = childCount;
        if(childCount == capacity) {
            int newCapacity = capacity * 2;
            TreeNode<T>** newChildren = new TreeNode<T>*[newCapacity];
            for (int i = 0; i < childCount; i++)
                newChildren[i] = children[i];
            delete[] children;
            children = newChildren;
            capacity = newCapacity;
        }
        for (int i = childCount; i > index; i--) {
            children[i] = children[i-1];
        }
        children[index] = child;
        childCount++;
    }

    void sortChildren(int (*compareFunc)(const T&, const T&) = nullptr) {
        for (int i = 0; i < childCount-1; i++) {
            for (int j = 0; j < childCount - i - 1; j++) {
                int cmp = 0;
                if (compareFunc)
                    cmp = compareFunc(children[j]->value, children[j+1]->value);
                else
                    cmp = (children[j]->value < children[j+1]->value ? -1 :
                           (children[j]->value > children[j+1]->value ? 1 : 0));
                if (cmp > 0) {
                    TreeNode<T>* temp = children[j];
                    children[j] = children[j+1];
                    children[j+1] = temp;
                }
            }
        }
    }

    int countDescendants() const {
        int count = childCount;
        for (int i = 0; i < childCount; i++)
            count += children[i]->countDescendants();
        return count;
    }

    TreeNode<T>* find(bool (*compareFunc)(const T&, const T&), const T& target) {
        if(compareFunc(value, target))
            return this;
        for (int i = 0; i < childCount; i++) {
            TreeNode<T>* found = children[i]->find(compareFunc, target);
            if(found)
                return found;
        }
        return nullptr;
    }
};

template<typename T>
class Tree {
public:
    TreeNode<T>* root;
    Tree() : root(nullptr) { }
    ~Tree() { if (root) delete root; }

    TreeNode<T>* add_node(TreeNode<T>* parent, const T& value) {
        TreeNode<T>* node = new TreeNode<T>(value);
        if(parent == nullptr) {
            if(root == nullptr)
                root = node;
            else
                root->addChild(node);
        }
        else {
            parent->addChild(node);
        }
        return node;
    }

    void delete_node(TreeNode<T>* node) {
        std::cout << "intru in delete" << node->value << std::endl;
       if (node->parent != nullptr) {
            node->parent->detach_child(node);
        }
        delete node;
    }


    TreeNode<T>* get_node(TreeNode<T>* parent) { //vad parinte
        return (parent == nullptr ? root : parent);
    }

    TreeNode<T>* find(bool (*compareFunc)(const T&, const T&), const T& target) {
        return root ? root->find(compareFunc, target) : nullptr;
    }

    TreeNode<T>* insert(TreeNode<T>* parent, const T& value, int index) {
        TreeNode<T>* node = new TreeNode<T>(value);
        if(parent == nullptr) {
            if(root == nullptr)
                root = node;
            else
                root->insertChild(node, index);
        }
        else {
            parent->insertChild(node, index);
        }
        return node;
    }

    void sort(TreeNode<T>* node, int (*compareFunc)(const T&, const T&) = nullptr) {
        TreeNode<T>* target = (node == nullptr ? root : node);
        if(target)
            target->sortChildren(compareFunc);
    }

    int count(TreeNode<T>* node) const { //descendenti
        TreeNode<T>* target = (node == nullptr ? root : node);
        return target ? target->countDescendants() : 0;
    }
};

#endif // TREE_H