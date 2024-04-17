#include <stdio.h>
#include <stdlib.h>

#include <iostream>
//================================================
// Ранее для хранения большого числа однотипных
// элементов мы использовали только массив.
// Плюс массива: очень быстрый доступ по номеру элемента.
//  (поскольку начало массива известно, а дальше все
//   элементы расположены последовательно
//   То есть (адрес элемента i) = start_address + i * sizeof(data_type)
//  )
// Минус массива: мы хотим удалить второй элемент в массиве:
//                        v
// int massive[] = {3.8, 4.2, 8.2, .....};
// Тогда потребуется все элементы массива после второго сдвинуть
// на единицу влево.
//------------------------------------------------
// Для таких случаев (когда часто нужно добавлять/удалять элементы)
// пригождается структура данных List (список)

// Определяется отдельный узел списка (аналогично одному элементу массива)
struct Node
{
    float value;       // Значение, хранящееся в данном узле списка
    struct Node* next; // Указатель на следующий узел списка
};

std::ostream& operator << (std::ostream& os, const Node* node) {
    do {
        os << node->value << " ";
        node = node->next;
    } while (node->next != 0);
    os << node->value << "\n";
    return os;
}

void print(Node* node) {
    Node *n_ptr = node;
    int i = 0;
    while (n_ptr != 0) // продолжать цикл до конца списка
    {
        printf("List item %d = %f\n", i++, n_ptr->value);
        // Перейти от текущего узла списка к следующему.
        n_ptr = n_ptr->next;
    }
}

float get(Node* head, int n) { 
    // Хотим получить n-ый элемент списка (нумерация с нуля).
    Node * n_ptr = head; // Ставим Node* n_ptr как указатель на голову списка
    while(n--)
    {
        // Перейти от текущего узла списка к следующему.
        n_ptr = n_ptr->next;
    }
    return n_ptr->value;
}

void delete_node(Node* head, int n) {
    n--;
    Node* n_ptr = head; // Ставим Node* n_ptr как указатель на голову списка
    while (n--)
    {
        // Перейти от текущего узла списка к следующему.
        n_ptr = n_ptr->next;
    }
     
    Node* ndel = n_ptr->next;
    n_ptr->next = n_ptr->next->next;
    free(ndel);
}

int main()
{
    // Заполняем тестовый список из трёх узлов
    // n1 -> n2 -> n3
    Node n1;
    n1.value = 1;
    Node n2;
    n2.value = 2;
    Node n3;
    n3.value = 3;
    // Ставим указатели next, чтобы связать узлы списка между собой
    n1.next = &n2;
    n2.next = &n3;
    n3.next = 0;  // У последнего элемента next должен быть равен нулю,
                  // иначе мы никак не узнаем, где конец списка
    // Выводим значения списка
    int i = 0;
    Node* n_ptr = &n1;
    while (n_ptr != 0) // цикл до конца списка
    {
        printf("List item %d = %f\n", i++, n_ptr->value);
        // Перейти от текущего узла списка к следующему.
        n_ptr = n_ptr->next;
    }
    // Создадим список и заполним его
    float array[] = { 1., 2., 3., 4., 5. };
    Node* node_ptr;
    Node* prev = 0; // предыдущий узел списка
    Node* head = 0; // голова (первый узел) списка
    for (i = 0; i < 5; i++)
    {
        // Создаём пять узлов списка для пяти элементов в массиве
        node_ptr = (Node*)malloc(sizeof(Node));
        node_ptr->value = array[i];
        // Важно, чтобы next сначала указывал на 0,
        // иначе там может по умолчанию оказаться мусор,
        // в результате мы перейдём на неправильный адрес в памяти.
        node_ptr->next = 0;
        // Если это не первый узел, ставим на него указатель next
        // от предыдущего узла
        if (prev != 0)
        {
            prev->next = node_ptr;
        }
        // Если это самый первый элемент, то задаём голову списка
        if (head == 0)
        {
            // Записываем первый узел списка
            head = node_ptr;
        }
        prev = node_ptr;
    }
    std::cout << "print1 = " << head;
    std::cout << "print2 \n"; print(head);
    printf("=======\n\n\n");

    //======
    // Получение n-го элемента списка.
    int n = 4;
    printf("Element #%d = %f\n", n, get(head,n));
    printf("=======\n\n\n");

    //======
    delete_node(head, n);
    std::cout << "print1 = " << head;
}
