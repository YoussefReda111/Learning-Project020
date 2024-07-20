#pragma once
#include <iomanip>
#include <iostream>

using namespace std;

template <class class_type> class cls_doubly_linked_list
{
protected:
    int _size;

public:
    class node
    {
    public:
        class_type data;
        node* next, * prev;
    };

    node* head;

    cls_doubly_linked_list()
    {
        _size = 0;
        head = NULL;
    }

    void insert_at_beginning(class_type inserted_node_data)
    {
        node* inserted_node = new node();
        inserted_node->data = inserted_node_data;
        inserted_node->next = head;
        inserted_node->prev = NULL;
        if (head != NULL) head->prev = inserted_node;
        head = inserted_node;
        _size++;
    }

    node* find(class_type data)
    {
        node* current = head;
        while (current != NULL)
        {
            if (current->data == data) return current;
            current = current->next;
        }
        return NULL;
    }

    void insert_after(node* prev_node, class_type inserted_node_data)
    {
        if (prev_node == NULL) return;
        node* inserted_node = new node();
        inserted_node->data = inserted_node_data;
        inserted_node->next = prev_node->next;
        inserted_node->prev = prev_node;
        if (prev_node->next != NULL) prev_node->next->prev = inserted_node;
        prev_node->next = inserted_node;
        _size++;
    }

    void insert_after(int prev_index, class_type inserted_node_data)
    {
        insert_after(get_node(prev_index), inserted_node_data);
    }

    void insert_at_end(class_type inserted_node_data)
    {
        node* inserted_node = new node();
        inserted_node->data = inserted_node_data;
        inserted_node->next = NULL;
        if (head == NULL)
        {
            head = inserted_node;
            _size++;
            return;
        }
        node* last_node = head;
        while (last_node->next != NULL) last_node = last_node->next;
        last_node->next = inserted_node;
        inserted_node->prev = last_node;
        _size++;
    }

    void delete_node(node*& deleted_node_data)
    {
        node* prev_node = head, * current = head;
        while (current != NULL && current != deleted_node_data)
        {
            prev_node = current;
            current = current->next;
        }
        if (current == NULL) return;
        if (current == head)
        {
            head = current->next;
            if (head != NULL) head->prev = NULL;
            delete current;
            _size--;
            return;
        }
        prev_node->next = current->next;
        if (current->next != NULL) current->next->prev = prev_node;
        delete current;
        _size--;
    }

    void delete_first_node()
    {
        if (head == NULL) return;
        node* current = head;
        head = current->next;
        if (head != NULL) head->prev = NULL;
        delete current;
        _size--;
    }

    void delete_last_node()
    {
        if (head == NULL) return;
        node* current = head;
        while (current->next != NULL) current = current->next;
        if (current->prev != NULL) current->prev->next = NULL;
        else head = NULL;
        delete current;
        _size--;
    }

    void print_list()
    {
        node* current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }

    int size()
    {
        return _size;
    }

    bool is_empty()
    {
        return (_size == 0);
    }

    void clear()
    {
        while (_size > 0) this->delete_last_node();
    }

    void reverse()
    {
        node* current = head;
        node* temp = nullptr;

        while (current != nullptr)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr) head = temp->prev;
    }

    node* get_node(int index)
    {
        if (index < _size && index >= 0)
        {
            node* current = head;
            for (int i = 1; i <= index; i++) current = current->next;
            return current;
        }
        return NULL;
    }

    class_type at(int index)
    {
        return get_node(index)->data;
    }

    void update(int index, class_type update_data)
    {
        if (index > _size || index < 0) return;
        node* current = head;
        for (int i = 1; i <= index; i++) current = current->next;
        current->data = update_data;
    }
};