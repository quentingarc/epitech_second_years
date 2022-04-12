/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** C4512
*/

#ifndef C4512_HPP_
#define C4512_HPP_

#include <string>
#include "IComponent.hpp"

namespace nts {
    class C4512 : public IComponent {
        public:
            C4512();
            ~C4512();
    
            void simulate(std::size_t);
            nts::Tristate compute(size_t);
            void setLink(size_t, nts::IComponent &, size_t);
            void dump(void) const;
        protected:
        private:
    };
}

#endif /* !C4512_HPP_ */
