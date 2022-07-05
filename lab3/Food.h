#pragma once
#include<iostream>

//Структура Food(Їжа) з наступними полями:
// proteins(білки)
// carbohydrates(вуглеводи)
// fats(жири)

struct Food
{
private:
    int proteins;
    int carbohydrates;
    int fats;

public:
    Food();

    Food(int proteins_, int carbohydrates_, int fats_);

    friend bool operator<(Food const& lvalue, Food const& rvalue);

    friend bool operator==(Food const& lvalue, Food const& rvalue);
};

