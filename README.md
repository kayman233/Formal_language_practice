## Практикум по формальным языкам №1 - Кудрявцев Иван 822 группа


Вариант 6:
Даны а, буква x и натуральное число k. Вывести, есть ли в языке слова, содержащие ровно k букв x.

### TO RUN:

mkdir build

cd build

cmake ..

make

./analyse_reg_exp

cd ..

rm -r build


### TO RUN TESTS:
mkdir build

cd build

cmake ..

make

cd project_tests

./gtest_run

cd ..

cd ..

rm -r build


Написаны тесты(24 штуки), но code coverage измерить не удалось.
