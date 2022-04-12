/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** C4081
*/

#ifndef C4081_HPP_
#define C4081_HPP_

#include <string>
#include "IComponent.hpp"

namespace nts {
    class C4081 : public IComponent {
        public:
            C4081();
            ~C4081();
    
            void simulate(std::size_t);
            nts::Tristate compute(size_t);
            void setLink(size_t, nts::IComponent &, size_t);
            void dump(void) const;
        protected:
        private:
    };
}

#endif /* !C4081_HPP_ */
