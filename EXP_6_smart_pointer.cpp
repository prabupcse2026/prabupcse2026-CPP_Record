#include <iostream>
#include <memory>
#include <vector>
using namespace std;
// Resource class
class Resource
{
public:
    Resource()
    {
        cout << "Resource acquired" << endl;
    }
    ~Resource()
    {
        cout << "Resource released" << endl;
    }
    void use()
    {
        cout << "Resource is being used" << endl;
    }
};
// Manual Smart Pointer using RAII
class MySmartPointer
{
private:
    Resource* ptr;
public:
    MySmartPointer(Resource* p)
    {
        ptr = p;
    }
    ~MySmartPointer()
    {
        delete ptr;
        cout << "Manual smart pointer destroyed" << endl;
    }
    Resource* operator->()
    {
        return ptr;
    }
    // Disable copying to avoid double deletion
    MySmartPointer(const MySmartPointer&) = delete;
    MySmartPointer& operator=(const MySmartPointer&) = delete;
};

int main()
{
    int owners, uses;
    cout << "Enter number of shared pointer owners: ";
    cin >> owners;
    cout << "Enter number of times to use the resource: ";
    cin >> uses;

    cout << "----- Manual RAII Smart Pointer -----" << endl;

    {
        MySmartPointer smartPtr(new Resource());
        for (int i = 0; i < uses; i++)
            smartPtr->use();
    }
    cout << "\n----- unique_ptr -----" << endl;
    {
        unique_ptr<Resource> uniquePtr =
            make_unique<Resource>();
        for (int i = 0; i < uses; i++)
            uniquePtr->use();
    }
    cout << "\n----- shared_ptr -----" << endl;
    {
        shared_ptr<Resource> sharedPtr1 =
            make_shared<Resource>();
        vector<shared_ptr<Resource>> others;
        for (int i = 1; i < owners; i++)
            others.push_back(sharedPtr1);
        for (int i = 0; i < uses; i++)
            sharedPtr1->use();
        cout << "Shared Pointer Count: "
            << sharedPtr1.use_count() << endl;
    }
    cout << "\nProgram completed successfully." << endl;
    return 0;
}