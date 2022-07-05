#include"Food.h"

Food::Food()
{
    proteins = rand() % 100;
    carbohydrates = rand() % 100;
    fats = rand() % 100;
}

Food::Food(int proteins_value, int carbohydrates_value, int fats_value)
{
    proteins = proteins_value;
    carbohydrates = carbohydrates_value;
    fats = fats_value;
}

bool operator==(Food const& lvalue, Food const& rvalue)
{
    if (lvalue.proteins == rvalue.proteins && lvalue.carbohydrates == rvalue.carbohydrates && lvalue.fats == rvalue.fats)
    {
        return true;
    }
    
    return false;
}

bool operator<(Food const& lvalue, Food const& rvalue)
{
    if (lvalue.proteins != rvalue.proteins)
    {
        return (lvalue.proteins < rvalue.proteins);
    }
    
    if (lvalue.carbohydrates != rvalue.carbohydrates)
    {
        return (lvalue.carbohydrates < rvalue.carbohydrates);
    }

        return (lvalue.fats < rvalue.fats);
}