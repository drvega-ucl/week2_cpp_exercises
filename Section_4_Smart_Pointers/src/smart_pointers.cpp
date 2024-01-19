#include <memory>
#include <iostream>
#include <vector>

/**
 * A simple class which just reports when it is created (constructor) and when it is destroyed (destructor).
*/
class Reporter
{
    public: 
    Reporter(std::string id_string) : ID(id_string)
    {
        std::cout << "Creating Reporter Object with ID: " << ID << std::endl;
    }

    ~Reporter()
    {
        std::cout << "Destroying Reporter Object with ID: " << ID << std::endl;
    }

    private:
    std::string ID;
};


int main()
{

    //This is a raw pointer, it only points in memory where the data is saved
    Reporter *Report = new Reporter("abc");
    //Without the delete function there will be a memory leak
    delete Report;

    //Making a smart pointer makes it so that it is created and destroyed preventing a memory leak
    std::unique_ptr<Reporter> Report2 = std::make_unique<Reporter>("efg");

    return 0;
}
