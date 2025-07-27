#include <iostream>

using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

int main() {

    // Можем завести переменную с этим типом
    TaskStatus task_status = TaskStatus::NEW;

    // Можем сравнивать значение в переменной
    if (task_status == TaskStatus::NEW) {
        // cout << task_status << '\'; // не получиться
        cout << static_cast<int>(task_status); // элементам enum соответствует номер их позиции
    }

    // Можем использовать в switch..case
    switch (task_status) {
        case TaskStatus::NEW: {
            // ...
            break;
        }
        // ...
        default:
    }

    // Можем получить следующее по списку поле enum
    auto next = static_cast<TaskStatus>(static_cast<int>(task_status));

}