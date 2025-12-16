#include <bits/stdc++.h>
#include <synchapi.h>

using namespace std;

#define endl '\n'

class Value
{
private:
    string name;
    string phone;
    string email;
public:
    Value() = default;
    Value(string& name,string& phone,string& email)
    {
        this->name = name;
        this->phone = phone;
        this->email = email;
    }
    Value& operator=(const Value& value)
    {
        if(this != &value)
        {
            this->name = value.name;
            this->phone = value.phone;
            this->email = value.email;
            return *this;
        }
        return *this;
    }
    void display() const
    {
        cout << "Name: " << name << ", Phone: " << phone << ", Email: " << email << endl;
    }
};

class AvlNode
{
public:
    int id;
    Value value;
    int height;
    AvlNode* leftChild;
    AvlNode* rightChild;
    explicit AvlNode(Value& value,int id)
    {
        this->id = id;
        this->height = 0;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
        this->value = value;
    }
    void display() const
    {
        cout << "ID: " << id<<", ";
        value.display();
    }
};

class AvlTree
{
private:
    AvlNode* root;

    int height(AvlNode* node)
    {
        return node ? node->height : -1;
    }

    int calcBalance(AvlNode* node)
    {
        return node ? height(node->leftChild) - height(node->rightChild) : 0;
    }

    AvlNode* leftLeftRotate(AvlNode* node)
    {
        AvlNode* leftNode = node->leftChild;
        node->leftChild = leftNode->rightChild;
        leftNode->rightChild = node;

        node->height = 1 + max(height(node->leftChild), height(node->rightChild));
        leftNode->height = 1 + max(height(leftNode->leftChild), height(leftNode->rightChild));

        return leftNode;
    }

    AvlNode* rightRightRotate(AvlNode* node)
    {
        AvlNode* rightNode = node->rightChild;
        node->rightChild = rightNode->leftChild;
        rightNode->leftChild = node;

        node->height = 1 + max(height(node->leftChild), height(node->rightChild));
        rightNode->height = 1 + max(height(rightNode->leftChild), height(rightNode->rightChild));

        return rightNode;
    }

    AvlNode* leftRightRotate(AvlNode* node)
    {
        node->leftChild = rightRightRotate(node->leftChild);
        return leftLeftRotate(node);
    }

    AvlNode* rightLeftRotate(AvlNode* node)
    {
        node->rightChild = leftLeftRotate(node->rightChild);
        return rightRightRotate(node);
    }

    AvlNode* insertHelper(AvlNode* node, int id, Value& value)
    {
        if (!node)
            return new AvlNode(value, id);

        if (id < node->id)
            node->leftChild = insertHelper(node->leftChild, id, value);
        else if (id > node->id)
            node->rightChild = insertHelper(node->rightChild, id, value);
        else
            return node;

        node->height = 1 + max(height(node->leftChild), height(node->rightChild));

        int balance = calcBalance(node);

        if (balance > 1 && id < node->leftChild->id)
            return leftLeftRotate(node);
        if (balance < -1 && id > node->rightChild->id)
            return rightRightRotate(node);
        if (balance > 1 && id > node->leftChild->id)
            return leftRightRotate(node);
        if (balance < -1 && id < node->rightChild->id)
            return rightLeftRotate(node);

        return node;
    }

    void inOrderHelper(AvlNode* start)
    {
        if(start != nullptr)
        {
            inOrderHelper(start->leftChild);
            start->display();
            cout << endl;
            inOrderHelper(start->rightChild);
        }
    }

    void treeStructureHelper(AvlNode* start, vector<string>& vec, int row, int col, int offset)
    {
        if (start == nullptr || row >= 20 || col >= 80 || col < 0)
            return;

        string idStr = to_string(start->id);

        for (size_t i = 0; i < idStr.length() && col + i < 80; ++i)
            vec[row][col + i] = idStr[i];

        if (start->leftChild)
            treeStructureHelper(start->leftChild, vec, row + 2, col - offset, offset / 2);

        if (start->rightChild)
            treeStructureHelper(start->rightChild, vec, row + 2, col + offset, offset / 2);
    }

public:
    AvlTree() : root(nullptr) {}

    bool insert(int id, Value& value)
    {
        if (search(id) == nullptr)
        {
            root = insertHelper(root, id, value);
            return true;
        }
        return false;
    }

    AvlNode* search(int id)
    {
        AvlNode* curr = root;
        while (curr)
        {
            if (id < curr->id)
                curr = curr->leftChild;
            else if (id > curr->id)
                curr = curr->rightChild;
            else
                return curr;
        }
        return nullptr;
    }

    void inOrder()
    {
        inOrderHelper(root);
    }

    AvlNode* getRoot()
    {
        return root;
    }

    void treeStructure()
    {
        vector<string> vec(20, string(80, ' '));
        treeStructureHelper(root, vec, 0, 40, 20);
        for (auto& it : vec)
            cout << it << endl;
    }
};

int validNumber()
{
    int choice;
    string input;
    while (true)
    {
        cin >> input;
        stringstream ss(input);
        if (ss >> choice && ss.eof())
        {
            break;
        }
        else
        {
            cout << "Enter only integers value!" << endl;
        }
    }
    return choice;
}

void mainMenu()
{
    cout << "Address Book Application" << endl << "------------------------" << endl
         << "1. Add New Contact"<<endl << "2. Search for Contact" << endl
         <<"3. List All Contacts (Sorted by ID)"<<endl << "4. Display Current Tree Structure"<<endl
         << "------------------------"<<endl <<"Enter operation (1-4): "<<endl;

}

int main()
{
    AvlTree tree;
    string fileName = "testcases.txt";
    ifstream file(fileName);
    while (true)
    {
        int id;
        cout << "Press any from {0,5,6,7,8,9} number to exist..."<<endl;
        mainMenu();
        int choice = validNumber();
        if(choice == 1)
        {
            cout << "load contact from file";
            for(int i = 0;i<3;i++)
            {
                Sleep(1500);
                cout << ".";
            }
            cout << endl;
            string fName,lName,phone,email;
            if(!file.is_open())
            {
                cout << "cannot open file...! " << fileName << endl;
                return 0;
            }
            string line;
            if(getline(file,line))
            {
                stringstream ss(line);
                ss >> id >> fName >> lName >> phone >> email;
            }
            fName.append(" ");
            string fullName = fName + lName;
            Value value(fullName,phone,email);
            if(tree.insert(id,value))
            {
                cout << "Successfully added contact : < ) from file \"" << fileName << "\"" << endl;
            }
            else
                cout << "Cannot add the current contact from file "<< fileName << " \" ID is duplicate\"" << endl;
        }
        else if(choice == 2)
        {
            cout << "Enter ID to search:"<<endl;
            cin >> id;
            AvlNode* node = tree.search(id);
            if(node != nullptr)
            {
                cout << "Contact found:"<<endl;
                node->display();
            }
            else
                cout<<"Contact not found."<<endl;
        }
        else if(choice == 3)
        {
            if(tree.getRoot() != nullptr)
            {
                cout << "Contacts in Address Book (sorted by ID):"<<endl;
                tree.inOrder();
            }
            else
                cout << "Address Book is empty."<<endl;
        }
        else if(choice == 4)
        {
            tree.treeStructure();
        }
        else
            break;
    }
    file.close();
    return 0;
}