#include "Span.hpp"

Span::Span() : mVec(0), mMaxSize(0) {}

Span::Span(unsigned int N) : mVec(0), mMaxSize(N) { mVec.reserve(N); }

Span::Span(const Span &span)
    : mVec(span.getVector()), mMaxSize(span.getSize()) {}

Span::~Span() {}

Span &Span::operator=(const Span &span) {
  if (this == &span)
    return (*this);
  mVec = span.getVector();
  mMaxSize = span.getSize();
  return (*this);
}

std::vector<int> Span::getVector() const { return (mVec); }

unsigned int Span::getSize() const { return (mMaxSize); }

void Span::addNumber(const int element) {
  if (mVec.size() < mMaxSize)
    mVec.push_back(element);
  else
    throw Span::FullContainerException();
}

const char *Span::FullContainerException::what() const throw() {
  return ("Cannot add element to container");
}

const char *Span::TooFewElementException::what() const throw() {
  return ("Too few element");
}

unsigned int Span::shortestSpan() const {
  std::vector<int> copy(mVec);
  unsigned int gap = UINT32_MAX;

  if (copy.size() < 2)
    throw Span::TooFewElementException();
  std::sort(copy.begin(), copy.end());
  for (std::vector<int>::iterator iter = copy.begin(); iter != copy.end() - 1;
       ++iter)
    gap = std::min(gap, static_cast<unsigned int>(*(iter + 1) - *iter));
  return (gap);
}

unsigned int Span::longestSpan() const {
  std::vector<int> copy(mVec);

  if (copy.size() < 2)
    throw Span::TooFewElementException();
  std::sort(copy.begin(), copy.end());
  return (static_cast<unsigned int>(copy.back() - copy.front()));
}

void Span::addRandomNumbers(unsigned int amount) {
  srand(time(NULL));
  try {
    for (unsigned int idx = 0; idx != amount; ++idx)
      this->addNumber(rand());
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void Span::addNumberInRange(const unsigned int amount, const int value) {
  if (mVec.size() + amount > mMaxSize)
    throw Span::FullContainerException();
  mVec.insert(mVec.end(), amount, value);
}
