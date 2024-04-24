при компиляции данного кода появляется следующее сообщение:
 test2.c:65:21: warning: cast from pointer to integer of different size [-Wpointer-to-int-cast]
   65 |     int args[2] = { (int)students, count }; // Arguments for wrapper functions

Верно, компилятор генерирует предупреждение из-за приведения указателя к целочисленному типу. 
Вместо этого мы можем передать указатель на структуру student
и по сути это будет код из задания task1
