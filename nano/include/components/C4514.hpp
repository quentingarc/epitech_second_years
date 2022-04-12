/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** C4514
*/

#ifndef C4514_HPP_
#define C4514_HPP_

#include <string>
#include "IComponent.hpp"

namespace nts {
    class C4514 : public IComponent {
        public:
            C4514();
            ~C4514();
    
            void simulate(std::size_t);
            nts::Tristate compute(size_t);
            void setLink(size_t, nts::IComponent &, size_t);
            void dump(void) const;
        protected:
        private:
    };
}

#endif /* !C4514_HPP_ */
