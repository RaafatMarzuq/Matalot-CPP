#pragma once
#include <functional>

using namespace std;

namespace itertools
{
    auto _sum = [](auto x, auto y) { return x + y; }; // defult function and it's lambda

    template <typename C, typename F = decltype(_sum)>
    class accumulate
    {
    private:
        C container;
        F function;

    public:
        accumulate(C c, F f = _sum)
            : container(c), function(f) {}

        class iterator
        {
        private:
            F function;
            typename C::iterator it;
            typename C::iterator last;
            typename decay<decltype(*(container.begin()))>::type aggr;//aggregated value
            

        public:
            iterator(typename C::iterator first, typename C::iterator l, F fun)
                : it(first), last(l), function(fun)
            {
                if (it != last)
                    aggr = *it;
            }

            // ++i;
            iterator &operator++()
            {
                ++it;
                if (it != last)
                    aggr = function(aggr, *it);
                return *this;
            }
            // i++;
            iterator operator++(int)
            {
                iterator i = *this;
                ++(*i);
                return i;
            }
            bool operator==(const iterator &other) const
            {
                return (it == other.it);
            }
            bool operator!=(const iterator &other) const
            {
                return (it != other.it);
            }
            auto operator*() const
            {
                return aggr;
            }

            iterator &operator=(const iterator &other)
            {
                if (*this != other)
                {
                    this->it = other.it;
                    this->last = other.last;
                    this->aggr = other.aggr;
                    this->function = other.function;
                }
                return *this;
            }
        };
        iterator begin()
        {
            return iterator(container.begin(), container.end(), function);
        }

        iterator end()
        {
            return iterator(container.end(), container.end(), function);
        }
    };
} // namespace itertools