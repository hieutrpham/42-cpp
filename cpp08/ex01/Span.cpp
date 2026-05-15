#include "Span.hpp"

Span::Span(unsigned int n) : m_maxSize(n) {}

Span::Span(const Span& other) : m_maxSize(other.m_maxSize), m_numbers(other.m_numbers) {}

Span& Span::operator=(const Span& other)
{
	if (this != &other) {
		m_maxSize = other.m_maxSize;
		m_numbers = other.m_numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (m_numbers.size() >= m_maxSize)
		throw std::overflow_error("Span is full: cannot add more numbers");
	m_numbers.push_back(number);
}

int Span::shortestSpan() const
{
	if (m_numbers.size() < 2)
		throw std::logic_error("Need at least 2 numbers to find a span");
	std::vector<int> sorted = m_numbers;
	std::sort(sorted.begin(), sorted.end());

	int shortest = INT_MAX;
	for (size_t i = 1; i < sorted.size(); ++i) {
		int diff = sorted[i] - sorted[i - 1];
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

int Span::longestSpan() const
{
	if (m_numbers.size() < 2)
		throw std::logic_error("Need at least 2 numbers to find a span");

	int maxVal = *std::max_element(m_numbers.begin(), m_numbers.end());
	int minVal = *std::min_element(m_numbers.begin(), m_numbers.end());

	return maxVal - minVal;
}
