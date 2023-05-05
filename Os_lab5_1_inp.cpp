#include <iostream>
#include <string>

int main()
{
    int x = 69;
  
    std::cout << "x is located at " << &x << std::endl;

    std::cout << "process id is " << getpid() << std::endl;

    while (true)
    {

        std::string input;
        std::getline(std::cin, input);

        int new_x = std::stoi(input);
        x = new_x;
    }

    return 0;
}
