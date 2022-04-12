/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** C4011
*/

#ifndef C4011_HPP_
#define C4011_HPP_

#include <string>
#include "IComponent.hpp"

namespace nts {
    class C4011 : public IComponent {
        public:
            C4011();
            ~C4011();

            void simulate(std::size_t);
            nts::Tristate compute(size_t);
            void setLink(size_t, nts::IComponent &, size_t);
            void dump(void) const;
        protected:
        private:
    };
}

#endif /* !C4011_HPP_ */
