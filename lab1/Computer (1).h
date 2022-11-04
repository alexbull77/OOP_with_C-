#ifndef COMPUTER_H_
#define COMPUTER_H_

class Computer
{
private:

    char* manufacturer = { nullptr };
    char* processor = { nullptr };
    int clock_speed;

public:

    void init(const char* man, const char* proc, const int cs);
    void clear();
    void print() const;
    bool is_greater(const Computer& other) const;
    Computer& set(const char* new_manufacturer, const char* new_processor, const int new_clock_speed);
};

#endif