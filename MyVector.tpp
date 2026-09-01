// ECE 3574 Exercise: Templates - starter code

#include <iostream>

template <class T>
MyVector<T>::MyVector() : m_data(nullptr), m_capacity(0), m_size(0)
{
    // do nothing
}

template <class T>
MyVector<T>::MyVector(const MyVector<T> &obj)
{
    m_capacity = obj.m_capacity;
    m_size = obj.m_size;

    if (m_capacity == 0)
    {
        m_data = nullptr;
    }
    else
    {
        m_data = new T[m_capacity];
        for (int i = 0; i < m_size; i++)
        {
            m_data[i] = obj.m_data[i];
        }
    }
}

template <class T>
MyVector<T>::~MyVector()
{
    delete[] m_data;
}

template <class T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& obj)
{
    if (this == &obj)
    {
        return *this;
    }

    delete[] m_data;

    m_capacity = obj.m_capacity;
    m_size = obj.m_size;

    if (m_capacity == 0)
    {
        m_data = nullptr;
    }
    else
    {
        m_data = new T[m_capacity];
        for (int i = 0; i < m_size; i++)
        {
            m_data[i] = obj.m_data[i];
        }
    }

    return *this;
}

template <class T>
int MyVector<T>::size()
{
    return m_size;
}

template <class T>
bool MyVector<T>::empty()
{
    return m_size == 0;
}

template <class T>
void MyVector<T>::push_back(const T& value)
{
    if (m_size == m_capacity)
    {
        int new_capacity;

        if (m_capacity == 0)
        {
            new_capacity = 1;
        }
        else
        {
            new_capacity = m_capacity * 2;
        }

        T* new_data = new T[new_capacity];

        for (int i = 0; i < m_size; i++)
        {
            new_data[i] = m_data[i];
        }

        delete[] m_data;

        m_data = new_data;
        m_capacity = new_capacity;
    }

    m_data[m_size] = value;
    m_size++;
}

template <class T>
T& MyVector<T>::at(int i)
{
    if (i < 0 || i >= m_size)
    {
        std::cerr << "Error";
        return m_data[0];
    }

    return m_data[i];
}
