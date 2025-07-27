#include <map>

int main() {
    std::map<string, int> candy_count;

    // если в карте не было ключа, то при обращении оператором [], он будет создан, т.е. Мисси, Крисси, Кисси в карте не было, для них будут созданы пары и назначено значение
    // в константном методе, если наша карта является полем класса, то мы не можем использовать [], так как он предполагает изменение, можно использовать .at(key)
    // в map по умолчанию пары сортированы по ключу, а не в порядке добавления

    // Можно назначить значение
    // candy_count[key] = value;
    candy_count["Missy"s] = 5;
    candy_count["Kissy"s] = 3;
    candy_count["Krissy"s] = 5;

    // Можно изменить значение по ключу
    ++candy_count["Kissy"s]; // тоже самое как
    candy_count["Kissy"s] += 1; // тоже самое как
    candy_count["Kissy"s] = candy_count["Kissy"s] + 1;

    // Можно проверить есть ли ключ в карте
    if (candy_count.find("Missy"s) != candy_count.end()) {
        // выведет значение для Missy
        cout << candy_count.at("Missy"s) << '\n';
    }

    // Можно проверить есть ли ключ в карте так
    auto it = candy_count.find("Missy"s);
    if (it != candy_count.end()) {
        // выведет значение для Missy
        cout << it->second << '\n';
    }

    // Можно итерировать по карте
    // Если не будем менять значения карты то const&
    for (auto const& [key, value] : candy_count) {
        cout << "Name: "s << key 
             << "; count: " << value << '\n';
    }
    // Вывод ключи отсортированы, сначала будет Kissy, лексикографически меньше чем Krissy потомучто i раньше r, и потом Missy, потому чо K раньше чем M
    // Name: Kissy; count: 3
    // Name: Krissy; count: 5
    // Name: Missy; count: 5

    // Карта хранит пары std::pair<key, value> поэтому если написать так, не раскрывая на [key, value], то элемент entity будет парой
    for (auto const& entity : candy_count) {
        cout << entity.first << " "s << entity.second << '\n';
    }

    // Чтобы удалить элемент из карты
    candy_count["Sissy"s] = 0; // добавим для примера
    candy_count.erase("Sissy"); // а так можно удалить по ключу
    
}