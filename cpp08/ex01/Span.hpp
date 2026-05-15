#pragma once

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <climits>

class Span
{
	private:
		unsigned int		m_maxSize;
		std::vector<int>	m_numbers;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		void addNumber(int number);

		template <typename T>
		void addNumbers(T container)
		{
			if (m_numbers.size() + container.size() > m_maxSize)
				throw std::overflow_error("Unable to add");
			m_numbers.insert(m_numbers.end(), container.begin(), container.end());
		}
		int shortestSpan() const;
		int longestSpan() const;
};
