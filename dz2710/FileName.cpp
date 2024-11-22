#include<iostream>
#include<string>

class Text
{
public:
    Text() : content("") {}
    Text(const char* inputText) : content(inputText) {}
    Text(const Text& other) : content(other.content) {}

    char operator[](int index)
    {
        if (index >= 0 && index < length()) return content[index];
        throw std::out_of_range("Index out of range!");
    }

    int operator() (char ch) const
    {
        for (size_t i = 0; i < length(); i++)
        {
            if (content[i] == ch)
            {
                return i;
            }
        }
        return -1;
    }

    operator int() const
    {
        return length();
    }

    void Display() const
    {
        if (length() > 0)
        {
            std::cout << content << std::endl;
        }
        else
        {
            std::cout << "Text is empty" << std::endl;
        }
    }

    int length() const {
        return content.size();
    }

private:
    std::string content;
};

int main()
{
    Text text1("Hello world");
    Text text2("Hello world");

    text1.Display();
    text2.Display();

    return 0;
}
