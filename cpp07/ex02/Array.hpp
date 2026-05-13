#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>

template <typename T>
class Array
{
	private:
		T*				m_elements;
		unsigned int	m_size;

	public:
		Array() : m_elements(nullptr), m_size(0) {}

		Array(unsigned int n) : m_size(n) {
			m_elements = new T[m_size]();
		}

		Array(const Array& other) : m_size(other.m_size)
		{
			m_elements = new T[m_size]();
			for (unsigned int i = 0; i < m_size; i++) {
				m_elements[i] = other.m_elements[i];
			}
		}

		Array& operator=(const Array& other) {
			if (this != &other) {
				delete[] m_elements;
				m_size = other.m_size;
				m_elements = new T[m_size]();
				for (unsigned int i = 0; i < m_size; i++) {
					m_elements[i] = other.m_elements[i];
				}
			}
			return *this;
		}

		~Array() {
			delete[] m_elements;
		}

	T& operator[](unsigned int index) {
		if (index >= m_size)
			throw std::out_of_range("out of range");
		return m_elements[index];
	}

	const T& operator[](unsigned int index) const {
		if (index >= m_size)
			throw std::out_of_range("out of range");
		return m_elements[index];
	}

	unsigned int size() const {
		return m_size;
	}
};
