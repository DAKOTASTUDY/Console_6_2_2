#include <iostream>
class smartArray
{
private:
    int asize;
    int* array;
    int index = 0;
public:

    smartArray(int size)
    {
        asize = 2 * size;
        array = new int[asize];

    };
    ~smartArray()
    {
        delete[] array;

    }

    void elementValue(int value)
    {


       // std::cout << " / Element index" << index << " / " << " asize" << asize << std::endl;
        if ((index >= asize) || (index < 0))

        {
            // std::cout << "throw" << std::endl;
            throw std::runtime_error("\n Error. Index is out of range.");
        }
        else {
           // std::cout << " / " << index << " / " << std::endl;
            array[index] = value;
        }
        index++;
    }
    int getElement(int position)
    {
        if ((position < 0) || (position >= index))

        {

            throw std::exception("\n Error. No valuable element.");
        }
       // std::cout << " /  index " << index << " / " << std::endl;
     //   std::cout << " / position" << position << " / " << std::endl;
        return array[position];
    }
    smartArray& operator=(const smartArray& other) {
        if (this != &other) {
            asize = other.asize ;//
            delete[] array;
            array = new int[ asize]; //
            index = other.index;
            for (int i = 0; i <  asize; i++) //
                array[i] = other.array[i];
        }
        return *this;
    }
    smartArray(const smartArray& rhs) 
    {
        if (this != &rhs) {
            asize = rhs.asize ;  //
            index = rhs.index;
            array = new int[asize]; //
            for (int i = 0; i < asize; i++) //
                array[i] = rhs.array[i];
        }
    }
};

int main()
{
    smartArray a(3);
    smartArray b(10);
    for (int i = 0; i < 10; i++)
    {
        try {
            a.elementValue(i);
          
        }

        catch (const std::exception& e) {
            std::cout << e.what();
        }

    }
    for (int i = 0; i < 10; i++)
    {
        try {
            
            b.elementValue(i + i * 100);
        }

        catch (const std::exception& e) {
            std::cout << e.what();
        }

    }
    for (int i = 0; i < 10; i++)
    {
        try { std::cout << " \n Array a element (index): " << "(" << i << ") " << a.getElement(i) << std::endl; }

        catch (const std::exception& e) { std::cout << e.what(); }
    };
        

    for (int i = 0; i < 10; i++)
    {
        try { std::cout << "\n Array b element (index): " << "(" << i << ") " << b.getElement(i) << std::endl; }

        catch (const std::exception& e) { std::cout << e.what(); }
    };

            
    
    /*try
    {
        a.elementValue(20);
        std::cout << a.getElement(20) << std::endl;
    }
    catch (const std::exception& e) { std::cout << e.what(); };*/
    a = b;
    for (int i = 0; i < 10; i++)
    {
        try
        {
            std::cout << "\n Last array  element  (index): " << "(" << i << ") " << a.getElement(i) << std::endl;

        }
        catch (const std::exception& e)
        {
            std::cout << e.what();
        }

    }

    return 0;
}