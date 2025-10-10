## CuLo — Библиотека для отображения индикатора загрузки в терминале

- Простой и понятный API
- Поддержка цветов (ANSI)
- Управление анимацией через start() и stop()
- Поддержка любых кастомных фреймов

## Использование
пример со спинером
```cpp
#include "CuLo.hpp"
#include <iostream>
#include <thread>
#include <chrono>

int main() {

    Culo::start();

    std::thread spinner_thread([]() {
        Culo::lb({"-", "/", "\\"}, CULO_RED); 
    });

    // Имитация загрузки
    for (int i = 0; i < 100; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    Culo::stop();

    spinner_thread.join();

    std::cout << "Готово!" << std::endl;
    return 0;
}

```
Пример с прогресс-баром
```cpp
#include "CuLo.hpp"
#include <iostream>
#include <thread>
#include <chrono>

int main() {

    Culo::start();

    std::thread pb_thread([]() {
        Culo::lb({"-", "--", "---", "----", "-----"}, CULO_YELLOW); 
    });

    // Имитация загрузки
    for (int i = 0; i < 100; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    Culo::stop();

    pb_thread.join();

    std::cout << "Готово!" << std::endl;
    return 0;
}
```

## Доступные цвета:

- CULO_WHITE
- CULO_RED
- CULO_GREEN
- CULO_YELLOW
- CULO_BLUE
- CULO_MAGENTA
- CULO_CYAN
- CULO_RESET

## Cвои цвета
Так как в функцию передаётся std::string, вы можете использовать свои ANSI-коды:

```cpp
Culo::lb({"-", "/", "\\"}, "\033[95m");  // ярко-фиолетовый
```

